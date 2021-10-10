cmake_minimum_required (VERSION 3.8)

add_executable (CMakeTarget_1 "Modul_test.cpp" "Modul_test.h" "../CPP Labs - 2021/string.h" "../CPP Labs - 2021/string.inl")
target_link_libraries(CMakeTarget_1 "gmock_main")

#Спросить у РР про "../CPP Labs - 2021/string.h" "../CPP Labs - 2021/string.cpp".
