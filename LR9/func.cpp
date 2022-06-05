#include "func.h"

void getSize(const string &name, int &max_weight, int &num_element) {
    ifstream inFile(name);
    string line;
    getline(inFile, line, ' ');
    max_weight = stoi(line);
    getline(inFile, line);
    num_element = stoi(line);
    inFile.close();
}

vector<item> getListItem(const string &name, int num_element) {
    vector<item> listItem;
    listItem.resize(num_element);
    ifstream inFile(name);
    string line;
    getline(inFile, line);
    for (int i = 0; i < num_element; ++i) {
        getline(inFile, line);
        int space = line.find(' ', 0);
        listItem[i].setCost(stoi(line.substr(0, space)));
        listItem[i].setWeight(stoi(line.substr(space, line.length() - space)));
    }
    inFile.close();
    return listItem;
}

void outList(vector<item> listItem) {
    for (int i = 0; i < listItem.size(); ++i) {
        listItem[i].showItem();
    }
}

void init_mas(int **mas, int row, int col) {
    for (int i = 0; i < row; ++i) {
        mas[i] = new int[col];
    }
}

void delete_mas(int **mas, int row) {
    for (int i = 0; i < row; ++i) {
        delete[]mas[i];
    }
    delete[]mas;
}

void out_mas(int **mas, int row, int col) {
    cout << endl;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cout << mas[i][j] << " ";
        }
        cout << endl;
    }
}

void dynamic(vector<item> &listItem, int **mas, int num_element, int max_weight) {
    for (int i = 0; i < num_element; ++i) {
        int weight = listItem[i].getWeight();
        int cost = listItem[i].getCost();
        for (int j = 0; j < max_weight; ++j) {
            if (i == 0) {
                mas[i][j] = 0;
            } else if (j >= weight) {
                mas[i][j] = max(mas[i - 1][j], mas[i - 1][j - weight] + cost);
            } else {
                mas[i][j] = mas[i - 1][j];
            }
        }
    }
}
