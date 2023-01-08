#include <iostream>
#include "Aparatura.h"

Aparatura::Aparatura(const std::string _denumire, int _nrBuc) {
    this->denumire = _denumire;
    this->nrBuc = _nrBuc;
}

Aparatura::Aparatura(const Aparatura &aparatura) {
    this->denumire = aparatura.denumire;
    this->nrBuc = aparatura.nrBuc;
}

Aparatura &Aparatura::operator=(const Aparatura &aparatura) {
    denumire = aparatura.denumire;
    nrBuc = aparatura.nrBuc;
    return *this;
}

std::istream &operator>>(std::istream &in, Aparatura &aparatura) {
    aparatura.citire(in);
    return in;
}

std::ostream &operator<<(std::ostream &out, Aparatura &aparatura) {
    aparatura.afisare(out);
    return out;
}

void Aparatura::citire(std::istream &in) {
    std::cout << "Denumirea: ";
    in >> denumire;

    std::cout << "Numar bucati: ";
    in >> nrBuc;
}

void Aparatura::afisare(std::ostream &out) {
    out << "Denumirea: " << denumire << "\n";
    out << "Numar bucati: " << nrBuc << "\n";
}


