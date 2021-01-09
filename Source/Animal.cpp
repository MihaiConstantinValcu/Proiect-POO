#include "../Include/Animal.h"

Animal::Animal(std::string _specie, std::string _rasa, std::string _tip, int _varsta) : specie(_specie), rasa(_rasa),
                                                                                        tip(_tip), varsta(_varsta) {}

Animal &Animal::operator=(Animal &a) {
    this->specie = a.specie;
    this->rasa = a.rasa;
    this->varsta = a.varsta;
    return *this;
}

Animal::~Animal() = default;

//Getters

std::string Animal::getSpecie() const {
    return specie;
}

std::string Animal::getRasa() const {
    return rasa;
}

std::string Animal::getTip() const {
    return tip;
}

int Animal::getVarsta() const {
    return varsta;
}

//Setters

void Animal::setSpecie(const std::string _specie) {
    this->specie = _specie;
}

void Animal::setRasa(const std::string _rasa) {
    this->rasa = _rasa;
}

void Animal::setTip(const std::string _tip) {
    this->tip = _tip;
}

void Animal::setVarsta(const int _varsta) {
    this->varsta = _varsta;
}
