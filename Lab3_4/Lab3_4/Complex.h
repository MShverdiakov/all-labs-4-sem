#include <iostream>
#include <string>

using namespace std;

template<typename T>
class complex {
public:

    T real;
    T image;

    complex() {
        real = 0;
        image = 0;
    }
    T& g_real() {
        return real;
    }
    T& g_image() {
        return image;
    }

    friend istream& operator>>(istream& in, complex& a) {
        cout << "Введите действительную часть числа:" << endl;
        in >> a.real;
        cout << "Введите мнимую часть числа:" << endl;
        in >> a.image;
        return (in);
    }

    friend ostream& operator<<(ostream& out, complex a) {
        out << a.real << "+i" << a.image;
        return (out);
    }

    bool operator==(complex& a) {
        if (sqrt(pow(real, 2) + pow(image, 2)) == sqrt(pow(a.real, 2) + pow(a.image, 2))) {
            return true;
        }
        return false;
    }

    complex& operator= (T i) {

        real = i;
        image = i;

        return *this;
    }
};

template <class T1> class Set;
template <class T1>
istream& operator>>(istream& in, Set<T1>& s) {
    int n;
    cout << "Введите множество (максимальный размер = " << s.max_size << "):" << endl;
    cout << "Количество элементов:";
    cin >> n;
    if (n > s.max_size) throw(1);
    else {
        for (int i = 0; i < n; i++) {
            in >> s.base[i];
            s.size++;
        }
    }
    return in;
}

template<typename T1>
ostream& operator <<(ostream& out, Set<T1>& s) {
    out << "{ ";
    if (s.size != 0) {
        for (int i = 0; i < s.size - 1; i++)
            out << s.base[i] << ", ";
        out << s.base[s.size - 1] << " }" << endl;
    }
    else {
        cout << "Пустое множество" << endl;
    }
    return out;
}