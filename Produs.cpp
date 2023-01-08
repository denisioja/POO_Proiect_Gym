#include <iostream>
#include "Produs.h"

Produs::Produs(const std::string _denumire, int _pret, int _cantitate) {
    this->denumire = _denumire;
    this->pret = _pret;
    this->cantitate = _cantitate;
}

Produs::Produs(const Produs &produs) {
    this->denumire = produs.denumire;
    this->pret = produs.pret;
    this->cantitate = produs.cantitate;
}

Produs &Produs::operator=(const Produs &produs) {
    denumire = produs.denumire;
    pret = produs.pret;
    cantitate = produs.cantitate;
    return *this;
}

std::istream &operator>>(std::istream &in, Produs &produs) {
    produs.citire(in);
    return in;
}

std::ostream &operator<<(std::ostream &out, Produs &produs) {
    produs.afisare(out);
    return out;
}

void Produs::citire(std::istream &in) {
    std::cout << "Denumirea: ";
    in >> denumire;

    std::cout << "Pretul: ";
    in >> pret;

    std::cout << "Cantitatea(g): ";
    in >> cantitate;
}

void Produs::afisare(std::ostream &out) const {
    out << "Denumirea: " << denumire << "\n";
    out << "Pretul: " << pret << "\n";
    out << "Cantitea(g): " << cantitate << "\n";
}
