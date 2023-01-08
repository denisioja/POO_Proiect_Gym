#include <iostream>
#include "Client.h"

Client::Client(int _id_client, const std::string _nume, int _varsta, const std::string _tipAbon, int _nrProd, const std::vector<std::shared_ptr<Produs>> &_produse) {
    this->id_client = _id_client;
    this->nume = _nume;
    this->varsta = _varsta;
    this->tipAbon = _tipAbon;
    this->nrProd = _nrProd;
    this->produse = _produse;
}

Client::Client(const Client &client) {
    this->id_client = client.id_client;
    this->nume = client.nume;
    this->varsta = client.varsta;
    this->tipAbon = client.tipAbon;
    this->nrProd = client.nrProd;
    this->produse = client.produse;
}

Client &Client::operator=(const Client &client) {
    id_client = client.id_client;
    nume = client.nume;
    varsta = client.varsta;
    tipAbon = client.tipAbon;
    nrProd = client.nrProd;
    produse = client.produse;
    return *this;
}

std::istream &operator>>(std::istream &in, Client &client) {
    client.citire(in);
    return in;
}

std::ostream &operator<<(std::ostream &out, Client &client) {
    client.afisare(out);
    return out;
}

void Client::citire(std::istream &in) {
    std::cout << "ID_Client:";
    in >> id_client;

    std::cout << "Nume: ";
    in >> nume;

    std::cout << "Varsta: ";
    in >> varsta;

    std::cout << "Tipul de abonament: ";
    in >> tipAbon;

    std::cout << "Numarul de produse cumparate: ";
    in >> nrProd;

    if(nrProd > 0){
        std::cout << "Produse: ";
        for(int i = 0 ; i < nrProd; i++) {
            std::shared_ptr<Produs> tempProdus;
            tempProdus->citire(std::cin);
            produse.push_back(tempProdus);
        }
    }
}

void Client::afisare(std::ostream &out) const{
    out << "ID_Client: " << id_client << "\n";
    out << "Nume: " << nume << "\n";
    out << "Varsta: " << varsta << "\n";
    out << "Tipul de abonament: " << tipAbon << "\n";
    out << "Numarul de produse cumparate: " << nrProd << "\n";
    if(nrProd>0) {
        for(auto &produs : produse) {
            produs->afisare(out );
        }
    }
}

const std::string &Client::getNume() const {
    return nume;
}
