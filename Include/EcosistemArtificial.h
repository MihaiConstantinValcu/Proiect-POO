#pragma once

#include "Ecosistem.h"

class EcosistemArtificial : public Ecosistem {
public:
    EcosistemArtificial(int, int, float, std::string, std::string, std::string);

    void disparitie();

    void simulareSchimbareClima(const int);

    void simulareSchimbareClima(const float);
};