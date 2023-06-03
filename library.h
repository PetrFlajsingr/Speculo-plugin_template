#pragma once

#include <pf_meta_plugin_template.hpp>
#include <codegen/CodeGenerator.hpp>

extern "C" {

META_PLUGIN_EXPORT pf::meta_gen::CodeGenerator *create();

META_PLUGIN_EXPORT void destroy(pf::meta_gen::CodeGenerator *ptr);
}