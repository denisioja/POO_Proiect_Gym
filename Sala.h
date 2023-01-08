#ifndef POO_TEMA2_SALA_H
#define POO_TEMA2_SALA_H

#include <string>
#include <memory>
#include <vector>
#include "Angajat.h"
#include "Client.h"
#include "Aparatura.h"

class Sala {
private:
    std::string denumire;
    int nrAngajati;
    int nrClienti;
    int nrProduse;
    int nrAparatura;
    std::vector<std::shared_ptr<Angajat>> angajati;
    std::vector<std::shared_ptr<Client>> clienti;
    std::vector<std::shared_ptr<Aparatura>> aparatura;
    std::vector<std::shared_ptr<Produs>> produse;
public:
    Sala() = default;
    virtual ~Sala() = default;

    Sala(const std::string _denumire, int _nrAngajati, int _nrClienti, int _nrProduse, int _nrAparatura, std::vector<std::shared_ptr<Angajat>> &_angajati, std::vector<std::shared_ptr<Client>> &_clienti, std::vector<std::shared_ptr<Aparatura>> &aparatura, std::vector<std::shared_ptr<Produs>> &_produse);
    Sala(const Sala &sala);
    Sala & operator=(const Sala &sala);

    friend std::istream& operator>>(std::istream& in, Sala& sala);
    friend std::ostream& operator<<(std::ostream& out, Sala& sala);

    virtual void  citire(std::istream& in);
    virtual void afisare(std::ostream& out) const;

    static void meniu();
    void adaugareClient();
    void adaugareAngajat();
    void afisareClienti();
    void afisareAngajati();
    void cautaClient(const std::string& numeClient);
    void ordonareAngajatiSalariu();
    void raportAngajati();
};

#endif //POO_TEMA2_SALA_H
