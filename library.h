#pragma once

#include <speculo_plugin_template.hpp>
#include <codegen/CodeGenerator.hpp>

extern "C" {

META_PLUGIN_EXPORT speculo::gen::CodeGenerator *create();

META_PLUGIN_EXPORT void destroy(speculo::gen::CodeGenerator *ptr);
}