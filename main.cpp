#include <iostream>
#include <vector>
#include <fstream>

class Animal{

    std::string specie;
    std::string rasa;
    int varsta;

public:
    Animal(std::string _specie, std::string _rasa, int _varsta){
        specie = _specie;
        rasa = _rasa;
        varsta = _varsta;
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

class Planta{

    std::string specie;
    std::string culoare;

public:
    Planta(std::string _specie, std::string _culoare = "\0"){
        specie = _specie;
        culoare = _culoare;
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

class Ecosistem{

    std::vector<Animal> animale;
    std::vector<Planta> plante;
    int umiditate;
    int temperatura;
    std::string precipitii;

public:
    Ecosistem(std::vector<Animal> _animale, std::vector<Planta> _plante,int _umiditate, int _temperatura, std::string _precipitatii): umiditate(_umiditate), temperatura(_temperatura),precipitii(_precipitatii){

        for(auto &i : _animale)
            animale.push_back(i);

        for(auto &i : _plante)
            plante.push_back(i);

    }
    Ecosistem(int _umiditate, int _temperatura, std::string _precipitatii):umiditate(_umiditate), temperatura(_temperatura),precipitii(_precipitatii){
        std::ifstream f("animale.txt");
        std::ifstream g("plante.txt");

        std::string _specie, _rasa, _culoare;
        int _varsta;

        while(f>>_specie>>_rasa>>_varsta) {
            Animal animal(_specie, _rasa, _varsta);
            animale.push_back(animal);
        }

        while(g>>_specie>>_culoare){
            Planta planta(_specie, _culoare);
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

    Ecosistem &operator=(const Ecosistem &eco){
        for(auto &i : eco.animale)
            animale.push_back(i);

        for(auto &i : eco.plante)
            plante.push_back(i);

        umiditate = eco.umiditate;
        temperatura = eco.temperatura;
        precipitii = eco.precipitii;

        return *this;
    }

    ~Ecosistem(){
        animale.~vector<Animal>();
        plante.~vector<Planta>();
    }

    void afisare(){
        std::cout<<"Animalele din ecosistem sunt:\n";
        for(auto &i:animale)
            std::cout << i.getSpecie() <<' '<<i.getRasa()<<'\n';
        std::cout<<'\n';

        std::cout<<"Plantele din ecosistem sunt:\n";
        for(auto &i:plante)
            std::cout << i.getSpecie() <<' '<<i.getCuloare()<<'\n';\

        std::cout<<'\n';

        std::cout<<"Umiditatea: "<<umiditate<<'(' << ((umiditate > 60) ? "aer suprasaturat" : (umiditate < 30 ? "aer uscat" : "aer normal"))<<")\n";

        std::cout<<"Temperatura: "<<temperatura<<" grade Celsius"<<'\n';

        std::cout<<"Precipitatii: "<<precipitii<<'\n';

        std::cout<<'\n';
    }

};

int main() {

    //Testez metodele din clasele Animal si Planta
    Animal animal1("pisica","bengaleza",6);
    Animal animal2("caine","shiba",3);
    Planta planta1("crizantema","albastra");

    std::cout<<"Primul animal: "<<animal1.getSpecie()<<' '<<animal1.getRasa()<<' '<<animal1.getVarsta()<<'\n';
    std::cout<<"Al doilea animal: "<<animal2.getSpecie()<<' '<<animal2.getRasa()<<' '<<animal2.getVarsta()<<'\n';
    std::cout<<"Planta: "<<planta1.getSpecie()<<' '<<planta1.getCuloare()<<"\n\n";

    //Construiesc 2 vectori de obiecte pentru primul constructor al clasei Ecosistem

    std::vector<Animal> animale;
    std::vector<Planta> plante;
    animale.push_back(animal1);
    animale.push_back(animal2);
    plante.push_back(planta1);

    //Testez clasa Ecosistem

    Ecosistem Gradina(animale,plante,50,24,"Ploaie");
    Ecosistem GradinaVecinului(Gradina);
    Ecosistem PadureNorvegiana(40,32,"Senin");
    Ecosistem Padure = PadureNorvegiana;

    Gradina.afisare();
    GradinaVecinului.afisare();
    Padure.afisare();
    Padure.afisare();


    return 0;
}
