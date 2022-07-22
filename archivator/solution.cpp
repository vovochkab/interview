/*
* solution.cpp
* Distributed under terms of the MIT license.
* Сложность: 4
*/

#include <string>
#include <string.h>
#include <stdlib.h>

/*
* Функция archiving принимает строку заглавных латинских символов
* и возвращает упакованный вариант этой строки.
* Символы упаковываются по следующим правилам:
* последовательность из нескольких одинаковых символов ("DDD") преобразуется в ("3D")
* последовательность из одного символа переносится без изменений
*
* Пример:
* archiving("WFFGGGH");
* Должен вернуть "W2F3GH"
*
* Вызывающий код освобождает возвращаемый указатель
*/

int overwrite_bytes(char* letter_pointer, int value)
{
	std::string string_number = std::to_string(value);

	for (int index = 0; index < (int)string_number.length(); index++)
	{
		*letter_pointer = (char)string_number[index];
		letter_pointer++;
	}

	return string_number.length();
}

char* archiving(char* input)
{
	int data_length;
	int repeat_counts = 1;
	char* last_letter_pointer;
	char* output = new char[strlen(input)]();

	strcpy(output, input);
	last_letter_pointer = output;

	for (char* current_letter = output; *current_letter != '\0'; current_letter++)
	{
		if (*current_letter == *(current_letter + 1))
		{
			++repeat_counts;
			continue;
		}

		if (repeat_counts == 1)
		{
			*last_letter_pointer = *current_letter;
			last_letter_pointer++;
			continue;
		}

		data_length = overwrite_bytes(last_letter_pointer, repeat_counts);
		last_letter_pointer += data_length;
		*last_letter_pointer = *current_letter;
		last_letter_pointer++;
		repeat_counts = 1;
	}

	*last_letter_pointer = '\0';
	return output;
}