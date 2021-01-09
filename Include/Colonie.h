#pragma once

#include "Animal.h"

class Colonie {
    friend class Ecosistem;

    friend class EcosistemArtificial;

    Animal animal;
    int numar_indivizi;

    friend std::ostream &operator<<(std::ostream &, Colonie &);

public:
    Colonie(Animal animal, int nr);

    //Getters
    int getNumar() const;

    //Setters
    void setNumar(const int);
};