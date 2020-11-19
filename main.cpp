#include <iostream>
#include <vector>
#include <fstream>

class Animal{

    std::string specie;
    std::string rasa;
    int varsta;
    friend class Colonie;

public:
    Animal(std::string _specie = "", std::string _rasa ="", int _varsta = 0){
        specie = _specie;
        rasa = _rasa;
        varsta = _varsta;
    }

    Animal& operator=(Animal& a){
        this->specie = a.specie;
        this->rasa = a.rasa;
        this->varsta = a.varsta;
        return *this;
    }

    std::string getSpecie(){
        return specie;
    }
    std::string getRasa(){
        return rasa;
    }
    int getVarsta(){
        return varsta;
    }

};

class Colonie{

    Animal animal;
    int numar_indivizi;
    friend class Ecosistem;

public:
    Colonie(Animal animal, int nr){
        this->animal = animal;
        this->numar_indivizi = nr;
    }
    friend std::ostream& operator<<(std::ostream&, Colonie&);

};

std::ostream &operator<<(std::ostream &os, Colonie &colonie) {

    os<<colonie.animal.getSpecie()<<' '<<colonie.animal.getRasa()<<": "<<colonie.numar_indivizi<<std::endl;
    return os;
}

class Planta{

    std::string specie;
    std::string culoare;
    friend class Soi;

public:
    Planta(std::string _specie ="", std::string _culoare = ""){
        specie = _specie;
        culoare = _culoare;
    }

    Planta& operator=(Planta& a){
        this->specie = a.specie;
        this->culoare = a.culoare;
        return *this;
    }

    std::string getSpecie(){
        return specie;
    }

    std::string getCuloare(){
        if(culoare == "\0")
            return "";
        else return culoare;
    }
};

class Soi{

    Planta planta;
    int numar_indivizi;
    friend class Ecosistem;

public:
    Soi(Planta planta, int nr){
        this->planta = planta;
        this->numar_indivizi = nr;
    }

    friend std::ostream& operator<<(std::ostream&, Soi&);
};
std::ostream &operator<<(std::ostream& os, Soi& soi) {
    os<<soi.planta.getSpecie()<<' '<<soi.planta.getCuloare()<<": "<<soi.numar_indivizi<<std::endl;
    return os;
}
class Ecosistem{

    std::vector<Colonie> animale;
    std::vector<Soi> plante;
    int umiditate;
    int temperatura;
    std::string precipitii;
public:
    Ecosistem(std::vector<Colonie> _animale, std::vector<Soi> _plante,int _umiditate, int _temperatura, std::string _precipitatii): umiditate(_umiditate), temperatura(_temperatura),precipitii(_precipitatii){

        for(auto &i : _animale)
            animale.push_back(i);

        for(auto &i : _plante)
            plante.push_back(i);

        std::cout<<"Biocenoza sistemului a fost populata.\n";

    }
    Ecosistem(int _umiditate, int _temperatura, std::string _precipitatii, std::string inputAnimale, std::string inputPlante):umiditate(_umiditate), temperatura(_temperatura),precipitii(_precipitatii){
        std::ifstream f(inputAnimale);
        std::ifstream g(inputPlante);

        std::string _specie, _rasa, _culoare;
        int _varsta, nr_animale, nr_plante;

        while(f>>_specie>>_rasa>>_varsta>>nr_animale) {
            Animal _animal(_specie, _rasa, _varsta);
            Colonie animal(_animal,nr_animale);
            animale.push_back(animal);
        }

        while(g>>_specie>>_culoare>>nr_plante){
            Planta _planta(_specie, _culoare);
            Soi planta(_planta, nr_plante);
            plante.push_back(planta);
        }

        f.close();
        g.close();

    }

    Ecosistem(Ecosistem &eco){
        for(auto &i : eco.animale)
            animale.push_back(i);

        for(auto &i : eco.plante)
            plante.push_back(i);

        umiditate = eco.umiditate;
        temperatura = eco.temperatura;
        precipitii = eco.precipitii;
    }

    Ecosistem &operator=(const Ecosistem &eco) {
        for (auto &i : eco.animale)
            animale.push_back(i);

        for (auto &i : eco.plante)
            plante.push_back(i);

        umiditate = eco.umiditate;
        temperatura = eco.temperatura;
        precipitii = eco.precipitii;

        return *this;
    }
    ~Ecosistem(){
        std::cout<<"Biocenoza ecosistemului a fost dusa la extinctie.\n";
    }

    friend std::ostream& operator<<(std::ostream&, Ecosistem&);

    void disparitie(){
        int minim = animale[0].numar_indivizi;
        std::string nume = animale[0].animal.getSpecie() + " " + animale[0].animal.getRasa();
        for(auto &i : animale)
            if(i.numar_indivizi < minim){
                minim = i.numar_indivizi;
                nume = i.animal.getSpecie() + " " + i.animal.getRasa();
            }
        if(minim < 10)
            std::cout<<nume<<" e pe cale de disparitie\n";

        int minim2 = plante[0].numar_indivizi;
        std::string nume2 = plante[0].planta.getSpecie() + " " + plante[0].planta.getCuloare();
        for(auto &i : plante)
            if(i.numar_indivizi < minim){
                minim = i.numar_indivizi;
                nume2 = i.planta.getSpecie() + " " + i.planta.getCuloare();
            }

        if(minim2 < 10)
            std::cout<<nume2<<" e pe cale de disparitie\n";

        std::cout<<std::endl;
    }
};

std::ostream &operator<<(std::ostream &os, Ecosistem &ecosistem) {

    for(auto &i:ecosistem.animale)
        os<<i;
    for(auto &i:ecosistem.plante)
        os<<i;
    os<<std::endl;

    return os;
}


int main() {

    const std::string inputAnimale = "Date/animale.txt";
    const std::string inputPlante = "Date/plante.txt";

    //Testez metodele din clasele Animal si Planta
    Animal animal1("pisica","bengaleza",6);
    Animal animal2("caine","shiba",3);
    Planta planta1("crizantema","albastra");

    std::cout<<"Primul animal: "<<animal1.getSpecie()<<' '<<animal1.getRasa()<<' '<<animal1.getVarsta()<<'\n';
    std::cout<<"Al doilea animal: "<<animal2.getSpecie()<<' '<<animal2.getRasa()<<' '<<animal2.getVarsta()<<'\n';
    std::cout<<"Planta: "<<planta1.getSpecie()<<' '<<planta1.getCuloare()<<"\n\n";

    //Construiesc 2 vectori de obiecte pentru primul constructor al clasei Ecosistem

    Colonie animale1(animal1,3);
    Colonie animale2(animal2,50);
    Soi plante1(planta1,60);

    std::vector<Colonie> _animale;
    std::vector<Soi> _plante;
    _animale.push_back(animale1);
    _animale.push_back(animale2);
    _plante.push_back(plante1);

    //Testez clasa Ecosistem

    Ecosistem Gradina(_animale,_plante,50,24,"Ploaie");
    Ecosistem GradinaVecinului(Gradina);
    Ecosistem PadureNorvegiana(40,32,"Senin",inputAnimale,inputPlante);
    Ecosistem Padure = PadureNorvegiana;

    std::cout<<Gradina;
    std::cout<<GradinaVecinului;
    std::cout<<PadureNorvegiana;
    std::cout<<Padure;

    Gradina.disparitie();

    return 0;
}