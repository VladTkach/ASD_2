#include "func.h"
#include "queue.h"

int main() {
    Queue A;
    A.showQueue();
    A.addElement(10, 10);
    A.addElement(9, 9);
    A.addElement(9, 10);
    A.addElement(30, 123);
    A.showQueue();
    A.changePriorety(2, 130);
    A.showQueue();

    A.deleteMax();
    A.showQueue();
    return 0;
}
