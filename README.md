# C++
##Lab №1
## Tasks
- [ ] 1. Создать публичный репозиторий;
- [ ] 2. Выполнить задания в соответствии с своим  **18** вариантом.

## Tutorial
**1. Базовый уровень**
```bash
Определить среднюю стоимость товара и товар с минимальной стоимостью.
```

```ShellSession
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
	if (newmin < min)//Поиск наименьшего
		min = newmin;
	}
	middlePrice = middlePrice / N;//Вычисление средней цены
```
**2. Средний уровень**
```bash
Вывести сведения о товарах, срок годности которых меньше 20-ти днейю Определить количество просроченых товаров.
```

```ShellSession
for (int i = 0; i < N; i++)
{
	int maxdate = 0, out = group[i].release.day + 20, outdate = group[i].release.day, outmonth = group[i].release.month, outyear = group[i].release.year;
	switch (group[i].release.month)//Установка максимально допустимого дня в месеце
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
	if ((out % maxdate) < (out))//Дата + 20
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
	if (outyear >= group[i].shelfLife.year)//Вывод товаров со сроком меньше 20
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
	if (nowday.year >= group[i].shelfLife.year)//Счетчик просроченых товаров
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
```
**2. Высокий уровень**
```bash
Описать структуру с именем NOТЕ, содержащую поля: Name — фамилия и инициалы, TELE — номер телефона, DATE — дата рождения (год.месяц, число)
		Написать программу, выполняющую:
			— ввод с клавиатуры данных в массив BLOCKNOTE состоящий из 10
			структур типа NOTE, записи должны быть упорядочены по возрастанию даты рождения;
			- вывод на экран сведений о человеке, номер телефон которого введен с клавиатуры;
			- усли такого человека нет - выдать сообщение
```

```ShellSession
do//Сортировка по возрастанию даты рождения
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
```

```ShellSession
cout << "------------------" << endl;
cout << "Search by phone number: ";
while (!(cin >> number))//Проверка на ввод номера
{
	cout << "Search by phone number: ";
	cin >> number;
	cin.clear();
	cin.ignore(std::cin.rdbuf()->in_avail());
}

for (int i = 0; i < N; i++)//Вывод
{
	if (number == BLOCKNOTE[i].TELE)//Поиск
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
if (sum == N)//Если не нашел
{
	cout << "No such person found.";
}
```
