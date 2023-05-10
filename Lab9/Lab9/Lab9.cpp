#include <iostream>
#include <list>

using namespace std;

struct Video_lib {
    string name;
    float cost;
    string director;
};

istream &operator>>(istream& in, Video_lib& data) {
    cout << "Введите название, стоимость и режиссера\n";
    in >> data.name >> data.cost >> data.director;
    return in;
}

ostream& operator<<(ostream& out, Video_lib& data) {
    cout << "\nназвание "; out << data.name;
    cout << "\nстоимость "; out << data.cost;
    cout << "\nрежиссер "; out << data.director;
    cout << endl;
    return out;
}

list<Video_lib> v_lib_input(list<Video_lib> vl, int n) {
    cout << "введите фильмы для видеотеки\n";
    Video_lib temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        vl.push_back(temp);
    }
    return vl;
}

void v_lib_output(list<Video_lib> &vl) {
    //list<Video_lib>::iterator it = vl.begin();
    for (list<Video_lib>::iterator it = vl.begin(); it != vl.end(); it++)
        cout << *it;
}

void v_lib_get_director(list<Video_lib> &vl, int random) {
    list<Video_lib>::iterator it = vl.begin();
    while (random--) ++it;
    string dir = it->director;
    cout << "все найденные фильмы режиссера " << dir;
    for (list<Video_lib>::iterator it = vl.begin(); it != vl.end(); it++)
        if (it->director == dir) cout << *it;
}

int main() {
    setlocale(LC_ALL, "Russian");
    list<Video_lib> vl;
    cout << "введите кол-во фильмов\n";
    int n; cin >> n;
    vl = v_lib_input(vl, n);
    cout << "картотека видеотеки\n";
    //v_lib_output(vl);
    
    int r = rand() % (n - 1);
    v_lib_get_director(vl, r);
}