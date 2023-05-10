#include "Set.h"
#include "Car.h"

int main() {

    setlocale(LC_ALL, "ru");

    int num_of_bases, num_of_cars;
    Car car;

    cout << "введите кол-во автобаз" << endl;
    cin >> num_of_bases;
    Set<int>* brands_of_bases = new Set<int>[num_of_bases];
    Set<Car>* bases = new Set<Car>[num_of_bases];
    for (int i = 0; i < num_of_bases; i++) {
        cout << "введите кол-во машин на " << i << " автобазе"; cin >> num_of_cars;
        cout << "введите машины (номер, марка, стоимость)";
        for (int j = 0; j < num_of_cars; j++) {
            cin >> car;
            bases[i].add_elem(car);
            brands_of_bases[i].add_elem(car.get_brand());
        }
    }
    bool flag = false;
    for (int i = 0; i < (num_of_bases - 1); i++) {
        if (brands_of_bases[i] == brands_of_bases[i + 1]) { 
            cout << i << "-ая автобаза";
            cout << bases[i];
            cout << i + 1 << "-ая автобаза";
            cout << bases[i + 1];
            int sum = 0, j;
            for (int j = 0; j < bases[i].getSize(); j++) sum += bases[i].getElem(j).get_cost() + bases[i + 1].getElem(j).get_cost();
            cout << "сумма " << sum;
            flag = true;
        }
    }
    if (!flag) cout << "нет одинаковых";

}