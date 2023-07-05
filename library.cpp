#include "library.h"

#include <string>

using namespace std::string_literals;

class DemoCodeGenerator : public speculo::gen::CodeGenerator {
public:
    speculo::gen::GenerationResult start() override {
        return {"", "#include \""s + std::string{getRelativePathToOriginal()} + "\"\n", ""};
    }

    speculo::gen::RecordGenerationResult generate(speculo::gen::RecordTypeInfo &typeInfo) override {
        return {
                "// "s + typeInfo.fullName + "\n",
                "int "s + typeInfo.fullName + "::demo() const { return 10; }\n",
                "// "s + typeInfo.fullName + "\n",
                {},
                "public: int demo() const;\n"
        };
    }

    speculo::gen::GenerationResult generate(const speculo::gen::EnumTypeInfo &typeInfo) override {
        return {"// "s + typeInfo.fullName + "\n", "// "s + typeInfo.fullName + "\n"};
    }

    speculo::gen::GenerationResult end() override {
        return {"// Code generated in header\n", "// Code generated in source", ""};
    }

    // decides order in which the generators are used
    std::uint64_t getPriority() const override { return 10; }
};


speculo::gen::CodeGenerator *create() { return new DemoCodeGenerator{}; }

void destroy(speculo::gen::CodeGenerator *ptr) { delete ptr; }
