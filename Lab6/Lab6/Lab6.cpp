#include "Set.h"
#include "Car.h"

void solution(Set<int>* brands_of_bases, Set<Car>* bases, int num_of_bases) {
    bool flag = false;
    for (int i = 0; i < num_of_bases; i++) {
        for (int j = 0; (j < num_of_bases) && (i != j); j++) {
            if (brands_of_bases[i] == brands_of_bases[j]) {
                cout << j << "-ая автобаза";
                cout << bases[j] << endl;
                cout << i << "-ая автобаза";
                cout << bases[i] << endl;
                int sum = 0;
                for (int k = 0; k < bases[i].size; k++) sum += bases[i].base[k].cost + bases[j].base[k].cost;
                cout << "сумма " << sum;
                flag = true;
            }
        }
    }
    if (!flag) cout << "нет одинаковых";
}

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
            cin >> car.number >> car.brand >> car.cost;
            bases[i].add_elem(car);
            brands_of_bases[i].add_elem(car.brand);
        }
    }
    
    solution(brands_of_bases, bases, num_of_bases);
}