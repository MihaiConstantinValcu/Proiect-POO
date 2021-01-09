#pragma once

#include "EcosistemArtificial.h"

class Tester {
    Tester() = default;

    static Tester *tester;
public:
    void run();

    void testAnimal();

    void testColonie();

    void testPlanta();

    void testSoi();

    void testEcosistem();

    void testEcosistemArtificial();

    static Tester *start_test();

};