// Лабораторная работа №1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
using namespace std;
#include <iostream>

void menu() {
	cout << '\n';
	cout << "1) Вывести, сколько памяти (в байтах) на вашем компьютере отводится под различные типы данных со спецификаторами и без: int, short int, long int, float, double, long double, char и bool." << '\n';
	cout << '\n';
	cout << "2) Вывести на экран двоичное представление в памяти (все разряды) целого числа. При выводе необходимо визуально обозначить знаковый разряд и значащие разряды отступами или цветом." << '\n';
	cout << '\n';
	cout << "3) Вывести на экран двоичное представление в памяти (все разряды) типа float. При выводе необходимо визуально обозначить знаковый разряд мантиссы, знаковый разряд порядка (если есть), мантиссу и порядок." << '\n';
	cout << '\n';
	cout << "4) Вывести на экран двоичное представление в памяти (все разряды) типа double. При выводе необходимо визуально обозначить знаковый разряд мантиссы, знаковый разряд порядка (если есть), мантиссу и порядок." << '\n';
	cout << '\n';
	cout << "0) Завершить программу" << '\n';
	cout << '\n';
}

void memory() {
	cout << "Размер в байтах" << '\n';
	cout << "int" << " " << "=" << " " << sizeof(int) << '\n';
	cout << "short int" << " " << "=" << " " << sizeof(short int) << '\n';
	cout << "long int" << " " << "=" << " " << sizeof(long int) << '\n';
	cout << "float" << " " << "=" << " " << sizeof(float) << '\n';
	cout << "double" << " " << "=" << " " << sizeof(double) << '\n';
	cout << "long double" << " " << "=" << " " << sizeof(long double) << '\n';
	cout << "char" << " " << "=" << " " << sizeof(char) << '\n';
	cout << "bool" << " " << "=" << " " << sizeof(bool) << '\n';
}

void integer() {
	cout << "Введите число типа данных int ";
	int value;
	cin >> value;
	unsigned int order = sizeof(int) * 8;
	unsigned int mask = 1 << order - 1;
	for (int i = 1; i <= order; i++)
	{
		putchar(value & mask ? '1' : '0');
		mask >>= 1;
		if (!(i % 8) || !(i % order - 1))
			putchar(' ');
	}
	cout << '\n';


	cout << "Сдвинуть биты в право" << '\n' << "1 = да" << '\n' << "0 = нет" << '\n';
	bool a;
	cin >> a;
	if (a)
	{
		int c;
		cout << "Введите число на сколько сдвинуть в право ";
		cin >> c;
		value >>= c;
		unsigned int order = sizeof(int) * 8;
		unsigned int mask = 1 << order - 1;
		for (int i = 1; i <= order; i++)
		{
			putchar(value & mask ? '1' : '0');
			mask >>= 1;
			if (!(i % 8) || !(i % order - 1))
				putchar(' ');
		}
		cout << '\n';
	}

}

void float_()
{
	union {
		int integerA;
		float floatB;
	};
	cout << "Введите число типа данных float ";
	cin >> floatB;
	unsigned int order = sizeof(int) * 8;
	unsigned int mask = 1 << order - 1;
	for (int i = 1; i <= order; i++)
	{
		putchar(integerA & mask ? '1' : '0');
		mask >>= 1;
		if (i == 9)
		{
			putchar(' ');
		}
		if (i % order - 1 == 0)
		{
			putchar(' ');
		}
	}
	cout << '\n';


	cout << "Сдвинуть биты в право" << '\n' << "1 = да" << '\n' << "0 = нет" << '\n';
	bool a;
	cin >> a;
	if (a)
	{
		int c;
		cout << "Введите число на сколько сдвинуть в право ";
		cin >> c;

		integerA >>= c;
		unsigned int order = sizeof(int) * 8;
		unsigned int mask = 1 << order - 1;
		for (int i = 1; i <= order; i++)
		{
			putchar(integerA & mask ? '1' : '0');
			mask >>= 1;
			if (i == 9)
			{
				putchar(' ');
			}
			if (i % order - 1 == 0)
			{
				putchar(' ');
			}
		}
	}
}

void double_()
{
	union
	{
		int integerA[2];
		double doubleB;
	};
	cout << "Введите число типа данных double ";
	cin >> doubleB;
	unsigned int order = sizeof(int) * 8;
	unsigned int mask = 1 << order - 1;
	for (int i = 1; i >= 0; i--)
	{
		mask = 1 << order - 1;
		for (int j = 0; j < order; j++)
		{
			putchar(integerA[i] & mask ? '1' : '0');
			mask >>= 1;
			if ((j == 11) && i)
			{
				putchar(' ');
			}
			if ((j % order == 0) && i)
			{
				putchar(' ');
			}
		}
	}
	cout << '\n';


	cout << "Сдвинуть биты в право" << '\n' << "1 = да" << '\n' << "0 = нет" << '\n';
	bool a;
	cin >> a;
	if (a)
	{
		unsigned int c, d;
		cout << "Введите число на сколько сдвинуть в право ";
		cin >> c;
		d = integerA[1] >> c;
		integerA[1] = d;
		cout << d << '\n';
		d = integerA[0] >> c;
		integerA[0] = d;
		cout << d << '\n';
		for (int i = 1; i >= 0; i--)
		{
			mask = 1 << order - 1;
			for (int j = 0; j < order; j++)
			{
				putchar(integerA[i] & mask ? '1' : '0');
				mask >>= 1;
				if ((j == 11) && i)
				{
					putchar(' ');
				}
				if ((j % order == 0) && i)
				{
					putchar(' ');
				}
			}
		}
	}
}

int main()
{
	int choice;
	setlocale(0, "");
	while (true)
	{
		menu();
		cout << "Выберите номер пункта ";
		cin >> choice;
		switch (choice)
		{
		case 0:
			exit(0);
			break;
		case 1:
			memory();
			break;
		case 2:
			integer();
			break;
		case 3:
			float_();
			break;
		case 4:
			double_();
			break;
		default:
			cout << "Ошибка ввода";
			break;
		}
		cout << '\n';
		system("pause");
		system("cls");
	}
}