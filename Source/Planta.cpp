#include "../Include/Planta.h"

Planta::Planta(std::string _specie, std::string _culoare, std::string _tip) : specie(_specie), culoare(_culoare),
                                                                              tip(_tip) {}

Planta &Planta::operator=(Planta &a) {
    this->specie = a.specie;
    this->culoare = a.culoare;
    return *this;
}

Planta::~Planta() = default;

//Getters

std::string Planta::getSpecie() const {
    return this->specie;
}

std::string Planta::getCuloare() const {
    return this->culoare;
}

std::string Planta::getTip() const {
    return this->tip;
}

//Setters

void Planta::setSpecie(const std::string _specie) {
    this->specie = _specie;
}

void Planta::setCuloare(const std::string _culoare) {
    this->culoare = _culoare;
}

void Planta::setTip(const std::string _tip) {
    this->tip = _tip;
}
