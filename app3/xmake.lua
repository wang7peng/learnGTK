add_rules("mode.debug", "mode.release")

-- 调用 pkg-config 来获取编译 gtk3 的头文件和链接库
add_requires("gtk+-3.0", { alias = "gtk3", system = true, configs = {shared = true} })


target("program_IM")
    set_languages("c17", "c++17")
    set_kind("binary")  -- 可选 binary static shared
    add_files("cmd/*.c")
    
    add_includedirs("include")
    add_packages("gtk3")
    add_linkdirs("/usr/local/lib", "/usr/lib")

    
 
