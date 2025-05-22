#include "ex/stackback.h"
#include <iostream>
#include <stdexcept>

// UTF-8 测试
// 当你看到这串中文的时候就证明UTF-8生效了

void foo() { throw std::runtime_error("foo failed"); }

int main(int argc, char const* argv[]) {

    CPPTRACE_TRY {
        foo();
    }
    CPPTRACE_CATCH(const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        PrintCurrentStack();
        
    }

    return 0;
}
