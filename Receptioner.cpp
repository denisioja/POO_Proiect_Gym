#include "Receptioner.h"

Receptioner::Receptioner(int _id_anagajat, const std::string _nume, int _varsta, int _salariu, int _nrAbonIncheiate,
                         int _nrProdVandute) : Angajat(id_angajat, nume, varsta, salariu){
    this->nrAbonIncheiate = _nrAbonIncheiate;
    this->nrProdVandute = _nrProdVandute;
}

Receptioner::Receptioner(const Receptioner &receptioner) : Angajat(id_angajat, nume, varsta, salariu){
    this->nrProdVandute = receptioner.nrProdVandute;
    this->nrAbonIncheiate = receptioner.nrAbonIncheiate;
}

Receptioner &Receptioner::operator=(const Receptioner& receptioner) {
    nrAbonIncheiate = receptioner.nrAbonIncheiate;
    nrProdVandute = receptioner.nrProdVandute;
    return *this;
}

void Receptioner::citire(std::istream &in) {
    Angajat::citire(in);

    std::cout << "Numarul de abonamente incheiate azi este: ";
    in >> nrAbonIncheiate;

    std::cout << "Numarul de produse vandute azi este: ";
    in >> nrProdVandute;
}

void Receptioner::afisare(std::ostream &out) const {
    Angajat::afisare(out );
    out << "Numarul de abonamente vandute azi este: " << nrAbonIncheiate << "\n";
    out << "Numarul de produse vandute azi este: " << nrProdVandute << "\n";
 }
