#pragma once
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/spdlog.h>

template <typename Mutex>
class AnsiFileSink final : public spdlog::sinks::base_sink<Mutex>
{
public:
    explicit AnsiFileSink(const spdlog::filename_t& filename, bool truncate = false,
                          const spdlog::file_event_handlers& event_handlers = {})
        : file_helper_{event_handlers}
    {
        file_helper_.open(filename, truncate);
    }

    [[nodiscard]] const spdlog::filename_t& filename() const { return file_helper_.filename(); }

protected:
    void sink_it_(const spdlog::details::log_msg& msg) override
    {
        spdlog::memory_buf_t formatted;
        spdlog::sinks::base_sink<Mutex>::formatter_->format(msg, formatted);
        stripANSIEscapeSequences(formatted);
        file_helper_.write(formatted);
    }
    void flush_() override { file_helper_.flush(); }

private:
    void stripANSIEscapeSequences(spdlog::memory_buf_t& buf)
    {
        size_t len = buf.size();
        size_t i = 0;
        size_t out = 0;
        while (i < len)
        {
            if (buf.data()[i] == '\033' && buf.data()[i + 1] == '[')
            {
                size_t j = i;
                while (j < len && (buf.data()[j] != 'm'))
                {
                    j++;
                }
                if (j < len)
                {
                    std::copy(buf.data() + j + 1, buf.data() + len, buf.data() + i);
                    len -= (j - i + 1);
                    continue;
                }
            }
            buf.data()[out++] = buf.data()[i++];
        }
        buf.resize(out);
    }

    spdlog::details::file_helper file_helper_;
};
