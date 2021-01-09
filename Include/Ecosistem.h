#pragma once

#include "Soi.h"
#include "Colonie.h"
#include <vector>
#include <fstream>

class Ecosistem {
protected:
    std::vector<Colonie> animale;
    std::vector<Soi> plante;
    int suprafata; //metri^2
    int umiditate;
    float temperatura;
    std::string precipitatii;
public:
    Ecosistem();

    Ecosistem(int, int, float, std::string, std::string, std::string);

    Ecosistem(Ecosistem &);

    Ecosistem &operator=(const Ecosistem &);

    virtual ~Ecosistem();

    friend std::ostream &operator<<(std::ostream &, Ecosistem &);

    //Functionalitati
    virtual void disparitie();

    virtual void simulareSchimbareClima(const int);

    virtual void simulareSchimbareClima(const float);

    //Getters
    int getUmiditate() const;

    int getTemperatura() const;

    int getSuprafata() const;

    std::string getPrecipitatii() const;

    //Setters
    void setUmiditate(const int);

    void setTemperatura(const int);

    void setSuprafata(const int);

    void setPrecipitatii(const std::string);
};