#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <fstream>

using namespace std;

int main() {
    // вводим количество точек и в следующих n строках пары координат
    int n;
    int a, b; //координаты
    string filename_in;

    ifstream fin;
    cout << "Введите путь к входному файлу:\n";
    cin >> filename_in;
    fin.open(filename_in);

    fin >> n;
    float c; // расстояние
    vector<pair<float, pair<int, int>>> A; // создаем вектор пар (расстояние от центра, координаты)
    // координаты – тоже пара
    for (int i = 0; i < n; i++) {
        fin >> a >> b;
        c = a*a + b*b; // расстояние по l2 норме
        A.emplace_back(make_pair(c, make_pair(a, b)));
    }
    // создаем итераторы – начало и конец
    vector<pair<float, pair <int,int>>>::iterator iA = A.begin();
    vector<pair<float, pair <int,int>>>::iterator iAend = A.end();
    sort(iA, iAend); // сортируем по расстоянию
    iA = A.begin();
    cout << "Результат: \n";
    for (int i = 0; i<n; i++) {
        // берем второй элемент – это координаты, выводим их
        cout << (*iA).second.first << ' ' <<  (*iA).second.second;
        iA++;
        cout << '\n';
    }
    return 0;
}
