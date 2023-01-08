#ifndef POO_TEMA2_APARATURA_H
#define POO_TEMA2_APARATURA_H

#include <string>

class Aparatura{
private:
    std::string denumire;
    int nrBuc;
public:
    Aparatura() = default;
    ~Aparatura() = default;

    Aparatura(const std::string _denumire, int _nrBuc);
    Aparatura(const Aparatura &aparatura);
    Aparatura & operator= (const Aparatura &aparatura);

    friend std::istream& operator>>(std::istream&, Aparatura& aparatura);
    friend std::ostream& operator<<(std::ostream&, Aparatura& aparatura);

    virtual void citire(std::istream &in);
    virtual void afisare(std::ostream &out);
};

#endif //POO_TEMA2_APARATURA_H
