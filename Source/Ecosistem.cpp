#include "../Include/Ecosistem.h"

Ecosistem::Ecosistem() = default;

Ecosistem::Ecosistem(int _suprafata, int _umiditate, float _temperatura, std::string _precipitatii,
                     std::string inputAnimale, std::string inputPlante) : suprafata(_suprafata), umiditate(_umiditate),
                                                                          temperatura(_temperatura),
                                                                          precipitatii(_precipitatii) {
    std::ifstream f(inputAnimale);
    std::ifstream g(inputPlante);

    std::string _specie, _rasa, _culoare, _tip;
    int _varsta, nr_animale, nr_plante;

    while (f >> _specie >> _rasa >> _tip >> _varsta >> nr_animale) {
        Animal _animal(_specie, _rasa, _tip, _varsta);
        Colonie animal(_animal, nr_animale);
        animale.push_back(animal);
    }

    while (g >> _specie >> _culoare >> _tip >> nr_plante) {
        Planta _planta(_specie, _culoare, _tip);
        Soi planta(_planta, nr_plante);
        plante.push_back(planta);
    }

    f.close();
    g.close();
}

Ecosistem::Ecosistem(Ecosistem &eco) {
    for (auto &i : eco.animale)
        animale.push_back(i);

    for (auto &i : eco.plante)
        plante.push_back(i);

    umiditate = eco.umiditate;
    temperatura = eco.temperatura;
    precipitatii = eco.precipitatii;
}

Ecosistem &Ecosistem::operator=(const Ecosistem &eco) {
    for (auto &i : eco.animale)
        animale.push_back(i);

    for (auto &i : eco.plante)
        plante.push_back(i);

    umiditate = eco.umiditate;
    temperatura = eco.temperatura;
    precipitatii = eco.precipitatii;

    return *this;
}

Ecosistem::~Ecosistem() = default;

std::ostream &operator<<(std::ostream &os, Ecosistem &ecosistem) {

    for (auto &i:ecosistem.animale)
        os << i;
    for (auto &i:ecosistem.plante)
        os << i;
    os << std::endl;

    return os;
}

//Functionalitati

void Ecosistem::disparitie() {
    int minim = this->animale[0].getNumar(); //Aici uneori imi da segmentation fault, uneori nu, nu imi dau seama care e cauza
    std::string nume = this->animale[0].animal.getSpecie() + " " + this->animale[0].animal.getRasa();
    for (auto &i : this->animale)
        if (i.getNumar() < minim) {
            minim = i.getNumar();
            nume = i.animal.getSpecie() + " " + i.animal.getRasa();
        }
    if (minim < 10)
        std::cout << nume << " e pe cale de disparitie\n";

    int minim2 = this->plante[0].getNumar();
    std::string nume2 = this->plante[0].planta.getSpecie() + " " + this->plante[0].planta.getCuloare();
    for (auto &i : this->plante)
        if (i.getNumar() < minim) {
            minim = i.getNumar();
            nume2 = i.planta.getSpecie() + " " + i.planta.getCuloare();
        }

    if (minim2 < 10)
        std::cout << nume2 << " e pe cale de disparitie\n";

    if (minim > 10 && minim2 > 10)
        std::cout << "Nu exista animale sau plante pe cale de disparitie.\n";

    std::cout << std::endl;
}

void Ecosistem::simulareSchimbareClima(const int _umiditate) {
    if (this->umiditate < _umiditate) {
        this->temperatura -= (_umiditate - this->umiditate) /
                             2; // Daca umiditatea creste, atunci temperatura scade (formula fictiva)
        std::cout << "Temperatura a scazut la: " << this->temperatura << ".\n";
    } else if (this->umiditate > _umiditate) {
        this->temperatura += (_umiditate - this->umiditate) /
                             2; // Daca umiditatea scade, atunci temperatura creste (formula fictiva)
        std::cout << "Temperatura a crescut la: " << this->temperatura << ".\n";
    } else std::cout << "Temperatura nu s-a schimbat.\n";
}

void Ecosistem::simulareSchimbareClima(const float _temperatura) {
    if (this->temperatura < _temperatura) {
        this->umiditate -=
                (_temperatura - this->temperatura) / 2; // Daca temperatura creste, umiditatea scade (formula fictiva)
        std::cout << "Umiditatea a scazut la: " << this->umiditate << ".\n";
    } else if (this->temperatura > _temperatura) {
        this->umiditate +=
                (_temperatura - this->temperatura) / 2; // Daca temperatura scade, umiditatea creste (formula fictiva)
        std::cout << "Umiditatea a crescut la: " << this->umiditate << ".\n";
    } else std::cout << "Umiditatea nu s-a schimbat.\n";
}

//Getters
int Ecosistem::getUmiditate() const {
    return this->umiditate;
}

int Ecosistem::getTemperatura() const {
    return this->temperatura;
}

int Ecosistem::getSuprafata() const {
    return this->suprafata;
}

std::string Ecosistem::getPrecipitatii() const {
    return this->precipitatii;
}

//Setters
void Ecosistem::setUmiditate(const int _umiditate) {
    this->umiditate = _umiditate;
}

void Ecosistem::setTemperatura(const int _temperatura) {
    this->temperatura = _temperatura;
}

void Ecosistem::setSuprafata(const int _suprafata) {
    this->suprafata = _suprafata;
}

void Ecosistem::setPrecipitatii(const std::string _precipitatii) {
    this->precipitatii = _precipitatii;
}