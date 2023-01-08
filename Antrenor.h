#ifndef POO_TEMA2_ANTRENOR_H
#define POO_TEMA2_ANTRENOR_H

#include "Angajat.h"

class Antrenor : public Angajat{
private:
    int nrOameniAntr{};
    int aniExperienta{};
public:
    Antrenor() = default;
    ~Antrenor() override= default;

    Antrenor(int _id_anagajat,  const std::string _nume, int _varsta, int _salariu, int _nrOameniAntr, int _nrAniExperienta);
    Antrenor(const Antrenor &antrenor);
    Antrenor & operator=(const Antrenor &antrenor);

    void citire(std::istream &in) override;
    void afisare(std::ostream &out) const override;
};

#endif //POO_TEMA2_ANTRENOR_H
