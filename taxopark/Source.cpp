#include <iostream>
#include <locale.h>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
using namespace std;

enum colors { white, grey, red, blue, black, yellow, orange, green};
enum models { WPolo, HSolaris, SkodaOctavia, RenLogan};
enum status_order { Canceled, Performed, Completed };

class driver
{
	string first_name;
	string second_name;
	string third_name;
	unsigned int series_pass;
	unsigned int number_pass;
	string phone;
	unsigned int ID_driver;
public:
	void add_driver()
	{
		cout << "1. ���: " << endl; cin >> first_name;
		cout << "2. �������: " << endl; cin >> second_name;
		cout << "3. ��������: " << endl; cin >> third_name;
		cout << "4. ����� ��������: " << endl; cin >> series_pass;
		cout << "5. ����� ��������: " << endl; cin >> number_pass;
		cout << "6. �������: " << endl; cin >> phone;
		cout << "-------------";
		srand(static_cast<unsigned int>(time(0)));
		ID_driver = rand() % 8000;
	}
	void setter(string fn, string sn, string tn, int sp, int np, string ph) {
		first_name = fn; second_name = sn; third_name = tn;
		series_pass = sp; number_pass = np; phone = ph;
	}
	void set_ID(int id) {
		ID_driver = id;
	}
	int get_ID() {
		return ID_driver;
	}
	void display() {
		cout << "�������� c ID: " << ID_driver << endl;
		cout << "-----------------" << endl;
		cout << "- �������: " << second_name << " -���: " << first_name << " -��������: " << third_name << endl;
		cout << "- ����� ��������: " << series_pass << " - ����� ��������: " << number_pass << " - �������: " << phone << endl;
		cout << "-----------" << endl;
	}
	string get_phone() {
		return phone;
	}
};
class car 
{
	friend class driver;
	string number;
	colors color; 
	models model; 
	string col, mod;
	int _col, _mod; 
public:
	void setter(string n, colors c, models m) {
		number = n;
		color = c;
		model = m;
	}
	void add_car() {
		cout << "1. ����� ������: "; cin >> number;
		cout << "2. ���� ������(0-�����,1-�����,2-�������, 3-�����, 4-������, 5-������, 6-���������,7-�������): "; cin >> _col;
		cout << "3. ������ ������(0-WPolo,1-HSolaris,2-SkodaOctavia,3-RenLogan: "; cin >> _mod;
		cout << "--------------" << endl;
		switch (_col) {
		case 0: color = white; break;
		case 1: color = grey; break;
		case 2: color = red; break;
		case 3: color = blue; break;
		case 4: color = black; break;
		case 5: color = yellow; break;
		case 6: color = orange; break;
		case 7: color = green; break;
		}
		switch (_mod) {
		case 0: model = WPolo; break;
		case 1: model = HSolaris; break;
		case 2: model = SkodaOctavia; break;
		case 3: model = RenLogan; break;
		}
	}
	string get_number() {
		return number;
	}
	colors get_color() {
		return color;
	}
	models get_model() {
		return model;
	}
	void displayinfocars() {
		switch (color) {
		case 0: col = "�����"; break;
		case 1: col = "�����"; break;
		case 2: col = "�������"; break;
		case 3: col = "�����"; break;
		case 4: col = "������"; break;
		case 5: col = "�����"; break;
		case 6: col = "���������"; break;
		case 7: col = "������"; break;
		}
		switch (model) {
		case 0: mod = "WPolo"; break;
		case 1: mod = "Hyundai Solaris"; break;
		case 2: mod = "Skoda Octavia"; break;
		case 3: mod = "Renault Logan"; break;
		}
		cout << "����� ������: " << number << endl;
		cout << "���� ������: " << col << endl;
		cout << "������ ������: " << mod << endl;
		cout << "------------" << endl;
	}
};
class order
{
	string from;
	string to; 
	unsigned int price_order;
	status_order status;
	string statuss;
	int ID_order;
	int id_driver;
public:
	void setter(string fr, string t) {
		from = fr;
		to = t;
	}
	void display() {
		switch (status) {
		case 0: statuss = "������"; break;
		case 1: statuss = "�����������"; break;
		case 2: statuss = "��������"; break;
		}
		cout << "ID ������ - " << ID_order << " | " << "������: " << statuss << endl;
		cout << "������: " << from << " | " << "����: " << to << endl;
		cout << "��������� ������: " << price_order << endl;
		cout << "ID �������� - " << id_driver << endl;
		cout << "------------" << endl;
	}
	void generation_price(int po) {
		price_order = po;
	}
	void get_status(status_order so) {
		status = so;
	}
	int get_id() {
		return ID_order;
	}
	void set_id_driver(int id) {
		id_driver = id;
	}
	void set_id_order(int id) {
		ID_order = id;
	}
};
class reviews
{
	string header; 
	string text;
	unsigned short int value;
	char agree;
public:
	void setter() {
		cout << "��������� ������: "; cin >> header;
		cout << "����� ������: "; cin >> text;
		cout << "��������� ������ ������ �����(�� 0 �� 5) "; cin >> value;
		cout << "��������� �����? y-��, n-���: "; cin >> agree;
		if (agree == 'y') {
			cout << "�� ������� ��������� �����!" << endl;
		}
	}
	void display() {
		cout << header << endl;
		cout << "-----------" << endl;
		cout << text << endl;
		cout << "������: " << value << endl;
	}
	~reviews() {
		cout << "����� �����/������" << endl;
	}
};

int main(void)
{
	setlocale(LC_ALL, "RUS");
	int choise;
	int ID_order = 7600;
	int find_id_order;
	bool check_find;
	char agree;
	string from, to, phone, col, mod;
	int iddr;
	int kassa = 0;
	unsigned int price_order,times;
	vector<car>::iterator iter;
	int i_orders = 0, i_cars = 0, i_reviews = 0;
	car* cars = new car[50];
	cars[0].setter("�700��", grey, WPolo);
	cars[1].setter("�542��", black, HSolaris);
	cars[2].setter("�3456��", red, SkodaOctavia);
	cars[3].setter("�855��", green, RenLogan);
	int sizec = 4, sized = 4;
	driver* drivers = new driver[50];
	drivers[0].setter("����", "������", "����������", 5848, 485842, "89439564652"); drivers[0].set_ID(3536);
	drivers[1].setter("����", "��������", "��������", 6493, 987643, "89552648572"); drivers[1].set_ID(5734);
	drivers[2].setter("�������", "������", "��������", 4353, 485842, "89542457931"); drivers[2].set_ID(7834);
	drivers[3].setter("������", "��������", "��������", 4385, 439852, "89347713471"); drivers[3].set_ID(3847);
	vector<car>free_cars;
	car temp;
	free_cars.push_back(cars[0]);
	free_cars.push_back(cars[1]);
	free_cars.push_back(cars[2]);
	free_cars.push_back(cars[3]);
	colors color; models model; string number;
	order* orders = new order[500];
	reviews* rev = new reviews[500];
	while (1) {
		cout << "������:\n1)�������� �����\n2)�������� �����\n--------------\n����.������:\n3)����� ������ � �������\n4)�������� �������� � ������ �������\n5)����� ������ � ���������\n6)����� ������\n7)�������� �������\n8)�������� �������� � ������\n9)����������� ������\n--------------" << endl;
		cin >> choise;
		switch (choise)
		{
		case 1:
			if (i_cars > sizec || i_cars > sized) {
				cout << "��������� ����� ���. �������� ���������" << endl;
				break;
			}
			cout << "������ �������: "; cin >> from;
			cout << "���� �������: "; cin >> to;
			orders[i_orders].set_id_order(ID_order);
			orders[i_orders].setter(from, to);
			orders[i_orders].get_status(Performed);
			srand(static_cast<unsigned int>(time(0)));
			price_order = 50 + rand() % 400;
			times = 3 + rand() % 10;
			orders[i_orders].generation_price(price_order);
			cout << "��������� ������: " << price_order << " ������" << " | ��������� ����� ��������: " << times << " �����" << endl;
			cout << "��������� �����? y - ��, n - ���: "; cin >> agree;
			if (agree = 'y') {
				srand(static_cast<unsigned int>(time(0)));
				random_shuffle(free_cars.begin(), free_cars.end());
				temp = free_cars.back();
				phone = drivers[i_cars].get_phone();
				iddr = drivers[i_cars].get_ID();
				orders[i_orders].set_id_driver(iddr);
				cout << "��� ����� � ID: " << orders[i_orders].get_id() << endl;
				temp.displayinfocars();
				cout << "����� �������� ��������: " << phone << endl;
				cout << "-------------------" << endl;
				cout << "������ �������� " << times << " �����" << endl;
				cout << "��� �������, �� ��������� " << price_order << " ������, ������������� �������� � ����.." << endl;
				orders[i_orders].get_status(Completed);
				kassa += price_order;
				i_cars++; i_orders++; ID_order++;
			}
			else {
				orders[i_orders].get_status(Canceled);
				ID_order++;
			}
			break;
		case 2:
			rev[i_reviews].setter();
			i_reviews++;
			break;
		case 3:
			for (int k = 0; k < sizec; k++) {
				cars[k].displayinfocars();
			}
			break;
		case 4:
			for (int k = 0; k < i_orders; k++) {
				orders[k].display();
			}
			break;
		case 5:
			for (int k = 0; k < sized;k++) {
				drivers[k].display();
			}
			break;
		case 6:
			cout << "������� ID ������: "; cin >> find_id_order;
			for (int k = 0; k < i_orders; k++) {
				if (find_id_order == orders[k].get_id()) {
					orders[k].display();
					check_find = true;
					break;
				}
				else {
					check_find = false;
				}
			}
			if (check_find == false)
				cout << "������ � ����� ID �� ����������." << endl;
			break;
		case 7:
			cout << "������� � ����� ����������: " << kassa << endl;
			break;
		case 8:
			cars[sizec].add_car();
			drivers[sized].add_driver();
			free_cars.push_back(cars[sizec]);
			sizec++; sized++;
			break;
		case 9:
			for (int k = 0; k < i_reviews; k++) {
				rev[k].display();
			}
			break;
		default:
			break;
		}
		char choise2;
		cout << "���������? y - ��, n - ���: "; cin >> choise2;
		if (choise2 == 'y') {
			system("pause");
			continue;
		}
		else {
			break;
		}
	}
	system("pause");
	return 0;
}