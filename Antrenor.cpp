#include "Antrenor.h"

Antrenor::Antrenor(int _id_anagajat, const std::string _nume, int _varsta, int _salariu, int _nrOameniAntr,
                   int _nrAniExperienta) : Angajat(id_angajat, nume, varsta, salariu){
    this->nrOameniAntr = _nrOameniAntr;
    this->aniExperienta = _nrAniExperienta;
}

Antrenor::Antrenor(const Antrenor &antrenor) : Angajat(id_angajat, nume, varsta, salariu){
    this->nrOameniAntr = antrenor.nrOameniAntr;
    this->aniExperienta = antrenor.aniExperienta;
}

Antrenor &Antrenor::operator=(const Antrenor &antrenor) {
    nrOameniAntr = antrenor.nrOameniAntr;
    aniExperienta = antrenor.aniExperienta;
    return *this;
}

void Antrenor::citire(std::istream &in) {
    Angajat::citire(in);

    std::cout << "Numarul de oameni antrenati este: ";
    in >> nrOameniAntr;

    std::cout << "Numarul de ani de experienta este: ";
    in >> aniExperienta;
}

void Antrenor::afisare(std::ostream &out) const {
    Angajat::afisare(out);

    out << "Numarul de oameni antrenati este: " << nrOameniAntr << "\n";
    out << "Numarul de ani de experienta este: " << aniExperienta << "\n";
}
