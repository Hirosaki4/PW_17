#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
using namespace std;

struct Perevezennya {
    static int total_perevezennya; // Статична змінна для підрахунку перевезень

    string vanтаж;
    string маршрут;
    double відстань;
    double вага;

    // Конструктор
    Perevezennya(string van, string mar, double vid, double vag)
        : vanтаж(van), маршрут(mar), відстань(vid), вага(vag) {
        total_perevezennya++;
    }

    // Гетери
    string getVanтаж() const { return vanтаж; }
    string getМаршрут() const { return маршрут; }
    double getВідстань() const { return відстань; }
    double getВага() const { return вага; }

    // Сетери
    void setVanтаж(string van) { vanтаж = van; }
    void setМаршрут(string mar) { маршрут = mar; }
    void setВідстань(double vid) { відстань = vid; }
    void setВага(double vag) { вага = vag; }

    // Метод для оптимізації маршруту за допомогою рекурсії
    static double optimizeRoute(vector<double> distances, int index = 0) {
        if (index == distances.size() - 1)
            return distances[index];
        return distances[index] + optimizeRoute(distances, index + 1);
    }

    // Виведення інформації про перевезення
    void displayInfo() const {
        cout << "Вантаж: " << vanтаж << endl;
        cout << "Маршрут: " << маршрут << endl;
        cout << "Відстань: " << відстань << " км" << endl;
        cout << "Вага: " << вага << " кг" << endl;
    }
};

// Ініціалізація статичної змінної
int Perevezennya::total_perevezennya = 0;

int main() {
    SetConsoleOutputCP(1251);  
    SetConsoleCP(1251);         

    // Створення кількох перевезень
    Perevezennya p1("Товари A", "Київ-Львів", 540.5, 1000);
    Perevezennya p2("Товари B", "Львів-Одеса", 810.0, 1200);

    p1.displayInfo();
    p2.displayInfo();

    cout << "Загальна кількість перевезень: " << Perevezennya::total_perevezennya << endl;

    // Оптимізація маршруту
    vector<double> distances = { 540.5, 810.0, 420.3 };
    double total_distance = Perevezennya::optimizeRoute(distances);
    cout << "Загальна оптимізована відстань: " << total_distance << " км" << endl;

    return 0;
}
