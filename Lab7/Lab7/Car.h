class Car {
public:
    int number, cost, brand;
    Car() {
        number = 0;
        cost = 0;
        brand = 0;
    }
    Car(const Car& s) {                                            //����������� �����������
        this->number = s.number;
        this->cost = s.cost;
        this->brand = s.brand;
    }
    friend istream& operator>>(istream& in, Car& a) {
        cout << "������� �����:" << endl;
        in >> a.number;
        cout << "�������� ����� (0 - �����, 1 - �����, 2 - ���-24, 3 - ������, 4 - ����, 5 - ���):" << endl;
        in >> a.brand;
        if ((a.brand < 0) || (a.brand > 5)) { cout << "�������� �����"; exit; }
        cout << "������� ���������:" << endl;
        in >> a.cost;
        return (in);
    }

    friend ostream& operator<<(ostream& out, Car a) {
        out << a.number << " ";
        string brands[6] = { "�����", "�����", "���-24", "������", "����", "���" };
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
//        if ((brand < 0) || (brand > 5)) { std::cout << "�������� �����"; return false; }
//        return true;
//    }
    //friend istream& operator>>(istream& in, Car& c);
	/*friend istream& operator>>(istream& in, Car& a) {
        cout << "������� �����:" << endl;
        in >> a.number;
        cout << "�������� ����� (0 - �����, 1 - �����, 2 - ���-24, 3 - ������, 4 - ����, 5 - ���):" << endl;
        in >> a.brand;
        if (!a.brand_check()) { abort; }
        cout << "������� ���������:" << endl;
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
//    Car(const Car& s) { //����������� �����������
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
    //    if ((brand < 0) || (brand > 5)) { cout << "�������� �����"; return false; }
    //    return true;
    //}
//    friend istream& operator>>(istream& in, Car& a) {
//        cout << "������� �����:" << endl;
//        in >> a.number;
//        cout << "�������� ����� (0 - �����, 1 - �����, 2 - ���-24, 3 - ������, 4 - ����, 5 - ���):" << endl;
//        in >> a.brand;
//        if (!a.brand_check()) { abort; }
//        cout << "������� ���������:" << endl;
//        in >> a.cost;
//        return (in);
//    }
//
//    friend ostream& operator<<(ostream& out, Car a) {
//        out << a.number << " ";
//        string brands[6] = { "�����", "�����", "���-24", "������", "����", "���" };
//        cout << brands[a.brand];
//        cout << " " << a.cost;
//        return (out);
//    }
//};