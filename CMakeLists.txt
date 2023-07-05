cmake_minimum_required(VERSION 3.26)
project(speculo_plugin_template)

include(GenerateExportHeader)

set(CMAKE_CXX_STANDARD 20)

add_library(speculo_plugin_template SHARED library.cpp)

find_package(spdlog CONFIG REQUIRED)

target_link_libraries(speculo_plugin_template PRIVATE spdlog::spdlog_header_only)

generate_export_header(speculo_plugin_template EXPORT_FILE_NAME
        ${CMAKE_BINARY_DIR}/exports/speculo_plugin_template.hpp BASE_NAME META_PLUGIN)

target_include_directories(speculo_plugin_template PUBLIC ${CMAKE_BINARY_DIR}/exports)
target_include_directories(speculo_plugin_template PRIVATE speculo/speculo_gen)
target_include_directories(speculo_plugin_template PRIVATE speculo/include)
