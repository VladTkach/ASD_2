#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>

using namespace std;

void getSize(string name, int &users, int &films);

void init_mas(int **mas, int row, int col);

void delete_mas(int **mas, int row);

void out_mas(int **mas, int row, int col);

vector<string> split_line(string line);

void in_base(string name, int **mas, int users, int films);

bool is_num(string num);

int inversion(int *mas, int size);

void comparison(int **base, int users, int films, int **result, int x);

void get_mas(int *mas1, int *mas2, int films, int *res_mas);

void sort_mas(int **result, int users);

void write_result(int **result, int users, string name, int x);

int main() {
    srand(time(NULL));
    int users, films;
    getSize("input.txt", users, films);
//    cout << users << " " << films << endl;

    int **base = new int *[users];
    init_mas(base, users, films);

    in_base("input.txt", base, users, films);
//    out_mas(base, users, films);

    int **result = new int *[users];
    init_mas(result, users, 2);

    int x = rand() % users + 1;
//    cout << x << endl;

    comparison(base, users, films, result, x);
//    out_mas(result, users, 2);


    sort_mas(result, users);
//    out_mas(result, users, 2);

    write_result(result, users, "outout.txt", x);

    delete_mas(base, users);
    delete_mas(result, users);
    return 0;
}

void getSize(string name, int &users, int &films) {
    ifstream inFile(name);
    string line;
    getline(inFile, line);
    int space = line.find(' ', 0);
    users = stoi(line.substr(0, space));
    films = stoi(line.substr(space, line.length() - space));
    inFile.close();
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

void in_base(string name, int **mas, int users, int films) {
    ifstream inFile(name);
    string line;
    int user;
    getline(inFile, line);
    for (int i = 0; i < users; ++i) {
        getline(inFile, line);
        vector<string> s_line = split_line(line);
        user = stoi(s_line[0]);
        for (int j = 0; j < films; ++j) {
            if (is_num(s_line[j + 1])) {
                mas[user - 1][j] = stoi(s_line[j + 1]);
            } else {
                cout << "Error: " << i << j << endl;
            }
        }
    }
    inFile.close();
}

vector<string> split_line(string line) {
    vector<string> s_list;
    int left_pos = 0, right_pos;
    while (right_pos != -1) {
        right_pos = line.find(' ', left_pos);
        s_list.push_back(line.substr(left_pos, right_pos - left_pos));
        left_pos = right_pos + 1;
    }
    return s_list;
}

bool is_num(string num) {
    for (int i = 0; i < num.length(); ++i) {
        if (num[i] < 48 || num[i] > 57) {
            return false;
        }
    }
    return true;
}

int inversion(int *mas, int size) {
    int sum = 0;
    for (int i = size - 1; i >= 1; --i) {
        for (int j = i - 1; j >= 0; --j) {

            if (mas[i] < mas[j]) {
                sum++;
            }
        }
    }
    return sum;
}

void comparison(int **base, int users, int films, int **result, int x) {
    int *mas = new int[films];
    int inver;
    for (int i = 0; i < users; ++i) {
        if(i != x - 1){
            get_mas(base[x - 1], base[i], films, mas);
            inver = inversion(mas, films);
//            cout << i + 1 << " " << inver << endl;
            result[i][0] = i + 1;
            result[i][1] = inver;
        }
        else{
            result[i][0] = i + 1;
            result[i][1] = -1;
        }
    }
}

void get_mas(int *mas1, int *mas2, int films, int *res_mas){
    for (int i = 0; i < films; ++i) {
        for (int j = 0; j < films; ++j) {
            if (mas1[i] == mas2[j]){
                res_mas[i] = j + 1;
            }
        }
    }
}

void sort_mas(int **result, int users){
    for (int i = 1; i < users; ++i) {
        for (int j = 0; j < users - i; ++j) {
            if (result[j][1] > result[j + 1][1]){
                int temp_u = result[j][0];
                int temp_i = result[j][1];

                result[j][0] = result[j + 1][0];
                result[j][1] = result[j + 1][1];

                result[j + 1][0] = temp_u;
                result[j + 1][1] = temp_i;
            }
        }
    }
}

void write_result(int **result, int users, string name, int x){
    ofstream outFile(name);
    outFile << x << "\n";
    for (int i = 1; i < users; ++i) {
        outFile << result[i][0] << " " << result[i][1] << "\n";
    }
    outFile << x << "\n";
    outFile.close();
}
