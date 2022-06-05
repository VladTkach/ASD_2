#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Queue{
    vector<int> queue;
    vector<int> priority;

public:
//    Queue();
    ~Queue();

    void showQueue();

    //queue
    const vector<int> &getQueue() const;

    void setQueue(const vector<int> &queue);
    //Priority
    const vector<int> &getPriority() const;

    void setPriority(const vector<int> &priority);
    //Operation

    void deleteMax();

    void changePriorety(int index, int newPriorety);

    void addElement(int value, int valuePriorety);

};