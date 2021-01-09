#include "../Include/AnimalFactory.h"

Animal AnimalFactory::AnimalTerestru() {
    return Animal("Veverita", "Zburatoare", "Terestru", 1);
}

Animal AnimalFactory::AnimalAcvatic() {
    return Animal("Caras", "Auriu", "Acvatic", 200);
}