#include <iostream>
#include <string>

using namespace std;

template <class T1> class Set;
template <class T1>
istream& operator>>(istream& in, Set<T1>& s) {
    int n;
    cout << "“екущее количество оперций:";
    cin >> n;
    if (n > s.max_size) throw(1);
    else {
        in >> s.base[0];
        s.size++;
        for (int i = 1; i < n; i++) {
            bool flag = false;
            while (!flag) {
                flag = true;
                in >> s.base[i];
                s.size++;
                for (int j = 0; j < i; j++) {
                    if (s.base[i] == s.base[j]) {
                        flag = false;
                        s.size--;
                    }
                }
            }
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
        cout << "Ќикаких операций не задано }" << endl;
    }
    return out;
}
template <class T1>
class Set {
private:
    T1* base;
    int max_size, size;
public:
    friend void solution(Set<int>* brands_of_bases, Set<T1>* bases, int num_of_bases);
    friend istream& operator>><T1>(istream& in, Set<T1>& s);
    friend ostream& operator<<<T1>(ostream& out, Set<T1>& s);

    Set(int n = 10) {                                               //конструктор по умолчанию
        size = 0;
        max_size = n;
        base = new T1[max_size];
    }
    Set(const Set& s) {                                            //конструктор копировани€
        this->max_size = s.max_size;
        base = new T1[max_size];
        for (int i = 0; i < max_size; i++) base[i] = s.base[i];
        size = s.size;
    }
    ~Set() {                                                        //деструктор
        delete[] base;
        max_size = 0;
        size = 0;
    }

    T1& getElem(int i) {  //доступ к элементу множества
        return base[i];
    }

    int getSize() {  //доступ к текущему размеру множества
        return size;
    }

    int getMax_size() { //доступ к максимальному размеру множества
        return max_size;
    }

    void setMax_size(int n) {
        max_size = n;
    }

    bool check(T1 elem) { //поиск элемента
        int i = 0;
        bool flag = false;
        while ((i < size) && !(flag)) {
            if (base[i] == elem) flag = true;  //нашли - возвращаем 1
            i++;
        }
        return flag; //не нашли - возвращаем 0
    }

    void add_elem(T1 elem) {  //добавить заранее известный элемент
        if (size < max_size) {
            if (check(elem)) cout << "“ака€ марка уже есть" << endl;
            else {
                base[size] = elem;
                size++;
            }
        }
        else cout << "ћаксимально возможное количество элементов" << endl;
    }
    void add_elem_unknown() {    //добавить элемент по выбору
        T1 elem;
        cout << " акую элемент добавить?";
        cin >> elem;
        if (size < max_size) {
            if (check(elem)) cout << "“ака€ марка уже есть" << endl;
            else {
                base[size] = elem;
                size++;
            }
        }
        else cout << "ћаксимально возможное количество элементов" << endl;
    }
    void delete_elem() {   //удалить элемент из множества
        int nom;
        cout << " акую по счету операцию удалить?";
        cin >> nom;
        if (nom > size)
            cout << "“акого элемента нет" << endl;
        else {
            if (nom <= size - 1) for (int i = nom - 1; i < size - 1; i++) base[i] = base[i + 1];
            size--;
        }
    }

    bool empty() {                      //пустое ли множество
        if (size == 0) return true; //да
        else return false;  //нет
    }

    bool operator==(const Set& s) {
        if (size != s.size) return false;
        for (int i = 0; i < s.size; i++) {
            if (!check(s.base[i])) return false;
        }
        return true;
    }

    Set<T1>& operator=(const Set& s) {  //присваивание множеств
        if (max_size != s.max_size) {
            delete[] base;
            base = new T1[s.max_size];
            size = 0;
            max_size = s.max_size;
        }
        for (int i = 0; i < s.size; i++) base[i] = s.base[i];
        size = s.size;
        return *this;
    }

    Set<T1> operator*(Set& s) {   //пересечение
        int k = 0;
        if (s.size < size) {
            Set<T1> res(s.size);
            for (int i = 0; i < s.size; i++) {
                if (this->check(s.base[i])) {
                    res.base[i - k] = s.base[i];
                    res.size++;
                }
                else k++;
            }
            return res;
        }
        else {
            int k = 0;
            Set<T1> res(size);
            for (int i = 0; i < size; i++) {
                if (s.check(base[i])) {
                    res.base[i - k] = base[i];
                    res.size++;
                }
                else k++;
            }
            return res;
        }
    }
};