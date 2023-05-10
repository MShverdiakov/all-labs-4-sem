#include "Set.h"
#include "heir.h"
#include "Car.h"

using namespace std;

int main() {

    setlocale(LC_ALL, "ru");

    int num_of_bases, num_of_cars;
    Car car;

    cout << "введите кол-во автобаз" << endl;
    cin >> num_of_bases;
    Heir<Car> h;
    Set<int>* brands_of_bases = new Set<int>[num_of_bases];
    Set<Car>* bases = new Set<Car>[num_of_bases];
    for (int i = 0; i < num_of_bases; i++) {
        cout << "введите кол-во машин на " << i << " автобазе"; cin >> num_of_cars;
        cout << "введите машины (номер, марка, стоимость)";
        for (int j = 0; j < num_of_cars; j++) {
            cin >> car;
            //cin >> car.set_number() >> car.set_brand()>> car.set_cost();
            bases[i].add_elem(car);
            brands_of_bases[i].add_elem(car.brand);
        }
    }

   h.solution(brands_of_bases, bases, num_of_bases);
}