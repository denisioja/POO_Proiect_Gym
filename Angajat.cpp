#include "Angajat.h"

Angajat::Angajat(int _id_anagajat, const std::string _nume, int _varsta, int _salariu) {
    this->id_angajat = _id_anagajat;
    this->nume = _nume;
    this->varsta = _varsta;
    this->salariu = _salariu;
}

Angajat::Angajat(const Angajat &angajat) {
    this->id_angajat = angajat.id_angajat;
    this->nume = angajat.nume;
    this->varsta = angajat.varsta;
    this->salariu = angajat.salariu;
}

Angajat &Angajat::operator=(const Angajat &angajat) {
    id_angajat = angajat.id_angajat;
    nume = angajat.nume;
    varsta = angajat.varsta;
    salariu = angajat.salariu;
    return *this;
}

std::istream &operator>>(std::istream &in, Angajat &angajat) {
    angajat.citire(in);
    return in;
}

std::ostream &operator<<(std::ostream &out, Angajat &angajat) {
    angajat.afisare(out);
    return out;
}

void Angajat::citire(std::istream &in) {
    std::cout << "ID_Angajat: ";
    std::cin >> id_angajat;

    std::cout << "Nume: ";
    std::cin >> nume;

    std::cout << "Varsta: ";
    std::cin >> varsta;

    std::cout << "Salariu: ";
    std::cin >> salariu;
}

void Angajat::afisare(std::ostream &out) const {
    std::cout << "ID_Angajat: " << id_angajat << "\n";
    std::cout << "Numele: " << nume << "\n";
    std::cout << "Varsta: " << varsta << "\n";
    std::cout << "Salariu: " << salariu << "\n";
}

int Angajat::getSalariu() const {
    return salariu;
}
