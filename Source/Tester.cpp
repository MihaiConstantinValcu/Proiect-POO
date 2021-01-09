#include "../Include/Tester.h"
#include <memory>
#include <exception>

//Functionalitati

void Tester::run() {
    std::cout << "(*Animalele sunt grupate in colonii, iar plantele in soiuri.*)\n";
    std::cout << "(*Totalitatea acestora si totalitatea factorilor abiotici formeaza un ecosistem*)\n\n";
    std::cout << "Alege ce doresti sa testezi:" << "\n1. Clasa Animal" << "\n2. Clasa Colonie" << "\n3. Clasa Planta"
              << "\n4. Clasa Soi" << "\n5. Clasa Ecosistem" << "\n6. Clasa EcosistemArtificial\n";
    char choice = '0';
    std::cin >> choice;
    if (choice < '1' || choice > '6')
        throw "\nAi ales o optiune invalida. Te rog reporneste programul pentru a incerca din nou.";
    switch (choice) {
        case '1':
            this->testAnimal();
            break;
        case '2':
            this->testColonie();
            break;
        case '3':
            this->testPlanta();
            break;
        case '4':
            this->testSoi();
            break;
        case '5':
            this->testEcosistem();
            break;
        case '6':
            this->testEcosistemArtificial();
            break;
    }
}

void Tester::testAnimal() {
    Animal testAnimalTerestru = AnimalFactory::AnimalTerestru();
    Animal testAnimalAcvatic = AnimalFactory::AnimalAcvatic();
    Animal testCopy = testAnimalTerestru;
    testCopy.setSpecie("Urs");
    testCopy.setRasa("Grizzly");
    testCopy.setTip("Terestru");
    testCopy.setVarsta(13);
    std::cout << "\nAnimalul initial:\n";
    std::cout << "\nSpecie: " << testAnimalTerestru.getSpecie() << "\nRasa: " << testAnimalTerestru.getRasa()
              << "\nTip: "
              << testAnimalTerestru.getTip() << "\nVarsta: " << testAnimalTerestru.getVarsta() << "\n\n";
    std::cout << "Copia animalului dupa setteri:\n";
    std::cout << "\nSpecie: " << testCopy.getSpecie() << "\nRasa: " << testCopy.getRasa() << "\nTip: "
              << testCopy.getTip() << "\nVarsta: " << testCopy.getVarsta() << "\n";
}

void Tester::testColonie() {
    Animal testAnimal("Urs", "Grizzly", "Terestru", 13);
    Colonie test(testAnimal, 20);
    test.setNumar(15);
    std::cout << "Numar indivizi in colonie: " << test.getNumar() << "\n";
}

void Tester::testPlanta() {
    Planta testPlantaTerestra = PlantaFactory::PlantaTerestra();
    Planta testPlantaAcvatica = PlantaFactory::PlantaAcvatica();
    Planta testCopy(testPlantaAcvatica);
    testCopy.setSpecie("Papadie");
    testCopy.setTip("Terestru");
    testCopy.setCuloare("Galbena");
    std::cout << "\nPlanta initiala:";
    std::cout << "\nSpecie: " << testPlantaAcvatica.getSpecie() << "\nCuloare: " << testPlantaAcvatica.getCuloare()
              << "\nTip: "
              << testPlantaAcvatica.getTip() << "\n\n";
    std::cout << "Copia plantei dupa setteri:\n";
    std::cout << "\nSpecie: " << testCopy.getSpecie() << "\nCuloare: " << testCopy.getCuloare() << "\nTip: "
              << testCopy.getTip() << "\n";
}

void Tester::testSoi() {
    Planta testPlanta("Iarba", "Verde", "Terestru");
    Soi test(testPlanta, 20);
    test.setNumar(15);
    std::cout << "Numar indivizi in soi: " << test.getNumar() << "\n";
}

void Tester::testEcosistem() {
    std::string inputAnimale, inputPlante;
    int choice;
    std::cout << "\nAlege un sablon:\n1. Ecosistem Terestru\n2. Ecosistem Acvativ.\n";
    std::cin >> choice;
    if (choice == 1) {
        inputAnimale = "Date/animaleTerestre.txt";
        inputPlante = "Date/planteTerestre.txt";
    } else if (choice == 2) {
        inputAnimale = "Date/animaleAcvatice.txt";
        inputPlante = "Date/planteAcvatice.txt";
    } else throw "Nu ai ales un sablon existent. Te rog reporneste programul pentru a incerca din nou.";


    Ecosistem test(0, 0, 0, "Ploaie", inputAnimale, inputPlante);
    Ecosistem testCopy(test);
    std::cout << "\n" << test;

    std::cout << "Test Getters & Setters:\n";
    test.setSuprafata(2000);
    test.setUmiditate(40);
    test.setTemperatura(32);
    test.setPrecipitatii("Senin");
    std::cout << "Suprafata: " << test.getSuprafata() << "\nUmiditatea: " << test.getUmiditate() << "\nTemperatura: "
              << test.getTemperatura() << "\nPrecipitatiile: " << test.getPrecipitatii() << "\n";

    std::cout << "\nTest Functionalitati:\n";
    //test.disparitie();
    test.simulareSchimbareClima(50);
    test.simulareSchimbareClima(float(50));

    std::cout << "\nTest functii virtuale cu smart pointers\n";
    std::unique_ptr<Ecosistem> eco(new EcosistemArtificial(0, 0, 0, "Ploaie", inputAnimale, inputPlante));
    //eco->disparitie();
    eco->simulareSchimbareClima(50);
    eco->simulareSchimbareClima(float(50));
}

void Tester::testEcosistemArtificial() {
    std::string inputAnimale, inputPlante;
    int choice;
    std::cout << "\nAlege un sablon:\n1. Ecosistem Terestru\n2. Ecosistem Acvativ.\n";
    std::cin >> choice;
    if (choice == 1) {
        inputAnimale = "Date/animaleTerestre.txt";
        inputPlante = "Date/planteTerestre.txt";
    } else if (choice == 2) {
        inputAnimale = "Date/animaleAcvatice.txt";
        inputPlante = "Date/planteAcvatice.txt";
    } else throw "Nu ai ales un sablon existent. Te rog reporneste programul pentru a incerca din nou.";

    Ecosistem test(0, 0, 0, "Ploaie", inputAnimale, inputPlante);
    test.setSuprafata(2000);
    test.setUmiditate(40);
    test.setTemperatura(32);
    test.setPrecipitatii("Senin");
    std::cout << "\n" << test;

    std::cout << "Test Getters & Setters:\n";
    test.setSuprafata(2000);
    test.setUmiditate(40);
    test.setTemperatura(32);
    test.setPrecipitatii("Senin");
    std::cout << "Suprafata: " << test.getSuprafata() << "\nUmiditatea: " << test.getUmiditate() << "\nTemperatura: "
              << test.getTemperatura() << "\nPrecipitatiile: " << test.getPrecipitatii() << "\n";

    std::cout << "\nTest Functionalitati:\n";
    test.disparitie();
    test.simulareSchimbareClima(50);
    test.simulareSchimbareClima(float(50));
}

Tester *Tester::start_test() {
    if (tester == nullptr)
        tester = new Tester;
    return tester;
}