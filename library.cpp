#include "library.h"

#include <string>

using namespace std::string_literals;

class DemoCodeGenerator : public pf::meta_gen::CodeGenerator {
public:
    pf::meta_gen::GenerationResult start() override {
        return {"", "#include \""s + std::string{getRelativePathToOriginal()} + "\"\n", ""};
    }

    pf::meta_gen::RecordGenerationResult generate(const pf::meta_gen::RecordTypeInfo &typeInfo) override {
        return {
                "public: int demo() const;\n",
                "// "s + typeInfo.fullName + "\n",
                "// "s + typeInfo.fullName + "\n",
                "int "s + typeInfo.fullName + "::demo() const { return 10; }\n",
        };
    }

    pf::meta_gen::GenerationResult generate(const pf::meta_gen::EnumTypeInfo &typeInfo) override {
        return {"// "s + typeInfo.fullName + "\n", "// "s + typeInfo.fullName + "\n"};
    }
    pf::meta_gen::GenerationResult end() override { return {"// Code generated in header\n", "// Code generated in source", ""}; }

    // decides order in which the generators are used
    uint64_t getPriority() const override { return 10; }
};


pf::meta_gen::CodeGenerator *create() { return new DemoCodeGenerator{}; }

void destroy(pf::meta_gen::CodeGenerator *ptr) { delete ptr; }
