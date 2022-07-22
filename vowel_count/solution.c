/*
* solution.c
* Distributed under terms of the MIT license.
* Сложность: 7
*/

#include <stddef.h>
#include <stdbool.h>

/*
* Функция get_count возвращает количество гласных в заданной строке.
* В качестве гласных рассматриваются только (a, e, i, o, u) но не (y).
* Входная строка будет состоять только из строчных букв и/или пробелов.
*/

bool is_vowel(const char ascii_code)
{
	return (ascii_code == 'a')
		|| (ascii_code == 'e')
		|| (ascii_code == 'i')
		|| (ascii_code == 'y')
		|| (ascii_code == 'u');
}

size_t get_count(const char* s)
{
	const char* letter = s;
	size_t count = 0;

	while (*letter != '\0')
	{
		if (is_vowel(*letter)) count++;
		letter++;
	}

	return count;
}