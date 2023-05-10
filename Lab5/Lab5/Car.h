class Car {
    int number, cost, brand;
public:
    Car() {
        number = 0;
        cost = 0;
        brand = 0;
    }
    Car(const Car& s) {                                            //êîíñòğóêòîğ êîïèğîâàíèÿ
        this->number = s.number;
        this->cost = s.cost;
        this->brand = s.brand;
    }
    int get_brand() { return brand; }
    int get_cost() { return cost; }
    friend istream& operator>>(istream& in, Car& a) {
        cout << "Ââåäèòå íîìåğ:" << endl;
        in >> a.number;
        cout << "âûáåğèòå ìàğêó (0 - ÊÀÌÀÇ, 1 - ÁåËÀÇ, 2 - ÃÀÇ-24, 3 - Èêàğóñ, 4 - ËÈÀÇ, 5 - ĞÀÔ):" << endl;
        in >> a.brand;
        if ((a.brand < 0) || (a.brand > 5)) { cout << "íåâåğíàÿ öèôğà"; exit; }
        cout << "Ââåäèòå ñòîèìîñòü:" << endl;
        in >> a.cost;
        return (in);
    }

    friend ostream& operator<<(ostream& out, Car a) {
        out << a.number << " ";
        string brands[6] = {"ÊÀÌÀÇ", "ÁåËÀÇ", "ÃÀÇ-24", "Èêàğóñ", "ËÈÀÇ", "ĞÀÔ"};
        cout << brands[a.brand];
        cout << " " << a.cost;
        return (out);
    }

    bool operator==(Car& a) {
        if ((a.number == this->number) && (a.cost == this->cost) && (a.brand == this->brand)) {
            return true;
        }
        return false;
    }
};