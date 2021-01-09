#pragma once

#include <iostream>

class Animal {
    friend class Colonie;

    std::string specie;
    std::string rasa;
    std::string tip; //Animalele pot fi terestre sau acvatice
    int varsta;
public:
    Animal(std::string = "", std::string = "", std::string = "", int = 0);

    Animal &operator=(Animal &);

    ~Animal();

    //Functionalitati


    //Getters
    std::string getSpecie() const;

    std::string getRasa() const;

    std::string getTip() const;

    int getVarsta() const;

    //Setters

    void setSpecie(const std::string);

    void setRasa(const std::string);

    void setTip(const std::string);

    void setVarsta(const int);
};
