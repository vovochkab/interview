/*
* solution.cpp
* Distributed under terms of the MIT license.
* Сложность: 6
*/

#include <string>
#include <string.h>

/*
* Необходимо, учитывая строку, заменить каждую букву ее позицией в алфавите.
* Если что-то в тексте не является буквой, игнорируйте это и не возвращайте.
* «a» = 1, «b» = 2 и т.д.
*
* Пример:
* alphabet_position("The sunset sets at twelve o' clock.");
* Должен вернуть "20 8 5 19 21 14 19 5 20 19 5 20 19 1 20 20 23 5 12 22 5 15 3 12 15 3 11" (в виде строки)
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

bool is_upper_case_letter(char letter_code)
{
	return letter_code >= 65 && letter_code <= 90;
}

bool is_lower_case_letter(char letter_code)
{
	return letter_code >= 97 && letter_code <= 122;
}

char* alphabet_position(char @club139805118(*text))
{
	char* output = new char[strlen(text) * 3 - 1]();
	int data_length;
	char letter_code;
	char* res_letter_pointer;

	strcpy(output, text);
	res_letter_pointer = output;

	for (char* current_letter = text; *current_letter != '\0'; current_letter++)
	{
		letter_code = *current_letter;

		if (!(is_upper_case_letter(letter_code) || is_lower_case_letter(letter_code)))
			continue;

		if (is_lower_case_letter(letter_code))
			letter_code -= 32;

		data_length = overwrite_bytes(res_letter_pointer, (int)(letter_code - 64));
		res_letter_pointer += data_length;

		*res_letter_pointer = ' ';
		res_letter_pointer++;
	}

	if (*(res_letter_pointer - 1) == ' ') —res_letter_pointer;
	*res_letter_pointer = '\0';

	return output;
}