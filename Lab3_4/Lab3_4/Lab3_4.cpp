#include "Complex.h"
#include "Set.h"

int main() {

    setlocale(LC_ALL, "ru");

    try {
        int max_size1, max_size2, kof, k1, k2;

        cout << "Размер первого множества:";
        cin >> max_size1;
        Set<complex<int>> set1(max_size1);
        cin >> set1;
        cout << set1;

        cout << "Размер второго множества:";
        cin >> max_size2;
        Set<complex<int>> set2(max_size2);
        cin >> set2;
        cout << set2;
        do {
            cout << "1 - добавить элемент" << endl;
            cout << "2 - удалить элемент" << endl;
            cout << "3 - объединение" << endl;
            cout << "4 - пересечение" << endl;
            cout << "0 - выход" << endl;
            cin >> kof;

            switch (kof) {
            case 1: {
                cout << "С каким множеством работать? 1 или 2?" << endl;
                cin >> k1;
                switch (k1) {
                case 1: {
                    set1.add_elem();
                    cout << set1;
                    break;
                }
                case 2: {
                    set2.add_elem();
                    cout << set2;
                    break;
                }
                }
                break;
            }
            case 2: {
                cout << "С каким множеством работать? 1 или 2?" << endl;
                cin >> k2;
                switch (k2) {
                case 1: {
                    set1.delete_elem();
                    cout << set1;
                    break;
                }
                case 2: {
                    set2.delete_elem();
                    cout << set2;
                    break;
                }
                }
                break;
            }
            case 3: {
                cout << "set1 + set2:" << endl;
                Set<complex<int>> res1;
                res1 = set1 + set2;
                cout << res1;
                break;
            }
            case 4: {
                cout << "set1 * set2: " << endl;
                Set<complex<int>> res2;
                res2 = set1 * set2;
                cout << res2;
                break;
            }
            }
        } while (kof != 0);
    }
    catch (int code) {
        if (code == 1)
            cout << "Количество элементов больше допустимого значения" << endl;
    }
}