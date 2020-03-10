# C++
## Tasks
- [ ] 1. Создать публичный репозиторий
- [ ] 2. Выполнить задания в соответствии с своим вариантом **18**

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
