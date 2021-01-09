#include "../Include/EcosistemArtificial.h"

EcosistemArtificial::EcosistemArtificial(int _suprafata, int _umiditate, float _temperatura, std::string _precipitatii,
                                         std::string inputAnimale, std::string inputPlante) : Ecosistem(_suprafata,
                                                                                                        _umiditate,
                                                                                                        _temperatura,
                                                                                                        _precipitatii,
                                                                                                        inputAnimale,
                                                                                                        inputPlante) {}

//Functionalitati

void EcosistemArtificial::disparitie() {
    int minim = animale[0].getNumar();
    std::string nume = animale[0].animal.getSpecie() + " " + animale[0].animal.getRasa();
    for (auto &i : animale)
        if (i.numar_indivizi < minim) {
            minim = i.numar_indivizi;
            nume = i.animal.getSpecie() + " " + i.animal.getRasa();
        }
    if (minim < 10)
        std::cout << "Populatia de " << nume << " trebuie repopulata.\n";

    int minim2 = plante[0].getNumar();
    std::string nume2 = plante[0].planta.getSpecie() + " " + plante[0].planta.getCuloare();
    for (auto &i : plante)
        if (i.numar_indivizi < minim) {
            minim = i.numar_indivizi;
            nume2 = i.planta.getSpecie() + " " + i.planta.getCuloare();
        }

    if (minim2 < 10)
        std::cout << "Populatia de " << nume2 << " trebuie repopulata.\n";

    std::cout << std::endl;
}

void EcosistemArtificial::simulareSchimbareClima(const int _umiditate) {
    setUmiditate(_umiditate);
    std::cout << "Intr-un ecosistem artificial, umiditatea si temperatura pot fi controlate individual.\n";
}

void EcosistemArtificial::simulareSchimbareClima(const float _temperatura) {
    setTemperatura(_temperatura);
    std::cout << "Intr-un ecosistem artificial, umiditatea si temperatura pot fi controlate individual.\n";
}