package("tga")
    
    set_homepage("https://github.com/aseprite/tga")
    set_description("C++ library to read/write Truevision TGA/TARGA files")
    set_license("MIT")
    
    set_urls("https://github.com/aseprite/tga.git")
    
    add_versions("2022.05.05", "d537510d98bc9706675746d132fa460639254a78")
    
    add_deps("cmake")
    on_install("windows", "mingw", function (package)
                import("package.tools.cmake").install(package, {})
    end)
   