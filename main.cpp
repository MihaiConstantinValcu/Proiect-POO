#include "Include/Tester.h"

Tester *Tester::tester = nullptr;

int main() {
    auto Test = Tester::start_test();

    try {
        Test->run();
    }
    catch (const char *eroare) {
        std::cout << eroare;
    }

    return 0;
}