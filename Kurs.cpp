#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>
#include <fstream>

using namespace std;

struct TRAIN {
	string destination;
	int number;
	int hours;
	int minutes;
};

struct List {
	List *next;
	List *prev;
	TRAIN TheTrain;
};

int check(int z);
int checkHou(int z);
int checkMin(int z);
int checkTr(int z, List *&Start);
void Add(TRAIN TheTrain, List *&Start, List *&End);
void Sort(TRAIN TheTrain, List *&Start);
void Search(TRAIN TheTrain, List *&Start);
void PrintTablet(TRAIN TheTrain, List *&Start);
void Read(TRAIN TheTrain, List *&Start, List *&End);
void ReadHelp(TRAIN TheTrain, List *&Start, List *&End);
void Record(TRAIN TheTrain, List *&Start);
List *Delete(TRAIN TheTrain, List *&Start);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	List *Start = NULL;
	List *End = NULL;
	TRAIN TheTrain;
	int MenuChose;
	cout << "Добавление - 1" << endl << "Удаление - 2" << endl << "Сортировка - 3" << endl << "Поиск - 4" << endl << "Вывод на экран - 5" << endl 
		<< "Чтение БД - 6" << endl << "Запись в БД - 7" << endl << "Выход - 0" << endl << "Введите цифру для выбора необходимого действия" << endl;
	cin >> MenuChose;
	MenuChose = check(MenuChose);
	while (MenuChose != 0) {
		switch (MenuChose) {
		case 1: {
			Add(TheTrain, Start, End);
			cout << "Добавление - 1" << endl << "Удаление - 2" << endl << "Сортировка - 3" << endl << "Поиск - 4"
				<< endl << "Вывод на экран - 5" << endl << "Чтение БД - 6" << endl << "Запись в БД - 7"
				<< endl << "Выход - 0" << endl << "Введите цифру для выбора необходимого действия" << endl;
			cin >> MenuChose;
			break;
		}
		case 2: {
			Delete(TheTrain, Start);
			cout << "Добавление - 1" << endl << "Удаление - 2" << endl << "Сортировка - 3" << endl << "Поиск - 4"
				<< endl << "Вывод на экран - 5" << endl << "Чтение БД - 6" << endl << "Запись в БД - 7"
				<< endl << "Выход - 0" << endl << "Введите цифру для выбора необходимого действия" << endl;
			cin >> MenuChose;
			break;
		}
		case 3: {
			Sort(TheTrain, Start);
			cout << "Добавление - 1" << endl << "Удаление - 2" << endl << "Сортировка - 3" << endl << "Поиск - 4"
				<< endl << "Вывод на экран - 5" << endl << "Чтение БД - 6" << endl << "Запись в БД - 7"
				<< endl << "Выход - 0" << endl << "Введите цифру для выбора необходимого действия" << endl;
			cin >> MenuChose;
			break;
		}
		case 4: {
			Search(TheTrain, Start);
			cout << "Добавление - 1" << endl << "Удаление - 2" << endl << "Сортировка - 3" << endl << "Поиск - 4"
				<< endl << "Вывод на экран - 5" << endl << "Чтение БД - 6" << endl << "Запись в БД - 7"
				<< endl << "Выход - 0" << endl << "Введите цифру для выбора необходимого действия" << endl;
			cin >> MenuChose;
			break;
		}
		case 5: {
			PrintTablet(TheTrain, Start);
			cout << "Добавление - 1" << endl << "Удаление - 2" << endl << "Сортировка - 3" << endl << "Поиск - 4"
				<< endl << "Вывод на экран - 5" << endl << "Чтение БД - 6" << endl << "Запись в БД - 7"
				<< endl << "Выход - 0" << endl << "Введите цифру для выбора необходимого действия" << endl;
			cin >> MenuChose;
			break;
		}
		case 6: {
			Read(TheTrain, Start, End);
			cout << "Добавление - 1" << endl << "Удаление - 2" << endl << "Сортировка - 3" << endl << "Поиск - 4"
				<< endl << "Вывод на экран - 5" << endl << "Чтение БД - 6" << endl << "Запись в БД - 7"
				<< endl << "Выход - 0" << endl << "Введите цифру для выбора необходимого действия" << endl;
			cin >> MenuChose;
			break;
		}
		case 7: {
			Record(TheTrain, Start);
			cout << "Добавление - 1" << endl << "Удаление - 2" << endl << "Сортировка - 3" << endl << "Поиск - 4" 
				<< endl << "Вывод на экран - 5" << endl << "Чтение БД - 6" << endl << "Запись в БД - 7" 
				<< endl << "Выход - 0" << endl << "Введите цифру для выбора необходимого действия" << endl;
			cin >> MenuChose;
			break;
		}
		case 0: {
			break;
		}
		}
	}
	return 0;
}

List *Delete(TRAIN TheTrain, List *&Start)
{
	List *st = Start;
	if (st == NULL) {
		cout << "Нечего удалять" << endl;
		return 0;
	}
	bool flag = 0;
	int num;
	cout << endl << "Введите номер поезда, который необходимо удалить" << endl;
	cin >> num;
	while (st != 0) {
		if (st->TheTrain.number == num) {
			if (st->prev == NULL) {
				Start = st->next;
			}
			if (st->next) {
				st->next->prev = st->prev;
			}
			if (st->prev) {
				st->prev->next = st->next;
			}
			flag = 1;
			cout << endl << "Запись удалена" << endl << endl;
		}
		st = st->next;
	}
	if (flag == 0) {
		cout << endl << "Поезд с таким номером не найден" << endl << endl;
	}
	return 0;
}

void Add(TRAIN TheTrain, List *&Start, List *&End)
{
	cout << endl << "Введите номер поезда" << endl;
	cin >> TheTrain.number;
	TheTrain.number = checkTr(TheTrain.number, Start);
	cout << "Введите место прибытия" << endl;
	cin >> TheTrain.destination;
	cout << "Введите часы прибытия" << endl;
	cin >> TheTrain.hours;
	TheTrain.hours = checkHou(TheTrain.hours);
	cout << "Введите минуты прибытия" << endl;
	cin >> TheTrain.minutes;
	TheTrain.minutes = checkMin(TheTrain.minutes);
	List *NewElem = new List;
	NewElem->next = NULL;
	NewElem->TheTrain = TheTrain;
	if (Start == NULL) {
		NewElem->prev = NULL;
		Start = End = NewElem;
	}
	else {
		NewElem->prev = End;
		End->next = NewElem;
		End = NewElem;
	}
	cout << endl;
}

void Sort(TRAIN TheTrain, List *&Start)
{
	List *st = Start;
	bool flag = 1;
	int k;
	do {
		k = 0;
		while (st->next != 0) {
			if (st->TheTrain.number > st->next->TheTrain.number) {
				swap(st->TheTrain, st->next->TheTrain);
				flag = 1;
				k++;
			}
			st = st->next;
		}
		if (k == 0) {
			flag = 0;
		}
		st = Start;
	} while (flag != 0);
	cout << endl << "Рейсы отсортированы по номеру" << endl << endl;
}

void Search(TRAIN TheTrain, List *&Start)
{
	List *st = Start;
	int num;
	bool flag = 0;
	cout << endl << "Введите номер поезда, который необходимо найти" << endl;	
	cin >> num;
	while (st != 0) {
		if (st->TheTrain.number == num) {
			cout << endl << "Найденный поезд:" << endl << "Номер: " << st->TheTrain.number << endl << "Место назначения: "
				<< st->TheTrain.destination << endl << "Время прибытия: " << st->TheTrain.hours << ":" << st->TheTrain.minutes;
			flag = 1;
		}
		st = st->next;
	}
	if (flag == 0) {
		cout << endl << "Искомый поезд не найден";
	}
	cout << endl << endl;
}

void PrintTablet(TRAIN TheTrain, List *&Start)
{
	cout << endl << "| " << "Номер поезда" << " | " << "Пункт прибытия" << " | " << "Время прибытия" << " |" << endl 
		<< "|--------------|----------------|----------------|" << endl;
	List *st = Start;
	while (st != 0) {
		cout << "| " << setw(12) << st->TheTrain.number << " | " << setw(14) << st->TheTrain.destination << " | " 
			<< setw(11) << st->TheTrain.hours << ":" << setw(2) << st->TheTrain.minutes << " |" << endl;
		cout << "|--------------|----------------|----------------|" << endl;
		st = st->next;
	}
	cout << endl;
}

void Read(TRAIN TheTrain, List *&Start, List *&End)
{
	List *st = Start;
	ifstream read_file("TRAIN.txt");
	string str, num, dest, hou, min;
	TRAIN asd;
	char txt[150];
	int x;
	do {
		read_file.getline(txt, 150);
		for (int i = 0; i < 150; i++) {
			str += txt[i];
		}
		x = 0;
		while (str[x] != '|') {
			num += str[x];
			x++;
			TheTrain.number = atoi(num.c_str());
		}
		x++;
		while (str[x] != '|') {
			dest += str[x];
			x++;
			TheTrain.destination = dest;
		}
		x++;
		while (str[x] != ':') {
			hou += str[x];
			x++;
			TheTrain.hours = atoi(hou.c_str());
		}
		x++;
		while (str[x] != ';') {
			min += str[x];
			x++;
			TheTrain.minutes = atoi(min.c_str());
		}
		ReadHelp(TheTrain, Start, End);
		str.clear();
		num.clear();
		dest.clear();
		hou.clear();
		min.clear();
	} while (!read_file.eof());
	cout << endl << "База данных загружена" << endl << endl;
	read_file.close();
}
void ReadHelp(TRAIN TheTrain, List *&Start, List *&End)
{
	List *NewElem = new List;
	NewElem->next = NULL;
	NewElem->TheTrain = TheTrain;
	if (Start == NULL) {
		NewElem->prev = NULL;
		Start = End = NewElem;
	}
	else {
		NewElem->prev = End;
		End->next = NewElem;
		End = NewElem;
	}
}

void Record(TRAIN TheTrain, List *&Start)
{
	List *st = Start;
	ofstream record_file;
	record_file.open("TRAIN.txt");
	while (st != 0) {
		record_file << st->TheTrain.number << "|" << st->TheTrain.destination
			<< "|" << st->TheTrain.hours << ":" << st->TheTrain.minutes << ";" << endl;
		st = st->next;
	}
	cout << endl << "Таблица была сохранена" << endl << endl;
}

int check(int z) {
	while ((cin.fail()) || (cin.get() != '\n') || (z < 0) || (z > 7)) {
		cout << "Ошибка, введите число повторно" << endl;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cin >> z;
	}
	return z;
}
int checkHou(int z)
{
	while ((cin.fail()) || (cin.get() != '\n') || (z < 0) || (z > 23)) {
		cout << "Ошибка, введите число повторно" << endl;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cin >> z;
	}
	return z;
}
int checkMin(int z)
{
	while ((cin.fail()) || (cin.get() != '\n') || (z < 0) || (z > 59)) {
		cout << "Ошибка, введите число повторно" << endl;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cin >> z;
	}
	return z;
}
int checkTr(int z, List *&Start)
{
	List* st = Start;
	while (st != 0) {
		if (z == st->TheTrain.number) {
			cout << "Номер поезда не уникален, введите другой номер" << endl;
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cin >> z;
		}
		st = st->next;
	}
	return z;
}
