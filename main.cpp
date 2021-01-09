#include "Include/Tester.h"

Tester *Tester::tester = nullptr;

int main() {
    auto Test = Tester::start_test();
    Test->run();
    //disparitie() din Ecosistem da segmentation error daca rulez programul de 2 ori sau mai mult, l-am lasat comentat in Tester.cpp

    return 0;
}