template <class T1>
class Set {
private:
    T1* base;
    int max_size, size;
public:
    friend istream& operator>><T1>(istream& in, Set<T1>& s);
    friend ostream& operator<<<T1>(ostream& out, Set<T1>& s);

    Set(int n = 0) {                                               //конструктор по умолчанию
        size = 0;
        max_size = n;
        base = new T1[max_size];
    }
    Set(const Set& s) {                                            //конструктор копирования
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

    bool check(T1 elem) { //поиск элемента
        int i = 0;
        bool flag = false;
        while ((i < size) && !(flag)) {
            if (base[i] == elem) flag = true;  //нашли - возвращаем 1
            i++;
        }
        return flag; //не нашли - возвращаем 0
    }

    void add_elem() {
        T1 elem;
        cout << "Какой элемент добавить?";
        cin >> elem;
        if (size < max_size) {
            if (check(elem)) cout << "Такой элемент уже есть" << endl;
            else {
                base[size] = elem;
                size++;
            }
        }
        else cout << "Множество заполнено" << endl;
    }
    void delete_elem() {
        int nom;
        cout << "Какой по счету элемент удалить?";
        cin >> nom;
        if (nom > size)
            cout << "Такого элемента нет" << endl;
        else {
            if (nom <= size - 1) for (int i = nom - 1; i < size - 1; i++) base[i] = base[i + 1];
            //base[size - 1] = T1(0);
            size--;
        }
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
    Set<T1> operator+(Set& s) {   // объединение
        int k = 0;
        Set<T1> res(size + s.size);
        for (int i = 0; i < size; i++) {
            res.base[i] = base[i];
            res.size++;
        }
        for (int i = size; i < s.size + size; i++) {
            if (!(this->check(s.base[i - size]))) {
                res.base[i - k] = s.base[i - size];
                res.size++;
            }
            else k++;
        }
        return res;
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