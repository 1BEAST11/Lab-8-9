#include <iostream>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	const int amount = 8;
	char board[amount][amount] = {};
	int k, l = 0, m, n = 0;
	int figure = 0, figure_2 = 0;


	for (int i = 0; i < amount; i++)
	{
		for (int j = 0; j < amount; j++)
		{
			if ((i + 1) % 2 == 0)
			{
				if ((j + 1) % 2 == 0)
				{
					board[i][j] = 'Б';
				}

				else
				{
					board[i][j] = 'Ч';
				}
			}

			else
			{
				if ((j + 1) % 2 == 0)
				{
					board[i][j] = 'Ч';
				}

				else
				{
					board[i][j] = 'Б';
				}
			}

		}
	}
	
	while (true)
	{
		cout << "Введите номер вертикали ПЕРВОГО поля (ЦЕЛОЕ число от 1 до 8): ";
		cin >> k;

		// обработка ввода неверного типа данных
		if (cin.fail() || cin.get() != '\n')
		{
			cout << "\nНекорректный ввод. Повторите попытку.\n" << endl;
			cin.clear();
			cin.ignore(1000, '\n');
		}

		// обработка ввода числа, выходящего за пределы диапазона
		else if (k < 1 || k > 8)
		{
			cout << endl;
			cout << "Номер должен находиться в диапазоне от 1-8.\n" << "Повторите попытку." << endl;
			cout << endl;
		}

		else
		{
			break;
		}
	}



while (true)
{
	cout << "Введите номер горизонтали ПЕРВОГО поля (ЦЕЛОЕ число от 1 до 8): ";
	cin >> l;

	// обработка ввода неверного типа данных
	if (cin.fail() || cin.get() != '\n')
	{
		cout << "\nНекорректный ввод. Повторите попытку.\n" << endl;
		cin.clear();
		cin.ignore(1000, '\n');
	}

	// обработка ввода числа, выходящего за пределы диапазона
	else if (l < 1 || l > 8)
	{
		cout << endl;
		cout << "Номер должен находиться в диапазоне от 1-8.\n" << "Повторите попытку." << endl;
		cout << endl;
	}

	else
	{
		break;
	}
}
cout << endl;

while (true)
{
	cout << "Введите номер вертикали ВТОРОГО поля (ЦЕЛОЕ число от 1 до 8): ";
	cin >> m;

	// обработка ввода неверного типа данных
	if (cin.fail() || cin.get() != '\n')
	{
		cout << "\nНекорректный ввод. Повторите попытку.\n" << endl;
		cin.clear();
		cin.ignore(1000, '\n');
	}

	// обработка ввода числа, выходящего за пределы диапазона
	else if (m < 1 || m > 8)
	{
		cout << endl;
		cout << "Номер должен находиться в диапазоне от 1-8.\n" << "Повторите попытку." << endl;
		cout << endl;
	}

	else
	{
		break;
	}
}

while (true)
{
	cout << "Введите номер горизонтали ВТОРОГО поля (ЦЕЛОЕ число от 1 до 8): ";
	cin >> n;

	// обработка ввода неверного типа данных
	if(cin.fail() || cin.get() != '\n')
	{
		cout << "\nНекорректный ввод. Повторите попытку.\n" << endl;
		cin.clear();
		cin.ignore(1000, '\n');
	}

	// обработка ввода числа, выходящего за пределы диапазона
	else if (n < 1 || n > 8)
	{
		cout << endl;
		cout << "Номер должен находиться в диапазоне от 1-8.\n" << "Повторите попытку." << endl;
		cout << endl;
	}

	else
	{
		break;
	}
}
cout << endl;

// проверка на совпадение цветов
if (board[amount - k][l - 1] == board[amount - m][n - 1])
{
	cout << "Цвета полей с координатами (" << k << ", " << l << ")" << " и (" << m << ", " << n << ") совпадают" << endl;
}

else
{
	cout << "Цвета полей с координатами (" << k << ", " << l << ")" << " и (" << m << ", " << n << ") НЕ совпадают" << endl;
}

// проверка, угрожает ли фигура полю
while (true)
{
	cout << "\nДля определения угрозы укажите фигуру, стоящую на ПЕРВОМ поле\n(нажмите 1 - для ФЕРЗЯ, 2 - для ЛАДЬИ, 3 - для СЛОНА, 4 - для КОНЯ): ";
	cin >> figure;
	
	// обработка ввода неверного типа данных
	if (cin.fail() || cin.get() != '\n')
	{
		cout << "\nНекорректный ввод. Повторите попытку.\n" << endl;
		cin.clear();
		cin.ignore(1000, '\n');
	}

	// обработка ввода не того числа
	else if (figure < 1|| figure > 4)
	{
		cout << endl;
		cout << "Введено неверное число.\n" << "Введите число 1, 2, 3 или 4." << endl;
	}

	else
	{
		break;
	}
}
cout << endl;

// ферзь
if (figure == 1)
{
	if (k == m || l == n || abs(k - m) == abs(l - n))
	{
		cout << "ФЕРЗЬ на поле (" << k << ", " << l << ")" << " угрожает полю (" << m << ", " << n << ")." << endl;
	}

	else
	{
		cout << "ФЕРЗЬ на поле (" << k << ", " << l << ")" << " НЕ угрожает полю (" << m << ", " << n << ")." << endl;
	}
}

// ладья
else if (figure == 2)
{
	if (k == m || l == n)
	{
		cout << "ЛАДЬЯ на поле (" << k << ", " << l << ")" << " угрожает полю (" << m << ", " << n << ")." << endl;
	}

	else
	{
		cout << "ЛАДЬЯ на поле (" << k << ", " << l << ")" << " НЕ угрожает полю (" << m << ", " << n << ")." << endl;
	}
}

// слон
else if (figure == 3)
{
	if (abs(k - m) == abs(l - n))
	{
		cout << "СЛОН на поле (" << k << ", " << l << ")" << " угрожает полю (" << m << ", " << n << ")." << endl;
	}

	else
	{
		cout << "СЛОН на поле (" << k << ", " << l << ")" << " НЕ угрожает полю (" << m << ", " << n << ")." << endl;
	}
}

// конь
else if (figure == 4)
{
	if ((abs(k - m) == 1 && abs(l - n) == 2) || (abs(k - m) == 2 && abs(l - n) == 1))
	{
		cout << "КОНЬ на поле (" << k << ", " << l << ")" << " угрожает полю (" << m << ", " << n << ")." << endl;
	}

	else
	{
		cout << "КОНЬ на поле (" << k << ", " << l << ")" << " НЕ угрожает полю (" << m << ", " << n << ")." << endl;
	}
}

// проверка на количество ходов
while (true)
{
	cout << "\nДля определения необходимого количества ходов укажите фигуру, стоящую на ПЕРВОМ поле\n(нажмите 1 - для ФЕРЗЯ, 2 - для ЛАДЬИ, 3 - для СЛОНА): ";
	cin >> figure_2;

	// обработка ввода неверного типа данных
	if (cin.fail() || cin.get() != '\n')
	{
		cout << "\nНекорректный ввод. Повторите попытку.\n" << endl;
		cin.clear();
		cin.ignore(1000, '\n');
	}

	// обработка ввода не того числа
	else if (figure_2 < 1 || figure_2 > 3)
	{
		cout << endl;
		cout << "Введено неверное число.\n" << "Введите число 1, 2 или 3." << endl;
	}

	else
	{
		break;
	}
}
cout << endl;

// ферзь
if (figure_2 == 1)
{
	if (k == m || l == n || abs(k - m) == abs(l - n))
	{
		cout << "ФЕРЗЬ может за 1 ход попасть с поля (" << k << ", " << l << ")" << " на поле (" << m << ", " << n << ")." << endl;
		cout << endl;
	}

	else
	{
		cout << "ФЕРЗЬ может за 2 хода попасть с поля (" << k << ", " << l << ")" << " на поле (" << m << ", " << n << ")." << endl;

		if (k > m)
		{
			while (k != m)
			{
				k--;
				l--;
			}
		}

		else
		{
			while (k != m)
			{
				k++;
				l++;
			}
		}
		cout << "Первый ход на поле (" << k << ", " << l << ")" << endl;
		cout << endl;
	}

}

// ладья
else if (figure_2 == 2)
{
	if (k == m || l == n)
	{
		cout << "ЛАДЬЯ может за 1 ход попасть с поля (" << k << ", " << l << ")" << " на поле (" << m << ", " << n << ")." << endl;
		cout << endl;
	}

	else
	{
		cout << "ЛАДЬЯ может за 2 хода попасть с поля (" << k << ", " << l << ")" << " на поле (" << m << ", " << n << ")." << endl;

		if (k > m)
		{
			while (k != m)
			{
				k--;
			}
		}

		else
		{
			while (k != m)
			{
				k++;
			}
		}
		cout << "Первый ход на поле (" << k << ", " << l << ")\n" << endl;
	}
}

// слон
else if (figure_2 == 3)
{
	if (abs(k - m) == abs(l - n))
	{
		cout << "СЛОН может за 1 ход попасть с поля (" << k << ", " << l << ")" << " на поле (" << m << ", " << n << ")." << endl;
		cout << endl;
	}

	else if (board[amount - k][l - 1] != board[amount - m][n - 1])
	{
		cout << "СЛОН не может попасть с поля (" << k << ", " << l << ")" << " на поле (" << m << ", " << n << ")." << endl;
		cout << endl;
	}

	else
	{
		cout << "СЛОН может за 2 хода попасть с поля (" << k << ", " << l << ")" << " на поле (" << m << ", " << n << ")." << endl;

		if (k > m)
		{
			while (abs(k - m) != abs(l - n))
			{
				k--;
				l--;
			}
		}

		else
		{
			while (abs(k - m) != abs(l - n))
			{
				k++;
				l++;
			}
		}
		cout << "Первый ход на поле (" << k << ", " << l << ")\n" << endl;
	}
}

return 0;
}