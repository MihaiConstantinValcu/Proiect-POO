#include "../Include/Colonie.h"

Colonie::Colonie(Animal animal, int nr) {
    this->animal = animal;
    this->numar_indivizi = nr;
}

std::ostream &operator<<(std::ostream &os, Colonie &colonie) {

    os << colonie.animal.getSpecie() << ' ' << colonie.animal.getRasa() << ": " << colonie.numar_indivizi << std::endl;
    return os;
}

//Getters
int Colonie::getNumar() const {
    return this->numar_indivizi;
}

//Setters

void Colonie::setNumar(const int _numar) {
    this->numar_indivizi = _numar;
}