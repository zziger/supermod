package("tl_optional")
    set_kind("library", {headeronly = true})
    set_homepage("https://github.com/TartanLlama/optional")
    set_description("C++11/14/17 std::optional with functional-style extensions and reference support")
    set_license("CC0-1.0")

    add_urls("https://github.com/TartanLlama/optional.git")
    add_versions("1.1.0", "3a1209de8370bf5fe16362934956144b49591565")
    add_versions("1.0.0", "5c4876059c1168d5fa3c945bd8dd05ebbe61b6fe")

    on_install(function (package)
        os.cp("include/tl/optional.hpp", package:installdir("include/tl"))
    end)

    on_test(function (package)
        assert(package:check_cxxsnippets({test = [[
            #include <string>
            #include <iostream>
            #include <tl/optional.hpp>
            
            void test () {  
                int i = 42;
                tl::optional<int&> o = i;
                *o == 42;
                i = 12;
                *o == 12;
                &*o == &i;
            }
        ]]}, {configs = {languages = "c++11"}, includes = "tl/optional.hpp"}))
    end)