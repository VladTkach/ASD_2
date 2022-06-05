#pragma once

#include <iostream>

using namespace std;


class item {
    int weight;
    int cost;

public:
    int getWeight() const;

    void setWeight(int weight);

    int getCost() const;

    void setCost(int cost);

    void showItem();
};
