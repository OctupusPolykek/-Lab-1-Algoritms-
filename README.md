# C
C++

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
		if (newmin < min)
			min = newmin;
	}
	middlePrice = middlePrice / N;
```
