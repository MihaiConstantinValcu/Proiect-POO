#include "../Include/PlantaFactory.h"

Planta PlantaFactory::PlantaTerestra() {
    return Planta("Lalea", "Albastra", "Terestra");
}

Planta PlantaFactory::PlantaAcvatica() {
    return Planta("Alga", "Rosie", "Acvatica");
}