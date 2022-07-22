/*
* solution.c
* Distributed under terms of the MIT license.
* Сложность: 7
*/

#include <string.h>

/* Дан массив идущих подряд чисел от 1 до N в произвольном порядке.
* В случае пустого массива необходимо вернуть 0.
* Из массива убран один элемент.
* Найти пропущенное число.
*/

void quick_sort(int* mas, int size) {

	int i = 0;
	int j = size - 1;

	int mid = mas[size / 2];

	do
	{
		while (mas[i] < mid) i++;
		while (mas[j] > mid) j--;

		if (i <= j)
		{
			int tmp = mas[i];
			mas[i] = mas[j];
			mas[j] = tmp;

			i++;
			j--;
		}
	} while (i <= j);

	if (j > 0) quick_sort(mas, j + 1);

	if (i < size) quick_sort(&mas[i], size - i);
}

int lost_number(int* numbers, size_t size)
{
	int index = 0;

	quick_sort(numbers, (int)size);

	for (int* pointer = numbers; pointer != numbers + size; pointer++)
		if (*pointer - 1 != index++) return index;

	return index;
}