#ifndef POO_TEMA2_RECEPTIONER_H
#define POO_TEMA2_RECEPTIONER_H

#include "Angajat.h"

class Receptioner : public Angajat {
private:
    int nrAbonIncheiate;
    int nrProdVandute;
public:
    Receptioner() = default;
    ~Receptioner() override = default;

    Receptioner(int _id_anagajat,  const std::string _nume, int _varsta, int _salariu, int _nrAbonIncheiate, int _nrProdVandute);
    Receptioner(const Receptioner &receptioner);
    Receptioner & operator=(const Receptioner& receptioner);

    void citire(std::istream &in) override;
    void afisare(std::ostream &out) const override;
};

#endif //POO_TEMA2_RECEPTIONER_H
