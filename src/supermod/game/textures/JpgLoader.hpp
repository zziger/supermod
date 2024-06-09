#pragma once
#include <supermod/pch.hpp>

#include <d3d8/d3d8helpers.h>
#include <fstream>
#include <jpeglib.h>
#include <supermod/game/textures/TextureLoader.hpp>
#include <supermod/sdk/DirectX.hpp>

class JpgLoader
{
    struct mem_src_mgr
    {
        struct jpeg_source_mgr pub;
        const JOCTET* mem;
        size_t len;
    };

    static boolean fill_mem_input_buffer(j_decompress_ptr cinfo)
    {
        spdlog::error("Failed to call fill_mem_input_buffer from JPGA loader");
        return TRUE;
    }

    static void skip_input_data(j_decompress_ptr cinfo, long num_bytes)
    {
        mem_src_mgr* src = (mem_src_mgr*)cinfo->src;
        if (num_bytes > 0)
        {
            src->pub.next_input_byte += num_bytes;
            src->pub.bytes_in_buffer -= num_bytes;
        }
    }

    static void nullsub(j_decompress_ptr cinfo)
    {
        // No initialization or termination required for memory source.
    }

public:
    // buffer should be preallocated before passing to this function
    static void AddJpgaData(vector2ui size, std::filesystem::path path, std::vector<byte>& pixelData,
                            const std::vector<byte>& buf, uint32_t bufSize, uint32_t imageSize, bool warn)
    {
        if (bufSize - imageSize <= 0)
        {
            spdlog::debug("Skipped JPGA alpha load for {}: no alpha data found", path.string());
            return;
        }

        auto expectedSize = size.x * size.y;
        if (bufSize - imageSize < expectedSize)
        {
            spdlog::debug("Skipped JPGA alpha load for {}: not enough alpha data (expected {}, got {})", path.string(),
                          expectedSize, bufSize - imageSize);
            return;
        }

        for (uint32_t y = 0; y < size.y; y++)
        {
            for (uint32_t x = 0; x < size.x; x++)
            {
                pixelData[y * size.x * 4 + x * 4 + 3] = buf[imageSize + y * size.x + x];
            }
        }
    }

    static std::optional<std::vector<byte>> ReadJpgBuf(const byte* buf, size_t bufSize, vector2ui& size,
                                                       size_t& imageSize)
    {
        try
        {
            struct jpeg_decompress_struct cinfo;
            struct jpeg_error_mgr jerr;

            cinfo.err = jpeg_std_error(&jerr);
            jerr.error_exit = [](j_common_ptr cinfo) {
                char buffer[JMSG_LENGTH_MAX];
                (*cinfo->err->format_message)(cinfo, buffer);
                throw std::runtime_error(buffer);
            };

            jpeg_create_decompress(&cinfo);

            // this is used instead of jpeg_mem_src to retrieve read bytes count (for proper alpha offset)
            mem_src_mgr* src;

            if (cinfo.src == nullptr)
            {
                cinfo.src = static_cast<jpeg_source_mgr*>((*cinfo.mem->alloc_small)(
                    reinterpret_cast<j_common_ptr>(&cinfo), JPOOL_PERMANENT, sizeof(mem_src_mgr)));
            }

            src = reinterpret_cast<mem_src_mgr*>(cinfo.src);
            src->pub.init_source = nullsub;
            src->pub.fill_input_buffer = fill_mem_input_buffer;
            src->pub.skip_input_data = skip_input_data;
            src->pub.resync_to_restart = jpeg_resync_to_restart; // Use default method
            src->pub.term_source = nullsub;
            src->mem = buf;
            src->len = bufSize;
            src->pub.bytes_in_buffer = bufSize;
            src->pub.next_input_byte = src->mem;

            jpeg_read_header(&cinfo, TRUE);
            jpeg_start_decompress(&cinfo);

            size = {cinfo.output_width, cinfo.output_height};

            uint32_t row_stride = cinfo.output_width * cinfo.output_components;
            std::vector<uint8_t> buffer(row_stride);

            std::vector<byte> rgba_buffer;
            rgba_buffer.resize(cinfo.output_width * cinfo.output_height * 4, 255);
            JSAMPROW row_pointer[1];  // pointer to a single row
            size_t rgba_position = 0; // position in the rgba_buffer

            while (cinfo.output_scanline < cinfo.output_height)
            {
                row_pointer[0] = &buffer[0];
                jpeg_read_scanlines(&cinfo, row_pointer, 1);

                for (unsigned int i = 0; i < cinfo.output_width; i++)
                {
                    rgba_buffer[rgba_position++] = buffer[i * cinfo.output_components];
                    rgba_buffer[rgba_position++] = buffer[i * cinfo.output_components + 1];
                    rgba_buffer[rgba_position++] = buffer[i * cinfo.output_components + 2];
                    rgba_buffer[rgba_position++] = 255;
                }
            }

            jpeg_finish_decompress(&cinfo);

            imageSize = src->len - src->pub.bytes_in_buffer;
            jpeg_destroy_decompress(&cinfo);

            return rgba_buffer;
        }
        catch (std::exception& e)
        {
            spdlog::error("Failed to load JPG: {}", e.what());
            return std::nullopt;
        }
        catch (...)
        {
            spdlog::error("Failed to load JPG: unknown error");
            return std::nullopt;
        }
    }

    static std::optional<std::vector<byte>> ReadJpga(std::filesystem::path path, vector2ui& size, bool expectAlpha)
    {
        std::ifstream file(path, std::ios::binary | std::ios::ate);
        if (!file.is_open())
        {
            return std::nullopt;
            // throw std::runtime_error("Failed to open JPEG file.");
        }

        std::streamsize fileSize = file.tellg();
        file.seekg(0, std::ios::beg);

        std::vector<byte> jpegData(static_cast<uint32_t>(fileSize));
        if (!file.read(reinterpret_cast<char*>(jpegData.data()), fileSize))
        {
            return std::nullopt;
            // throw std::runtime_error("Failed to read JPEG file.");
        }

        size_t jpegSize = 0;
        auto data = ReadJpgBuf(jpegData.data(), jpegData.size(), size, jpegSize);
        if (!data)
        {
            return std::nullopt;
        }

        // TODO: maybe always load alpha?
        if (expectAlpha)
            AddJpgaData(size, path, *data, jpegData, fileSize, jpegSize, expectAlpha);

        return data;
    }

    static LPDIRECT3DTEXTURE8 LoadJpga(std::filesystem::path path, vector2ui& size, vector2 canvasSizeMultiplier,
                                       bool expectAlpha = false)
    {
        size = {256, 256};

        auto textureData = ReadJpga(path, size, expectAlpha);
        if (!textureData)
        {
            return nullptr;
            // textureData = TextureLoader::GenerateUnknown(width, height);
        }

        return TextureLoader::LoadFromRgbaPixelData(*sdk::DirectX::d3dDevice, size, canvasSizeMultiplier,
                                                    textureData->data());
    }
};
