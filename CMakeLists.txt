cmake_minimum_required(VERSION 3.25)
project(pf_meta_plugin_template)

include(GenerateExportHeader)

set(CMAKE_CXX_STANDARD 20)

add_library(pf_meta_plugin_template SHARED library.cpp)


generate_export_header(pf_meta_plugin_template EXPORT_FILE_NAME
        ${CMAKE_BINARY_DIR}/exports/pf_meta_plugin_template.hpp BASE_NAME META_PLUGIN)

target_include_directories(pf_meta_plugin_template PUBLIC ${CMAKE_BINARY_DIR}/exports)
target_include_directories(pf_meta_plugin_template PRIVATE speculo/meta_gen)
target_include_directories(pf_meta_plugin_template PRIVATE speculo/include)
