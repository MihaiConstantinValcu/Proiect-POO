#pragma once

#include "Planta.h"

class Soi {
    friend class Ecosistem;

    friend class EcosistemArtificial;

    Planta planta;
    int numar_indivizi;

    friend class Ecosistem;

public:
    Soi(Planta, int);

    friend std::ostream &operator<<(std::ostream &, Soi &);

    //Getters
    int getNumar() const;

    //Setters
    void setNumar(const int);
};