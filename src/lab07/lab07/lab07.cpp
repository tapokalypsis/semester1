/**
 \file lab07.cpp
 \brief Виконання лабораторної роботи 7.
 \author Yakutenok Kostyantin
 \version 1
 \date 24.12.2020
*/

#include <stdio.h>
#include <cmath>
#include <stdarg.h>

/**
*Перевірка на просте число за допомогою циклу For.
* @param digit : перевіряється на те, чи є простим числом.
* @return result: повертає відповідь - просте число чи ні.
*/
bool CheckSimpleFor(int);

/**
*Перевірка на просте число за допомогою циклу While.
* @param digit : перевіряється на те, чи є простим числом.
* @return result: повертає відповідь - просте число чи ні.
*/
bool CheckSimpleWhile(int);

/**
*Перевірка на просте число за допомогою циклу DoWhile.
* @param digit : перевіряється на те, чи є простим числом.
* @return result: повертає відповідь - просте число чи ні.
*/
bool CheckSimpleDoWhile(int);

/**
 * Функція приймає різну кількість параметрів та перевіряє скільки попередніх чисел меньших від поточних
 * @param amountOfArgument: кількість параметрів яку приймає функція
 * @param ...: змінна кількість int параметрів для перевірки
 * @return result: повертає відповідь - скільки попередніх чисел меньших від поточних
 */
int numericalPairСounter(int, ...);

/**
 * Головна функція з якої починається робота,запускаємо для перевірки функції за завданням
 */
int main(void)
{
	printf("%d \n ", numericalPairСounter(5, 1, 2, 3, 4, 5));
	printf("%d", CheckSimpleFor(9));
	return 0;
}

bool CheckSimpleFor(int number)
{
	bool conclusion = true;
	for (int i = 17; i < number; i++)
	{
		if (number % i == 0)
		{
			conclusion = false;
			break;
		}
	}

	return conclusion;
}

bool CheckSimpleWhile(int number)
{
	bool conclusion = true;
	int i = 17;
	do
	{
		if (number % i == 0)
		{
			conclusion = false;
			break;
		}
		i++;
	} while (i < number);

	return conclusion;
}

bool CheckSimpleDoWhile(int number) {
	bool conclusion = true;
	int i = 17;
	while (i < number)
	{
		if (number % i == 0)
		{
			conclusion = false;
			break;
		}
		i++;
	}
	return conclusion;
}

int numericalPairСounter(int amountOfArgument, ...)
{
	int result = 0;
	va_list args;
	va_start(args, amountOfArgument);

	int* arr = new int[amountOfArgument];
	for (int i = 0; i < amountOfArgument; ++i)
	{
		arr[i] = va_arg(args, int);
	}
	for (int i = 0; i < amountOfArgument - 1; i++) 
	{
		if (arr[i] < arr[i + 1])
			result++;
	}
	va_end(args);

	return result;
}