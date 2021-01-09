#pragma once

#include <iostream>

class Planta {

    std::string specie;
    std::string culoare;
    std::string tip; //Plantele pot fi terestre sau acvatice
    friend class Soi;

public:
    Planta(std::string = "", std::string = "", std::string = "");

    Planta &operator=(Planta &);

    ~Planta();

    //Getters
    std::string getSpecie() const;

    std::string getCuloare() const;

    std::string getTip() const;

    //Setters

    void setSpecie(const std::string);

    void setCuloare(const std::string);

    void setTip(const std::string);

};