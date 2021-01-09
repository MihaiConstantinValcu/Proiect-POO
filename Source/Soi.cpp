#include "../Include/Soi.h"

Soi::Soi(Planta planta, int nr) {
    this->planta = planta;
    this->numar_indivizi = nr;
}

std::ostream &operator<<(std::ostream &os, Soi &soi) {
    os << soi.planta.getSpecie() << ' ' << soi.planta.getCuloare() << ": " << soi.numar_indivizi << std::endl;
    return os;
}

//Getters
int Soi::getNumar() const {
    return this->numar_indivizi;
}

//Setters
void Soi::setNumar(const int _numar) {
    this->numar_indivizi = _numar;
}