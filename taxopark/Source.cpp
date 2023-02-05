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
		cout << "1. Имя: " << endl; cin >> first_name;
		cout << "2. Фамилия: " << endl; cin >> second_name;
		cout << "3. Отчество: " << endl; cin >> third_name;
		cout << "4. Серия паспорта: " << endl; cin >> series_pass;
		cout << "5. Номер паспорта: " << endl; cin >> number_pass;
		cout << "6. Телефон: " << endl; cin >> phone;
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
		cout << "Водитель c ID: " << ID_driver << endl;
		cout << "-----------------" << endl;
		cout << "- Фамилия: " << second_name << " -Имя: " << first_name << " -Отчество: " << third_name << endl;
		cout << "- Серия паспорта: " << series_pass << " - Номер паспорта: " << number_pass << " - Телефон: " << phone << endl;
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
		cout << "1. Номер машины: "; cin >> number;
		cout << "2. Цвет машины(0-белый,1-серый,2-красный, 3-синий, 4-черный, 5-желтый, 6-оранжевый,7-зеленый): "; cin >> _col;
		cout << "3. Модель машины(0-WPolo,1-HSolaris,2-SkodaOctavia,3-RenLogan: "; cin >> _mod;
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
		case 0: col = "белый"; break;
		case 1: col = "серый"; break;
		case 2: col = "красный"; break;
		case 3: col = "синий"; break;
		case 4: col = "чёрный"; break;
		case 5: col = "жёлтый"; break;
		case 6: col = "оранжевый"; break;
		case 7: col = "зелёный"; break;
		}
		switch (model) {
		case 0: mod = "WPolo"; break;
		case 1: mod = "Hyundai Solaris"; break;
		case 2: mod = "Skoda Octavia"; break;
		case 3: mod = "Renault Logan"; break;
		}
		cout << "Номер машины: " << number << endl;
		cout << "Цвет машины: " << col << endl;
		cout << "Модель машины: " << mod << endl;
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
		case 0: statuss = "Отменён"; break;
		case 1: statuss = "Выполняется"; break;
		case 2: statuss = "Завершён"; break;
		}
		cout << "ID заказа - " << ID_order << " | " << "Статус: " << statuss << endl;
		cout << "Откуда: " << from << " | " << "Куда: " << to << endl;
		cout << "Стоимость заказа: " << price_order << endl;
		cout << "ID водителя - " << id_driver << endl;
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
		cout << "Заголовок отзыва: "; cin >> header;
		cout << "Текст отзыва: "; cin >> text;
		cout << "Поставьте оценку службы такси(от 0 до 5) "; cin >> value;
		cout << "Отправить отзыв? y-да, n-нет: "; cin >> agree;
		if (agree == 'y') {
			cout << "Вы успешно отправили отзыв!" << endl;
		}
	}
	void display() {
		cout << header << endl;
		cout << "-----------" << endl;
		cout << text << endl;
		cout << "Оценка: " << value << endl;
	}
	~reviews() {
		cout << "Отзыв удалён/отменён" << endl;
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
	cars[0].setter("А700АУ", grey, WPolo);
	cars[1].setter("Г542ВЛ", black, HSolaris);
	cars[2].setter("В3456МО", red, SkodaOctavia);
	cars[3].setter("М855ХД", green, RenLogan);
	int sizec = 4, sized = 4;
	driver* drivers = new driver[50];
	drivers[0].setter("Петр", "Иванов", "Алексеевич", 5848, 485842, "89439564652"); drivers[0].set_ID(3536);
	drivers[1].setter("Иван", "Алексеев", "Иванович", 6493, 987643, "89552648572"); drivers[1].set_ID(5734);
	drivers[2].setter("Алексей", "Петров", "Петрович", 4353, 485842, "89542457931"); drivers[2].set_ID(7834);
	drivers[3].setter("Максим", "Булгаков", "Игоревич", 4385, 439852, "89347713471"); drivers[3].set_ID(3847);
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
		cout << "Клиент:\n1)Заказать такси\n2)Написать отзыв\n--------------\nДисп.служба:\n3)Вывод данных о машинах\n4)Просмотр статусов и данных заказов\n5)Вывод данных о водителях\n6)Поиск заказа\n7)Просмотр выручки\n8)Добавить водителя и машину\n9)Просмотреть отзывы\n--------------" << endl;
		cin >> choise;
		switch (choise)
		{
		case 1:
			if (i_cars > sizec || i_cars > sized) {
				cout << "Свободных машин нет. Приносим извинения" << endl;
				break;
			}
			cout << "Откуда забрать: "; cin >> from;
			cout << "Куда отвезти: "; cin >> to;
			orders[i_orders].set_id_order(ID_order);
			orders[i_orders].setter(from, to);
			orders[i_orders].get_status(Performed);
			srand(static_cast<unsigned int>(time(0)));
			price_order = 50 + rand() % 400;
			times = 3 + rand() % 10;
			orders[i_orders].generation_price(price_order);
			cout << "Стоимость заказа: " << price_order << " рублей" << " | Примерное время ожидания: " << times << " минут" << endl;
			cout << "Оформлять заказ? y - да, n - нет: "; cin >> agree;
			if (agree = 'y') {
				srand(static_cast<unsigned int>(time(0)));
				random_shuffle(free_cars.begin(), free_cars.end());
				temp = free_cars.back();
				phone = drivers[i_cars].get_phone();
				iddr = drivers[i_cars].get_ID();
				orders[i_orders].set_id_driver(iddr);
				cout << "Ваш заказ с ID: " << orders[i_orders].get_id() << endl;
				temp.displayinfocars();
				cout << "Номер телефона водителя: " << phone << endl;
				cout << "-------------------" << endl;
				cout << "Прошло примерно " << times << " минут" << endl;
				cout << "Вас отвезли, Вы заплатили " << price_order << " рублей, поблагодарили водителя и ушли.." << endl;
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
			cout << "Введите ID заказа: "; cin >> find_id_order;
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
				cout << "Заказа с таким ID не существует." << endl;
			break;
		case 7:
			cout << "Выручка с такси составляет: " << kassa << endl;
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
		cout << "Повторить? y - да, n - нет: "; cin >> choise2;
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