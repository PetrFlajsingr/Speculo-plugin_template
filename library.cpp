#include "library.h"

#include <string>

using namespace std::string_literals;

class DemoCodeGenerator : public speculo::gen::CodeGenerator {
public:

    speculo::gen::RecordGenerationResult generate(speculo::gen::RecordTypeInfo &typeInfo) override {
        speculo::gen::RecordGenerationResult result;
        result.typeBodyCode = "public: int demo() const;\n";
        result.cppCode = "int "s + typeInfo.fullName + "::demo() const { return 10; }\n";
        return result;
    }

    speculo::gen::GenerationResult generate(const speculo::gen::EnumTypeInfo &typeInfo) override {
        return {"// "s + typeInfo.fullName + "\n", "// "s + typeInfo.fullName + "\n"};
    }

    speculo::gen::FilePrologueEpilogue getPrologueEpilogue() override {
        return {
                .cppPrologue = "#include \""s + std::string{getRelativePathToOriginal()} + "\"\n"
        };
    }


    // decides order in which the generators are used
    std::uint64_t getPriority() const override { return 10; }
};


speculo::gen::CodeGenerator *create() { return new DemoCodeGenerator{}; }

void destroy(speculo::gen::CodeGenerator *ptr) { delete ptr; }
