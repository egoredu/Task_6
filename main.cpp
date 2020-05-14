#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
    // вводим количество точек и в следующих n строках пары координат
    int n;
    int a, b; //координаты
    cin >> n;
    float c; // расстояние
    vector<pair<float, pair<int, int>>> A; // создаем сет, в котором будут пары (расстояние от центра, координаты)
    // координаты – тоже пара
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        c = a*a + b*b; // расстояние по l2 норме
        A.push_back(make_pair(c, make_pair(a, b)));
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
