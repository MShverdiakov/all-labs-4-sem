#include <iostream> // у меня 16 вариант
#include <conio.h>

using namespace std;

template <class T>
class Complex {
    T x, y; // действительная и мнимая часть

public:
    friend istream& operator >> (istream& in, Complex& i) { // перегрузка ввода
        in >> i.x >> i.y;
        return in;
    }

    friend ostream& operator << (ostream& out, Complex& i) { // перегрузка вывода
        out << i.x << " + i" << i.y;
        return out;
    }

    Complex(T x = T(0), T y = T(0)) { this->x = x; this->y = y; }

    void set(T a, T b) { // установить комплексное число
        x = a;
        y = b;
    }

    void print() { // показать комплексное число
        cout << x << " + " << y << "i" << endl;
    }

    int operator%(Complex i) {
        if ((i.x == 0) && (i.y == 0)) {
            cout << "ERROR: division by zero";
            exit;
        }
        if ((x % i.x == 0) && (y % i.y == 0))
            return 0;
        else
            return 1;
    }

    bool operator==(Complex i) { // сравнение
        if ((x == i.x) && (y == i.y))
            return true;
        else
            return false;
    }

    Complex<T> operator+(Complex<T> x) { // сложение
        Complex<T> res;
        res.x = this->x + x.x;
        res.y = this->y + x.y;
        return res;
    }

    Complex<T> operator+(double x) { // сложение
        Complex<T> res;
        res.x = this->x + x;
        res.y = this->y;
        return res;
    }

    Complex<T> operator-(Complex<T> x) { // сложение
        Complex<T> res;
        res.x = this->x - x.x;
        res.y = this->y - x.y;
        return res;
    }

    Complex<T> operator-(double x) { // сложение
        Complex<T> res;
        res.x = this->x - x;
        res.y = this->y;
        return res;
    }

    Complex<T> operator*(Complex<T> x) { // сложение
        Complex<T> res;
        res.x = this->x * x.x - this->y * x.y;
        res.y = this->x * x.y + this->y * x.x;
        return res;
    }

    T get_x() {		// функция ссылочного типа
        return x;
    }

    T get_y() {
        return y;
    }

    bool check() {   // проверка отрицательны ли мнимая и действительная части числа
        if ((this->x < 0) && (this->y < 0))
            return true;
        else
            return false;
    }

    double module() {       // взятие модуля
        double res;
        res = sqrt(x * x + y * y);
        return res;
    }
};