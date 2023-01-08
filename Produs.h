#ifndef POO_TEMA2_PRODUS_H
#define POO_TEMA2_PRODUS_H

#include <string>

class Produs{
private:
    std::string denumire;
    int pret;
    int cantitate;
public:
    Produs() = default;
    ~Produs() = default;

    Produs(const std::string _denumire, int _pret, int _cantitate);
    Produs(const Produs &produs);
    Produs & operator=(const Produs &produs);

    friend std::istream& operator>>(std::istream &in, Produs &produs);
    friend std::ostream& operator<<(std::ostream &out, Produs &produs);

    virtual void citire(std::istream &in);
    virtual void afisare(std::ostream &out) const;
};

#endif //POO_TEMA2_PRODUS_H
