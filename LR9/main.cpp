#include "func.h"
#include "item.h"

int main() {
    const string fileName = "input.txt";
    int max_weight, num_element;
    getSize(fileName, max_weight, num_element);

    vector<item> listItem = getListItem(fileName, num_element);
    outList(listItem);

    int **mas = new int *[num_element];
    init_mas(mas, num_element, max_weight);

    dynamic(listItem, mas, num_element, max_weight);

    cout << mas[num_element - 1][max_weight - 1];

    delete_mas(mas, num_element);
    return 0;
}
