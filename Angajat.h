#ifndef POO_TEMA2_ANGAJAT_H
#define POO_TEMA2_ANGAJAT_H

#include <iostream>
#include <string>

class Angajat{
protected:
    int id_angajat{};
    std::string nume;
    int varsta{};
    int salariu{};
public:
    Angajat() = default;
    virtual ~Angajat() = default;

    Angajat(int _id_anagajat,  const std::string _nume, int _varsta, int _salariu);
    Angajat(const Angajat& angajat);
    Angajat & operator = (const Angajat& angajat);

    friend std::istream& operator>>(std::istream&, Angajat& angajat);
    friend std::ostream& operator<<(std::ostream&, Angajat& angajat);

    virtual void citire(std::istream &in);
    virtual void afisare(std::ostream &out) const;

    int getSalariu() const;

};

#endif //POO_TEMA2_ANGAJAT_H
