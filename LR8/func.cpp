#include "func.h"

int getVertex(string name) {
    ifstream inFile(name);
    string line;
    getline(inFile, line);
    inFile.close();
    return stoi(line);
}

void init_mas(int **mas, int row, int col) {
    for (int i = 0; i < row; ++i) {
        mas[i] = new int[col];
    }
}

void init_mas(double **mas, int row, int col) {
    for (int i = 0; i < row; ++i) {
        mas[i] = new double [col];
    }
}

void delete_mas(int **mas, int row) {
    for (int i = 0; i < row; ++i) {
        delete[]mas[i];
    }
    delete[]mas;
}

void delete_mas(double **mas, int row) {
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

void out_mas(double **mas, int row, int col) {
    cout << endl;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cout << mas[i][j] << " ";
        }
        cout << endl;
    }
}

void in_coor(string name, int **coor, int vertex) {
    ifstream inFile(name);
    string line;
    getline(inFile, line);

    int x, y, space;

    for (int i = 0; i < vertex; ++i) {
        getline(inFile, line);
        space = line.find(' ', 0);
        x = stoi(line.substr(0, space));
        y = stoi(line.substr(space, line.length() - space));

        coor[i][0] = x;
        coor[i][1] = y;
    }

    inFile.close();
}

double distance(int x1, int y1, int x2, int y2) {
    double distance = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    return distance;
}

void in_graph(double **graph, int **coor, int vertex) {
    int  x1, y1;
    const int x2 = 0, y2 = 1;
    for (int i = 0; i < vertex; ++i) {
        x1 = coor[i][x2];
        y1 = coor[i][y2];
        for (int j = 0; j < vertex; ++j) {
            if (i == j) {
                graph[i][j] = 0;
            } else {
                graph[i][j] = distance(x1, y1, coor[j][x2], coor[j][y2]);
            }
        }
    }
}

void greed(double **graph, int vertex, int &min, vector<int> &total_comb){
    vector<int> comb;
    comb.push_back(0);
    search_comb(vertex, comb, graph, min, total_comb);
    total_comb.push_back(0);
}

void search_comb(int vertex, vector<int> comb, double **graph, int &min, vector<int> &total_comb){
    if (comb.size() == vertex){
        int sum = find_dir(comb, graph);
        if (sum < min){
            min = sum;
            total_comb = comb;
        }
        return;
    }
    vector<int> new_comb = comb;
        for (int i = 1; i < vertex; ++i) {
            if (no_repeat(i, new_comb)){
                new_comb.push_back(i);
                search_comb(vertex, new_comb, graph, min, total_comb);
                new_comb.pop_back();
            }

        }
}

void comb_output(vector<int> comb){
    for (int i = 0; i < comb.size(); ++i) {
        cout << comb[i] << " ";
    }
    cout << endl;
}

bool no_repeat(int index, vector<int> comb){
    for (int i = 0; i < comb.size(); ++i) {
        if (comb[i] == index){
            return false;
        }
    }
    return true;
}

double find_dir(vector<int> comb, double **graph){
    comb.push_back(0);
    double sum = 0;
    for (int i = 0; i < comb.size() - 1; ++i) {
        sum += graph[comb[i]][comb[i + 1]];
    }
    return sum;
}

void writeResult(string name, int min, vector<int> &comb) {
    ofstream outFile(name);
    outFile << min << "\n";
    for (int i = 0; i < comb.size(); ++i) {
        outFile << comb[i] << " ";
    }
    outFile.close();
}

