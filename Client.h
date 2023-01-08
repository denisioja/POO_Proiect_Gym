#ifndef POO_TEMA2_CLIENT_H
#define POO_TEMA2_CLIENT_H

#include <string>
#include <memory>
#include <vector>
#include "Produs.h"

class Client{
private:
    int id_client;
    std::string nume;
    int varsta;
    std::string tipAbon;
    int nrProd;
    std::vector<std::shared_ptr<Produs>> produse;
public:
    Client() = default;
    ~Client() = default;

    Client(int _id_client, const std::string _nume, int _varsta, const std::string _tipAbon, int _nrProd, const std::vector<std::shared_ptr<Produs>> &_produse);
    Client(const Client &client);
    Client & operator=(const Client &client);

    friend std::istream& operator>>(std::istream &in, Client &client);
    friend std::ostream& operator<<(std::ostream &out, Client &client);

    virtual void citire(std::istream &in);
    virtual void afisare(std::ostream &out) const;

    const std::string &getNume() const;
};

#endif //POO_TEMA2_CLIENT_H
