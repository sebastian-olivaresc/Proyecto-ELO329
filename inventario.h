#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <vector>
#include <string>


using namespace std;

class Item;

class Inventario {
private:
    vector<Item*> *inventario;

public:
    void addItem(Item *item);
    Item *usar(string item);
};

#endif // INVENTARIO_H
