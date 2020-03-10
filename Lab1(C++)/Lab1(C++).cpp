#include <iostream>

using namespace std;

struct Date 
{
	short day;
	short month;
	short year;
	bool isCorrect();
};

bool Date::isCorrect()
{
	bool result = false;
	if ((day < 1) || (month < 1) || (year < 1))
		result = false;
	else {
		switch (month)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
		{
			if ((day <= 31) && (day > 0))
				result = true;
			break;
		}

		case 4:
		case 6:
		case 9:
		case 11:
		{
			if ((day <= 30) && (day > 0))
				result = true;
			break;
		}

		case 2:
		{
			if (year % 4 != 0)
			{
				if ((day <= 28) && (day > 0))
					result = true;
			}
			else
				if (year % 400 == 0)
				{
					if ((day <= 29) && (day > 0))
						result = true;
				}
				else
					if ((year % 100 == 0) && (year % 400 != 0))
					{
						if ((day == 28) && (day > 0))
							result = true;
					}
					else
						if ((year % 4 == 0) && (year % 100 != 0))
							if ((day <= 29) && (day > 0))
								result = true;
			break;
		}

		default:
			result = false;
		}
	}
	return result;
}

struct Product 
{
    char name[56];
    int amount;
    float price;
    char madeIn[128];
	Date release;

};

void taskEase18() 
{
	cout << "Task 18 (ease)" << endl;
	//Определить среднюю стоимость товара и товар с минимальной стоимостью.

	const int N = 2;
	Product group[N];

	for (int i = 0; i < N; i++) 
	{
		cout << "------------------" << endl;

		cout << "Input name: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(group[i].name, 56);

		cout << "Input amount: ";
		while (!(cin >> group[i].amount))
		{
			cout << "Input amount: ";
			cin >> group[i].amount;
			cin.clear();
			cin.ignore(std::cin.rdbuf()->in_avail());
		}

		cout << "Input price: ";
		while (!(cin >> group[i].price))
		{
			cout << "Input price: ";
			cin >> group[i].price;
			cin.clear();
			cin.ignore(std::cin.rdbuf()->in_avail());
		}

		cout << "Input Made in: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(group[i].madeIn, 128);

		do
		{
			cout << "Input release: ";
			cin.clear();
			cin.ignore(std::cin.rdbuf()->in_avail());
			cin >> group[i].release.day >> group[i].release.month >> group[i].release.year;
		} while (!group[i].release.isCorrect());
	}

	float middlePrice = 0, min = 0;
	bool minones = true;

	for (int i = 0; i < N; i++) 
	{
		middlePrice += (group[i].price);
		if (minones)
		{
			min = group[i].price + 1;
			minones = false;
		}
		float newmin = group[i].price;
		if (newmin < min)
			min = newmin;

	}

	middlePrice = middlePrice / N;

	cout << "\nAverage cost of goods: " << middlePrice << endl;

	cout << "\nMinimum cost product: " << endl;

	for (int i = 0; i < N; i++)
	{
		if (min == group[i].price) 
		{
			cout << "-----------------------" << endl;
			cout << "Name: " << group[i].name;
			cout << "\nAmount: " << group[i].amount;
			cout << "\nprice: " << group[i].price;
			cout << "\nMade in: " << group[i].madeIn;
			cout << "\nRelease: " << group[i].release.day << "." << group[i].release.month << "." << group[i].release.year << endl;
		}
	}
	cout << "-----------------------" << endl;
}
	
struct ProductMiddle 
{
	char name[56];
	float price;
	Date release;
	Date shelfLife;
	int amount;
	char madeIn[128];
};

void taskMedium18() 
{
	cout << "Task 18 (medium)" << endl;
	//Вывести сведения о товарах, срок годности которых меньше 20-ти днейю Определить количество просроченых товаров.

	const int N = 2;
	int sum = 0;
	ProductMiddle group[N];
	Date nowday;

	do
	{
		cout << "\nInput today's date: ";
		cin.clear();
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin >> nowday.day >> nowday.month >> nowday.year;

	} while (!nowday.isCorrect());

	cout << "\n";

	for (int i = 0; i < N; i++)
	{

		cout << "------------------" << endl;

		cout << "Input name: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(group[i].name, 56);

		cout << "Input price: ";
		while (!(cin >> group[i].price))
		{
			cout << "Input price: ";
			cin >> group[i].price;
			cin.clear();
			cin.ignore(std::cin.rdbuf()->in_avail());
		}

		do
		{
			cout << "Input release: ";
			cin.clear();
			cin >> group[i].release.day >> group[i].release.month >> group[i].release.year;
			cin.ignore(std::cin.rdbuf()->in_avail());

		} while (!group[i].release.isCorrect());

		do
		{
			while (group[i].shelfLife.year < group[i].release.year) 
			{
				cout << "Input shelf life: ";
				cin >> group[i].shelfLife.day >> group[i].shelfLife.month >> group[i].shelfLife.year;
				cin.clear();
				cin.ignore(std::cin.rdbuf()->in_avail());
			}

			if ((group[i].shelfLife.year == group[i].release.year) && (group[i].shelfLife.month < group[i].release.month))
			{
				while (group[i].shelfLife.month < group[i].release.month)
				{
					cout << "Input shelf life: ";
					cin >> group[i].shelfLife.day >> group[i].shelfLife.month >> group[i].shelfLife.year;
					cin.clear();
					cin.ignore(std::cin.rdbuf()->in_avail());
				}
			}

			if ((group[i].shelfLife.day <= group[i].release.day) && (group[i].shelfLife.month == group[i].release.month) && (group[i].shelfLife.year == group[i].release.year))
			{
				while (group[i].shelfLife.day <= group[i].release.day)
				{
					cout << "Input shelf life: ";
					cin >> group[i].shelfLife.day >> group[i].shelfLife.month >> group[i].shelfLife.year;
					cin.clear();
					cin.ignore(std::cin.rdbuf()->in_avail());
				}
			}

		} while (!group[i].shelfLife.isCorrect());

		cout << "Input amount: ";
		while (!(cin >> group[i].amount))
		{
			cout << "Input amount: ";
			cin >> group[i].amount;
			cin.clear();
			cin.ignore(std::cin.rdbuf()->in_avail());
		}

		cout << "Input Made in: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(group[i].madeIn, 128);
	}

	for (int i = 0; i < N; i++)
	{
		int maxdate = 0, out = group[i].release.day + 20, outdate = group[i].release.day, outmonth = group[i].release.month, outyear = group[i].release.year;
		switch (group[i].release.month)
		{
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
			{
				maxdate = 31;
				break;
			}
			case 4:
			case 6:
			case 9:
			case 11:
			{
				maxdate = 30;
				break;
			}

			case 2:
			{
				if (group[i].release.year % 4 != 0)
				{
					maxdate = 28;
				}
				else
					if (group[i].release.year % 400 == 0)
						maxdate = 29;
					else
						if ((group[i].release.year % 100 == 0) && (group[i].release.year % 400 != 0))
							maxdate = 28;
						else
							if ((group[i].release.year % 4 == 0) && (group[i].release.year % 100 != 0))
								maxdate = 29;
				break;
			}
		}
		if ((out % maxdate) < (out))
		{
			outdate = out % maxdate;
			outmonth++;
			if (outmonth > 12) 
			{
				outmonth = 1;
				outyear++;
			}
		}
		else 
			outdate = out;

		if (outyear >= group[i].shelfLife.year)
		{
			if (outmonth >= group[i].shelfLife.month)
			{
				if (outdate > group[i].shelfLife.day)
				{
					cout << "-----------------------" << endl;
					cout << "Name: " << group[i].name;
					cout << "\nprice: " << group[i].price;
					cout << "\nRelease: " << group[i].release.day << "." << group[i].release.month << "." << group[i].release.year;
					cout << "\nShelf Life: " << group[i].shelfLife.day << "." << group[i].shelfLife.month << "." << group[i].shelfLife.year;
					cout << "\nAmount: " << group[i].amount;
					cout << "\nMade in: " << group[i].madeIn << endl;
					cout << "-----------------------" << endl;
				}
			}
		}

		if (nowday.year >= group[i].shelfLife.year)
		{
			if (nowday.month >= group[i].shelfLife.month)
			{
				if (nowday.day > group[i].shelfLife.day)
				{
					sum++;
				}
			}
	
		}

	}
	cout << "\nThe number of expired goods " << sum << endl;
}

struct NOTE
{
	char F[56];
	char I[32];
	char O[32];
	int TELE;
	Date birthday;
};

void taskHard4()
{
	cout << "Task 4 (hard)" << endl;
	/*Описать структуру с именем NOТЕ, содержащую поля: Name — фамилия и инициалы, TELE — номер телефона, DATE — дата рождения (год.месяц, число)
		Написать программу, выполняющую:
			— ввод с клавиатуры данных в массив BLOCKNOTE состоящий из 10
			структур типа NOTE, записи должны быть упорядочены по возрастанию даты рождения;
			- вывод на экран сведений о человеке, номер телефон которого введен с клавиатуры;
			- усли такого человека нет - выдать сообщение*/

	const int N = 3;
	NOTE BLOCKNOTE[N];
	bool swapped;
	int number, sum = 0;

	for (int i = 0; i < N; i++)
	{
		cout << "------------------" << endl;

		cout << "Input F: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(BLOCKNOTE[i].F, 56);

		cout << "Input I: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(BLOCKNOTE[i].I, 32);

		cout << "Input O: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(BLOCKNOTE[i].O, 32);

		cout << "Input telephone: ";
		while (!(cin >> BLOCKNOTE[i].TELE))
		{
			cout << "Input telephone: ";
			cin >> BLOCKNOTE[i].TELE;
			cin.clear();
			cin.ignore(std::cin.rdbuf()->in_avail());
		}

		do
		{
			cout << "Input birthday: ";
			cin.clear();
			cin.ignore(std::cin.rdbuf()->in_avail());
			cin >> BLOCKNOTE[i].birthday.day >> BLOCKNOTE[i].birthday.month >> BLOCKNOTE[i].birthday.year;
		} while (!BLOCKNOTE[i].birthday.isCorrect());
	}

	do//Сортировка
	{
		swapped = false;
		for (int count = 0; count < N - 1; count++)
		{
			if (BLOCKNOTE[count].birthday.year > BLOCKNOTE[count + 1].birthday.year)
			{
				swap(BLOCKNOTE[count], BLOCKNOTE[count + 1]);
				swapped = true;
			}
			else if ((BLOCKNOTE[count].birthday.year == BLOCKNOTE[count + 1].birthday.year) && (BLOCKNOTE[count].birthday.month > BLOCKNOTE[count + 1].birthday.month))
			{
				swap(BLOCKNOTE[count], BLOCKNOTE[count + 1]);
				swapped = true;
			}
			else if ((BLOCKNOTE[count].birthday.year == BLOCKNOTE[count + 1].birthday.year) && (BLOCKNOTE[count].birthday.month == BLOCKNOTE[count + 1].birthday.month) && (BLOCKNOTE[count].birthday.day > BLOCKNOTE[count + 1].birthday.day))
			{
				swap(BLOCKNOTE[count], BLOCKNOTE[count + 1]);
				swapped = true;
			}
		}
	} while (swapped);
		
	cout << "------------------" << endl;
	cout << "Search by phone number: ";
	while (!(cin >> number))
	{
		cout << "Search by phone number: ";
		cin >> number;
		cin.clear();
		cin.ignore(std::cin.rdbuf()->in_avail());
	}

	for (int i = 0; i < N; i++)//Вывод
	{
		if (number == BLOCKNOTE[i].TELE)
		{
			cout << "-----------------------" << endl;
			cout << "FIO: " << BLOCKNOTE[i].F << " " << BLOCKNOTE[i].I << "." << BLOCKNOTE[i].O << ".";
			cout << "\nTelephone: " << BLOCKNOTE[i].TELE;
			cout << "\nBirthday: " << BLOCKNOTE[i].birthday.day << "." << BLOCKNOTE[i].birthday.month << "." << BLOCKNOTE[i].birthday.year << endl;
			cout << "-----------------------" << endl;
			break;
		}
		else 
		{
			sum++;
		}
	}
	if (sum == N)
	{
		cout << "No such person found.";
	}

}

int main()
{
	taskEase18();
	taskMedium18();
	taskHard4();
	return 0;
}