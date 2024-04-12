#include <iostream>
#include <cmath>
using namespace std;
class point {
private:
    double x, y;
public:
    point(double x = 0, double y = 0) : x(x), y(y) {}
    ~point() {}
    double gx() const { return x; }
    double gy() const { return y; }
    friend double prod(const point& p1, const point& p2, const point& p3, const point& p4);
};

class card {
private:
    string name;
    int amount;
public:
    card(string name = "", double amount = 0) : name(name), amount(amount) {}
    ~card() {}
    string gn() const { return name; }
    double gp() const { return amount; }
};

double prod(const point& p1, const point& p2, const point& p3, const point& p4)
{
    if ((abs(p1.gx() - p3.gx()) * abs(p1.gy() - p3.gy())) == (abs(p2.gx() - p4.gx()) * abs(p2.gy() - p4.gy())))
    {
        return abs(p1.gx() - p3.gx()) * abs(p1.gy() - p3.gy());
    }
    else; return 0;
}

double dist(const point& p1, const point& p2)
{
    double dx = p1.gx() - p2.gx();
    double dy = p1.gy() - p2.gy();
    return sqrt(dx * dx + dy * dy);
}

int main() {
    setlocale(LC_ALL, "Rus");
    int choice;
    while (true)
    {
        cout << "\nМеню:" << endl;
        cout << "1) Прямоугольник(6x8) " << endl;
        cout << "2) Информация по прямоугольнику(ввод с клавиатуры) " << endl;
        cout << "3) Вывести количество карт без поездок" << endl;
        cout << "4) Выход" << endl;
        cout << "\nВведите свой выбор: ";
        cin >> choice;
        while (cin.fail()) {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Ошибка! Введите число согласно номеру в меню: ";
            cin >> choice;
        }
        switch (choice) {
        case 1: {
            point* points = new point[4];
            points[0] = point(0, 0);
            points[1] = point(0, 6);
            points[2] = point(8, 6);
            points[3] = point(8, 0);
            double side1 = dist(points[0], points[1]);
            double side2 = dist(points[1], points[2]);
            double side3 = dist(points[2], points[3]);
            double side4 = dist(points[3], points[0]);
            double diagonal = dist(points[0], points[2]);
            double d = prod(points[0], points[1], points[2], points[3]);

            cout << "\nПроизведение: " << d << endl;
            cout << "Стороны: " << side1 << ", " << side2 << ", " << side3 << ", " << side4 << endl;
            cout << "Диагональ: " << diagonal << endl;
            delete[] points;
            break;

        }
        case 2: {
            point* points = new point[4];
            cout << "\nВведите точки, сообветствующие координатам углов тпрямоугольника" << endl;
            for (int i = 0; i < 4; i++) {
                double x, y;
                cout << "Введите координаты точки(x y) " << i + 1 << ": ";
                cin >> x >> y;
                points[i] = point(x, y);
            }
            double side1 = dist(points[0], points[1]);
            double side2 = dist(points[1], points[2]);
            double side3 = dist(points[2], points[3]);
            double side4 = dist(points[3], points[0]);
            double diagonal = dist(points[0], points[2]);
            double d = prod(points[0], points[1], points[2], points[3]);
            if (d == 0) {
                cout << "\nОшибка, введенные точки не соответствуют координатам прямоугольника" << endl;
                cout << "Вы возвращены в Меню" << endl;
                break;
            }
            else {
                cout << "Стороны: " << side1 << ", " << side2 << ", " << side3 << ", " << side4 << endl;
                cout << "\nПроизведение: " << d << endl;
                cout << "Диагональ: " << diagonal << endl;
                delete[] points;
                break;
            }
        }
        case 3: {
            card cards[6] = {
            card("карта N1", 0),
            card("карта N2", 0),
            card("карта N3", 0),
            card("карта N4", 30),
            card("карта N5", 0),
            card("карта N6", 60)
            };
            double amount = 0;

            for (int i = 0; i < 6; i++) {
                if (cards[i].gp() == 0) {
                    amount++;

                }
            }
            cout << "\nКолиество карт без поездок: " << ": " << amount << endl;
            break;
        }

        case 4: {
            exit(0);
        }
        default: {
            cout << "\nНеверный выбор. Попробуйте ещё раз." << endl;
            break;
        }
        }
    }
    return 0;
}