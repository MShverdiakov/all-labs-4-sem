#include <iostream>
#include <string>

using namespace std;

template <class T1> class Set;
template <class T1>
istream& operator>>(istream& in, Set<T1>& s) {
    int n;
    cout << "������� ���������� �������:";
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
        cout << "������� �������� �� ������ }" << endl;
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

    Set(int n = 10) {                                               //����������� �� ���������
        size = 0;
        max_size = n;
        base = new T1[max_size];
    }
    Set(const Set& s) {                                            //����������� �����������
        this->max_size = s.max_size;
        base = new T1[max_size];
        for (int i = 0; i < max_size; i++) base[i] = s.base[i];
        size = s.size;
    }
    ~Set() {                                                        //����������
        delete[] base;
        max_size = 0;
        size = 0;
    }

    T1& getElem(int i) {  //������ � �������� ���������
        return base[i];
    }

    int getSize() {  //������ � �������� ������� ���������
        return size;
    }

    int getMax_size() { //������ � ������������� ������� ���������
        return max_size;
    }

    void setMax_size(int n) {
        max_size = n;
    }

    bool check(T1 elem) { //����� ��������
        int i = 0;
        bool flag = false;
        while ((i < size) && !(flag)) {
            if (base[i] == elem) flag = true;  //����� - ���������� 1
            i++;
        }
        return flag; //�� ����� - ���������� 0
    }

    void add_elem(T1 elem) {  //�������� ������� ��������� �������
        if (size < max_size) {
            if (check(elem)) cout << "����� ����� ��� ����" << endl;
            else {
                base[size] = elem;
                size++;
            }
        }
        else cout << "����������� ��������� ���������� ���������" << endl;
    }
    void add_elem_unknown() {    //�������� ������� �� ������
        T1 elem;
        cout << "����� ������� ��������?";
        cin >> elem;
        if (size < max_size) {
            if (check(elem)) cout << "����� ����� ��� ����" << endl;
            else {
                base[size] = elem;
                size++;
            }
        }
        else cout << "����������� ��������� ���������� ���������" << endl;
    }
    void delete_elem() {   //������� ������� �� ���������
        int nom;
        cout << "����� �� ����� �������� �������?";
        cin >> nom;
        if (nom > size)
            cout << "������ �������� ���" << endl;
        else {
            if (nom <= size - 1) for (int i = nom - 1; i < size - 1; i++) base[i] = base[i + 1];
            size--;
        }
    }

    bool empty() {                      //������ �� ���������
        if (size == 0) return true; //��
        else return false;  //���
    }

    bool operator==(const Set& s) {
        if (size != s.size) return false;
        for (int i = 0; i < s.size; i++) {
            if (!check(s.base[i])) return false;
        }
        return true;
    }

    Set<T1>& operator=(const Set& s) {  //������������ ��������
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

    Set<T1> operator*(Set& s) {   //�����������
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