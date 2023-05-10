template <class T1>
class Heir: public Set<T1> {
public:
    //Heir() : Set() {};
    void solution(Set<int>* brands_of_bases, Set<T1>* bases, int num_of_bases) {
        bool flag = false;
        for (int i = 0; i < (num_of_bases - 1); i++) {
            if (brands_of_bases[i] == brands_of_bases[i + 1]) {
                cout << i << "-ая автобаза";
                cout << bases[i] << endl;
                cout << i + 1 << "-ая автобаза";
                cout << bases[i + 1] << endl;
                int sum = 0, j;
                for (int j = 0; j < bases[i].getSize(); j++) 
                    sum += bases[i].getElem(j).cost + bases[i + 1].getElem(j).cost;
                cout << "сумма " << sum;
                flag = true;
            }
        }
        if (!flag) cout << "нет одинаковых";
    }
};