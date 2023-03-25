package("semver")
    set_kind("library", {headeronly = true})
    set_homepage("https://github.com/Neargye/semver")
    set_description("Semantic Versioning for modern C++")
    set_license("MIT")

    add_urls("https://github.com/Neargye/semver.git")
    add_versions("0.3.0", "6c1042c108bacdecce6eeeadcb9c87a75c4d8b2d")
    add_versions("0.2.2", "2bbc917fcbb2455868ec5cad37a8b8fad75ebacb")
    add_versions("0.2.1", "72680581f88f3c808b050ff5ca96e58589f654ee")
    add_versions("0.2.0", "4a62cad105b10f73a95976e3497645a8897193f5")
    add_versions("0.1.8", "5191a763cf16041df33a20e17613145880068253")

    on_install(function (package)
        os.cp("include/semver.hpp", package:installdir("include"))
    end)

    on_test(function (package)
        assert(package:check_cxxsnippets({test = [[
            #include <string>
            #include <iostream>
            #include <semver.hpp>
            
            void test () {
                constexpr semver::version v1{1, 4, 3};
                constexpr semver::version v2{1, 2, 4, semver::prerelease::alpha, 10};
                static_assert(v1 != v2);
                static_assert(v1 > v2);
                static_assert(v1 >= v2);
                static_assert(v2 < v1);
                static_assert(v2 <= v1);
            }
        ]]}, {configs = {languages = "c++17"}, includes = "semver.hpp"}))
    end)