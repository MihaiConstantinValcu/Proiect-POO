#pragma once

#include "Planta.h"

class PlantaFactory {
public:
    static Planta PlantaTerestra();

    static Planta PlantaAcvatica();
};