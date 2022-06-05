#include "queue.h"


Queue::~Queue() noexcept {
    queue.clear();
    priority.clear();
}
void Queue::showQueue() {
    for (int i = 0; i < queue.size(); ++i) {
        cout << queue[i] << "-(" << priority[i] << ") ";
    }
    cout << endl;
}

const vector<int> &Queue::getQueue() const {
    return queue;
}

void Queue::setQueue(const vector<int> &queue) {
    Queue::queue = queue;
}

const vector<int> &Queue::getPriority() const {
    return priority;
}

void Queue::setPriority(const vector<int> &priority) {
    Queue::priority = priority;
}

void Queue::deleteMax() {
    queue.pop_back();
    priority.pop_back();
}

void Queue::addElement(int value, int valuePriorety) {
    if (priority.empty()) {
        queue.push_back(value);
        priority.push_back(valuePriorety);
    } else if (valuePriorety <= priority[0]) {
        queue.insert(queue.begin(), value);
        priority.insert(priority.begin(), valuePriorety);
    } else if (valuePriorety >= priority[priority.size() - 1]) {
        queue.insert(queue.end(), value);
        priority.insert(priority.end(), valuePriorety);
    } else {


        for (int i = 0; i < priority.size() - 1; ++i) {
            if (valuePriorety >= priority[i] && valuePriorety <= priority[i + 1]) {
                queue.insert(queue.begin() + i, value);
                priority.insert(priority.begin() + i, valuePriorety);
                break;
            }
        }
    }

}

void Queue::changePriorety(int index, int newPriorety) {
    if (index >= queue.size()) {
        cout << "Error";
    } else {
        int temp_value = queue[index];
        queue.erase(queue.begin() + index);
        priority.erase(priority.begin() + index);

        addElement(temp_value, newPriorety);
    }

}