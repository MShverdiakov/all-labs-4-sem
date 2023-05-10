class Car {
public:
    int number, cost, brand;
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
        string brands[6] = { "ÊÀÌÀÇ", "ÁåËÀÇ", "ÃÀÇ-24", "Èêàğóñ", "ËÈÀÇ", "ĞÀÔ" };
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

//class Car {
//	int number, cost, brand;
//public:
//	Car() {
//		number = 0;
//		cost = 0;
//		brand = 0;
//	}
//	int get_number() { return number; }
//	int get_cost() { return cost; }
//	int get_brand() { return brand; }
//	int set_number(int x) { number = x; }
//	int set_cost(int x) { cost = x; }
//	int set_brand(int x) { brand = x; }
//    bool brand_check() {
//        if ((brand < 0) || (brand > 5)) { std::cout << "íåâåğíàÿ öèôğà"; return false; }
//        return true;
//    }
    //friend istream& operator>>(istream& in, Car& c);
	/*friend istream& operator>>(istream& in, Car& a) {
        cout << "Ââåäèòå íîìåğ:" << endl;
        in >> a.number;
        cout << "âûáåğèòå ìàğêó (0 - ÊÀÌÀÇ, 1 - ÁåËÀÇ, 2 - ÃÀÇ-24, 3 - Èêàğóñ, 4 - ËÈÀÇ, 5 - ĞÀÔ):" << endl;
        in >> a.brand;
        if (!a.brand_check()) { abort; }
        cout << "Ââåäèòå ñòîèìîñòü:" << endl;
        in >> a.cost;
        return (in);
    }*/
//};


//class Car {
//    int number, cost, brand;
//public:
//    Car() {
//        number = 0;
//        cost = 0;
//        brand = 0;
//    }
//    Car(const Car& s) { //êîíñòğóêòîğ êîïèğîâàíèÿ
//        this->number = s.number;
//        this->cost = s.cost;
//        this->brand = s.brand;
//    }
//    bool operator==(Car& a) {
//        if ((a.number == this->number) && (a.cost == this->cost) && (a.brand == this->brand)) {
//            return true;
//        };
//        return false;
//    }
    //bool brand_check() {
    //    if ((brand < 0) || (brand > 5)) { cout << "íåâåğíàÿ öèôğà"; return false; }
    //    return true;
    //}
//    friend istream& operator>>(istream& in, Car& a) {
//        cout << "Ââåäèòå íîìåğ:" << endl;
//        in >> a.number;
//        cout << "âûáåğèòå ìàğêó (0 - ÊÀÌÀÇ, 1 - ÁåËÀÇ, 2 - ÃÀÇ-24, 3 - Èêàğóñ, 4 - ËÈÀÇ, 5 - ĞÀÔ):" << endl;
//        in >> a.brand;
//        if (!a.brand_check()) { abort; }
//        cout << "Ââåäèòå ñòîèìîñòü:" << endl;
//        in >> a.cost;
//        return (in);
//    }
//
//    friend ostream& operator<<(ostream& out, Car a) {
//        out << a.number << " ";
//        string brands[6] = { "ÊÀÌÀÇ", "ÁåËÀÇ", "ÃÀÇ-24", "Èêàğóñ", "ËÈÀÇ", "ĞÀÔ" };
//        cout << brands[a.brand];
//        cout << " " << a.cost;
//        return (out);
//    }
//};