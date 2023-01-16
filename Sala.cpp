#include <algorithm>
#include "Sala.h"
#include "Receptioner.h"
#include "Antrenor.h"

Sala::Sala(const std::string _denumire, int _nrAngajati, int _nrClienti, int _nrProduse, int _nrAparatura, std::vector<std::shared_ptr<Angajat>> &_angajati, std::vector<std::shared_ptr<Client>> &_clienti, std::vector<std::shared_ptr<Aparatura>> &_aparatura,
           std::vector<std::shared_ptr<Produs>> &_produse) {
    this->nrAngajati = _nrAngajati;
    this->nrClienti = _nrClienti;
    this->nrAparatura = _nrAparatura;
    this->nrProduse = _nrProduse;
    this->denumire = _denumire;
    this->angajati = _angajati;
    this->clienti = _clienti;
    this->aparatura = _aparatura;
    this->produse = _produse;
}

Sala::Sala(const Sala &sala) {
    this->denumire = sala.denumire;
    this->nrAngajati = sala.nrAngajati;
    this->nrClienti = sala.nrClienti;
    this->nrAparatura = sala.nrAparatura;
    this->nrProduse = sala.nrProduse;
    this->denumire = sala.denumire;
    this->angajati = sala.angajati;
    this->clienti = sala.clienti;
    this->aparatura = sala.aparatura;
    this->produse = sala.produse;

}

Sala &Sala::operator=(const Sala &sala) {
    denumire = sala.denumire;
    nrAngajati = sala.nrAngajati;
    nrClienti = sala.nrClienti;
    nrAparatura = sala.nrAparatura;
    nrProduse = sala.nrProduse;
    angajati = sala.angajati;
    clienti = sala.clienti;
    aparatura = sala.aparatura;
    produse = sala.produse;
    return *this;
}

std::istream &operator>>(std::istream &in, Sala &sala) {
    sala.citire(in);
    return in;
}

std::ostream &operator<<(std::ostream &out, Sala &sala) {
    sala.afisare(out);
    return out;
}

void Sala::citire(std::istream &in) {
    std::cout << "Denumire: ";
    in >> denumire;

    std::cout << "Numar angajati: ";
    in >> nrAngajati;
    for(int i = 0; i < nrAngajati; i++){
        std::shared_ptr<Angajat> tempAngajat;
        unsigned int optiune, cond = 0;
        while(cond == 0){
            std::cout << "Ocupatie angajat (1-receptioner, 2-antrenor): ";
            std::cin >> optiune;
            cond = 1;
            try {
                if(optiune < 1 || optiune > 2) {
                    throw optiune;
                }
                if(optiune == 1)
                    tempAngajat = std::make_shared<Receptioner>();
                else tempAngajat = std:: make_shared<Antrenor>();
                tempAngajat->citire(std::cin);
                angajati.push_back(tempAngajat);
            }
            catch (...) {
                std::cout << "Eroare: Optiune invalida!\n";
                cond = 0;
            }
        }

        std::cout << "Numar clienti: ";
        in >> nrClienti;
        for(int i = 0; i < nrClienti; i++) {
            std::shared_ptr<Client> tempClient = std::make_shared<Client>();
            //make_shared_ptr daca e
            //shared_ptr e pentru clase care au derivate
            tempClient->citire(std::cin);
            clienti.push_back(tempClient);
        }

        std::cout << "Numar aparatura: ";
        in >> nrAparatura;
        for(int i = 0; i<nrAparatura; i++) {
            std::shared_ptr<Aparatura> tempApara = std::make_shared<Aparatura>();
            tempApara->citire(std::cin);
            aparatura.push_back(tempApara);
        }

        std::cout << "Numar produse: ";
        in >> nrProduse;
        for(int i = 0; i < nrProduse; i++) {
            std::shared_ptr<Produs> tempProd = std::make_shared<Produs>();
            tempProd->citire(std::cin);
            produse.push_back(tempProd);
        }
    }
}

void Sala::afisare(std::ostream &out) const {
    out << "Denumire: " << denumire << "\n";
    out << "Angajati:\n";
    for(auto &angajat : angajati) {
        angajat->afisare(out);
    }
    out << "Clienti:\n";
    for(auto &client : clienti) {
        client->afisare(out);
    }
    out << "Aparatura:\n";
    for(auto &aparat : aparatura) {
        aparat->afisare(out);
    }
    out << "Produse:\n";
    for(auto &produs : produse) {
        produs->afisare(out);
    }
}

void Sala::meniu() {

}

void Sala::adaugareClient() {
    unsigned int nrClienti;
    std::cout << "Numarul de clienti este: ";
    std::cin >> nrClienti;
    for(int i = 0 ; i <nrClienti ; i++) {
        std::shared_ptr<Client> tempClient;
        tempClient->citire(std::cin);
        clienti.push_back(tempClient);
    }
}

void Sala::adaugareAngajat() {
    unsigned int nrAngajati;
    std::cout << "Numarul de angajati este: ";
    std::cin >> nrAngajati;
    for(int i = 0; i < nrAngajati; i++) {
        unsigned int optiune, conditie = 0;
        std::shared_ptr<Angajat> tempAngajat;
        while(conditie == 0) {
            std::cout << "Tip angajat (1-Receptioer, 2-Antrenor): ";
            std::cin >> optiune;
            conditie = 1;
            try {
                switch(optiune) {
                    case 1: {
                        tempAngajat = std::make_shared<Receptioner>();
                        break;
                    }
                    case 2: {
                        tempAngajat = std::make_shared<Antrenor>();
                        break;
                    }
                    default: {
                        throw optiune;
                    }
                }
                tempAngajat->citire(std::cin);
                angajati.push_back(tempAngajat);
            }
            catch(...) {
                std::cout << "Eroare: Optiune invalida!\n";
                conditie = 0;
            }
        }
    }
}

void Sala::afisareClienti() {
    for(auto &client : clienti) {
        client->afisare(std::cout);
    }
}

void Sala::afisareAngajati() {
    for(auto &angajat : angajati) {
        angajat->afisare(std::cout);
    }
}

void Sala::cautaClient(const std::string &numeClient) {
    std::size_t gasit;
    for(auto &client : clienti) {
        gasit = client->getNume().find(numeClient);
        if(gasit != std::string::npos) {
            client->afisare(std::cout);
        }
    }
}

void Sala::ordonareAngajatiSalariu() {
    std::sort(angajati.begin(), angajati.end(), [](const std::shared_ptr<Angajat> &a, const std::shared_ptr<Angajat> &b) -> bool {
        return a->getSalariu() > b->getSalariu();
    });
    afisareAngajati();
}

void Sala::raportAngajati() {
    int nrAngajati = 0;
    int recept = 0, antren = 0;
    for(auto &angajat : angajati) {
        if(std::dynamic_pointer_cast<Receptioner>(angajat)) {
            recept++;
        }
        if(std::dynamic_pointer_cast<Antrenor>(angajat)) {
            antren++;
        }
        nrAngajati++;
    }
    std::cout << "Numarul total de angajati este: " << nrAngajati << "dintre care " << recept << " sunt receptioeri si " << antren << " sunt antrenori\n";
}

