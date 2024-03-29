set_project("supercow-mod")
add_repositories("local-repo deps")
add_requires("semver 0.3.0")
add_requires("tl_optional 1.1.0")
add_requires("minhook multihook")
add_requires("lodepng")
add_requires("libjpeg-turbo")
add_requires("imgui v1.90.4-docking", { configs = { win32 = true, user_config = path.join(os.curdir(), "src/ImGuiConfig.h") }})
add_requires("luajit 2.1.0-beta3")
add_requires("yaml-cpp 0.7.0")
add_requires("tga 2022.05.05")
add_requires("gtest v1.14.0")
add_requires("spdlog v1.13.0", { configs = { wchar = true }})

option("mod-version")
    set_default("0.0.0")
    set_showmenu(true)
    add_defines("VERSION=\"$(mod-version)\"")

target("d3d8")
    set_kind("shared")
    set_languages("c++20")
    set_basename("d3d8")
    set_prefixname("")
    set_suffixname("")
    add_options("mod-version")
    add_rules("plugin.compile_commands.autoupdate")

    add_files("./src/**.cpp")
    add_files("./src/**.def")
    add_files("./src/**.rc")
    add_headerfiles("./src/**.h")
    add_headerfiles("xmake.lua", {install = false})
    add_headerfiles("src/scripting/env/**", {install = false})
    add_includedirs("src")
    add_includedirs("src/thirdparty")
    add_linkdirs("deps")
    add_shflags("/DEF:src/d3d8/d3d8.def")
    add_cxflags("/MP", { force = true })
    add_cxflags("/utf-8", { force = true })

    add_packages("semver")
    add_packages("tl_optional")
    add_packages("minhook")
    add_packages("lodepng")
    add_packages("imgui")
    add_packages("luajit")
    add_packages("yaml-cpp")
    add_packages("libjpeg-turbo")
    add_packages("tga")
    add_packages("spdlog")
    add_syslinks("Gdiplus")
    add_syslinks("Shell32")
    add_syslinks("d3d9")
    add_syslinks("Ole32")
    add_syslinks("Shcore")
    add_links("bass")

    add_defines("_SILENCE_CXX20_CODECVT_FACETS_DEPRECATION_WARNING", "_SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING")
    add_defines("_UNICODE", "UNICODE", "NOMINMAX", "IMGUI_DEFINE_MATH_OPERATORS")
    set_symbols("debug")

    on_install(function (target)
        if not os.exists(target:installdir()) then
            cprint("${red}Укажите папку с установленной Супер-Коровой в аргумент -o")
            os.exit(1)
            return
        end

        local basename = path.join(target:targetdir(), "d3d8.")
        os.cp(basename .. "dll", target:installdir())
        if os.exists(basename .. "pdb") then
            os.cp(basename .. "pdb", target:installdir())
        end
    end)

    if not is_mode("debug") then
        add_defines("NDEBUG")
    end


target("test")
    set_kind("binary")
    set_languages("c++20")
    add_options("mod-version")

    add_files("./test/**.cpp")
    add_files("./src/**.cpp")
    add_files("./src/**.def")
    add_files("./src/**.rc")
    add_headerfiles("./test/**.h")
    add_headerfiles("./src/**.h")
    add_headerfiles("xmake.lua", {install = false})
    add_headerfiles("src/scripting/env/**", {install = false})
    add_includedirs("src")
    add_includedirs("src/thirdparty")
    add_linkdirs("deps")
    add_cxflags("/MP", { force = true })
    add_cxflags("/utf-8", { force = true })

    add_packages("gtest")
    add_packages("semver")
    add_packages("tl_optional")
    add_packages("minhook")
    add_packages("lodepng")
    add_packages("imgui")
    add_packages("luajit")
    add_packages("yaml-cpp")
    add_packages("libjpeg-turbo")
    add_packages("tga")
    add_packages("spdlog")
    add_syslinks("Gdiplus")
    add_syslinks("Shell32")
    add_syslinks("d3d9")
    add_syslinks("Ole32")
    add_syslinks("Shcore")
    add_links("bass")

    add_defines("UNIT_TESTS")

    add_defines("_SILENCE_CXX20_CODECVT_FACETS_DEPRECATION_WARNING", "_SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING")
    add_defines("_UNICODE", "UNICODE", "NOMINMAX", "IMGUI_DEFINE_MATH_OPERATORS")
    set_symbols("debug")

    after_build(function(target)
        os.cp('$(projectdir)/deps/bass.dll', path.directory(target:targetfile()))
    end)

    if not is_mode("debug") then
        add_defines("NDEBUG")
    end