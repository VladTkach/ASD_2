#include "item.h"

int item::getWeight() const {
    return weight;
}

void item::setWeight(int weight) {
    item::weight = weight;
}

int item::getCost() const {
    return cost;
}

void item::setCost(int cost) {
    item::cost = cost;
}

void item::showItem() {
    cout << weight << " " << cost << endl;
}
