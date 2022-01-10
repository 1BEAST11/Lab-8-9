#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

// дата и время
void date_time()
{
	time_t now = time(0);
	char* dt = ctime(&now);
	ofstream file("log.txt", ios_base::app);
	file << dt;
}

// одновременная запись
void dual_write(const string& text) 
{
	// вывод в консоль
	cout << text;

	// запись в файл
	ofstream file("log.txt", ios_base::app);
	if (text == "\n")
	{
		file << text;
	}

	else
	{
		file << "OUTPUT: " << text;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	const int amount = 8;
	char board[amount][amount] = {};
	int k, l = 0, m, n = 0;
	int figure = 0, figure_2 = 0;

	ofstream file("log.txt", ios_base::app);

	//создание двумерного массива
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

	// вертикаль первого поля
	while (true)
	{
		date_time();
		dual_write("Введите номер вертикали ПЕРВОГО поля (ЦЕЛОЕ число от 1 до 8): \n");

		cin >> k;
		dual_write("\n");
		date_time();
		file << "INPUT: " << k << "\n" << endl;

		// обработка ввода неверного типа данных
		if (cin.fail() || cin.get() != '\n')
		{
			date_time();
			dual_write("Некорректный ввод. Повторите попытку.\n\n");
			cin.clear();
			cin.ignore(1000, '\n');
		}

		// обработка ввода числа, выходящего за пределы диапазона
		else if (k < 1 || k > 8)
		{
			date_time();
			dual_write("Номер должен находиться в диапазоне от 1-8. Повторите попытку.\n\n");
		}

		else
		{
			break;
		}
	}

	// горизонталь первого поля
	while (true)
	{
		date_time();
		dual_write("Введите номер горизонтали ПЕРВОГО поля (ЦЕЛОЕ число от 1 до 8): \n");

		cin >> l;
		dual_write("\n");
		date_time();
		file << "INPUT: " << l << "\n" << endl;

		// обработка ввода неверного типа данных
		if (cin.fail() || cin.get() != '\n')
		{
			date_time();
			dual_write("Некорректный ввод. Повторите попытку.\n\n");
			cin.clear();
			cin.ignore(1000, '\n');
		}

		// обработка ввода числа, выходящего за пределы диапазона
		else if (l < 1 || l > 8)
		{
			date_time();
			dual_write("Номер должен находиться в диапазоне от 1-8. Повторите попытку.\n\n");
			cout << endl;
		}

		else
		{
			break;
		}
	}

	// вертикаль второго поля
	while (true)
	{
		date_time();
		dual_write("Введите номер вертикали ВТОРОГО поля (ЦЕЛОЕ число от 1 до 8): \n");

		cin >> m;
		dual_write("\n");
		date_time();
		file << "INPUT: " << m << "\n" << endl;

		// обработка ввода неверного типа данных
		if (cin.fail() || cin.get() != '\n')
		{
			date_time();
			dual_write("Некорректный ввод. Повторите попытку.\n\n");
			cin.clear();
			cin.ignore(1000, '\n');
		}

		// обработка ввода числа, выходящего за пределы диапазона
		else if (m < 1 || m > 8)
		{
			date_time();
			dual_write("Номер должен находиться в диапазоне от 1-8. Повторите попытку.\n\n");
			cout << endl;
		}

		else
		{
			break;
		}
	}

	// горизонталь второго поля
	while (true)
	{
		date_time();
		dual_write("Введите номер горизонтали ВТОРОГО поля (ЦЕЛОЕ число от 1 до 8): \n");

		cin >> n;
		dual_write("\n");
		date_time();
		file << "INPUT: " << n << "\n" << endl;

		// обработка ввода неверного типа данных
		if (cin.fail() || cin.get() != '\n')
		{
			date_time();
			dual_write("Некорректный ввод. Повторите попытку.\n\n");
			cin.clear();
			cin.ignore(1000, '\n');
		}

		// обработка ввода числа, выходящего за пределы диапазона
		else if (n < 1 || n > 8)
		{
			date_time();
			dual_write("Номер должен находиться в диапазоне от 1-8. Повторите попытку.\n\n");
			cout << endl;
		}

		else
		{
			break;
		}
	}

	// проверка на совпадение цветов
	if (board[amount - k][l - 1] == board[amount - m][n - 1])
	{
		cout << "Цвета полей с координатами (" << k << ", " << l << ")" << " и (" << m << ", " << n << ") НЕ совпадают" << endl;
		date_time();
		file << "OUTPUT: " << "Цвета полей с координатами (" << k << ", " << l << ")" << " и (" << m << ", " << n << ") НЕ совпадают\n" << endl;
	}

	else
	{
		cout << "Цвета полей с координатами (" << k << ", " << l << ")" << " и (" << m << ", " << n << ") НЕ совпадают" << endl;
		date_time();
		file << "OUTPUT: " << "Цвета полей с координатами (" << k << ", " << l << ")" << " и (" << m << ", " << n << ") НЕ совпадают\n" << endl;
	}

	// проверка, угрожает ли фигура полю
	while (true)
	{
		cout << endl;
		date_time();
		dual_write("Для определения угрозы укажите фигуру, стоящую на ПЕРВОМ поле (нажмите 1 - для ФЕРЗЯ, 2 - для ЛАДЬИ, 3 - для СЛОНА, 4 - для КОНЯ): \n");

		cin >> figure;
		dual_write("\n");
		date_time();
		file << "INPUT: " << figure << "\n" << endl;

		// обработка ввода неверного типа данных
		if (cin.fail() || cin.get() != '\n')
		{
			date_time();
			dual_write("Некорректный ввод. Повторите попытку.\n");
			cin.clear();
			cin.ignore(1000, '\n');
		}

		// обработка ввода не того числа
		else if (figure < 1 || figure > 4)
		{
			cout << endl;
			date_time();
			dual_write("Введено неверное число. Введите число 1, 2, 3 или 4.\n");
		}

		else
		{
			break;
		}
	}

	// ферзь
	if (figure == 1)
	{
		if (k == m || l == n || abs(k - m) == abs(l - n))
		{
			cout << "ФЕРЗЬ на поле (" << k << ", " << l << ")" << " угрожает полю (" << m << ", " << n << ")." << endl;
			date_time();
			file << "OUTPUT: " << "ФЕРЗЬ на поле (" << k << ", " << l << ")" << " угрожает полю (" << m << ", " << n << ").\n" << endl;
		}

		else
		{
			cout << "ФЕРЗЬ на поле (" << k << ", " << l << ")" << " НЕ угрожает полю (" << m << ", " << n << ")." << endl;
			date_time();
			file << "OUTPUT: " << "ФЕРЗЬ на поле (" << k << ", " << l << ")" << " НЕ угрожает полю (" << m << ", " << n << ").\n" << endl;
		}
	}

	// ладья
	else if (figure == 2)
	{
		if (k == m || l == n)
		{
			cout << "ЛАДЬЯ на поле (" << k << ", " << l << ")" << " угрожает полю (" << m << ", " << n << ")." << endl;
			date_time();
			file << "OUTPUT: " << "ЛАДЬЯ на поле (" << k << ", " << l << ")" << " угрожает полю (" << m << ", " << n << ").\n" << endl;
		}

		else
		{
			cout << "ЛАДЬЯ на поле (" << k << ", " << l << ")" << " НЕ угрожает полю (" << m << ", " << n << ")." << endl;
			date_time();
			file << "OUTPUT: " << "ЛАДЬЯ на поле (" << k << ", " << l << ")" << " НЕ угрожает полю (" << m << ", " << n << ").\n" << endl;
		}
	}

	// слон
	else if (figure == 3)
	{
		if (abs(k - m) == abs(l - n))
		{
			cout << "СЛОН на поле (" << k << ", " << l << ")" << " угрожает полю (" << m << ", " << n << ")." << endl;
			date_time();
			file << "OUTPUT: " << "СЛОН на поле (" << k << ", " << l << ")" << " угрожает полю (" << m << ", " << n << ").\n" << endl;
		}

		else
		{
			cout << "СЛОН на поле (" << k << ", " << l << ")" << " НЕ угрожает полю (" << m << ", " << n << ")." << endl;
			date_time();
			file << "OUTPUT: " << "СЛОН на поле (" << k << ", " << l << ")" << " НЕ угрожает полю (" << m << ", " << n << ").\n" << endl;
		}
	}

	// конь
	else if (figure == 4)
	{
		if ((abs(k - m) == 1 && abs(l - n) == 2) || (abs(k - m) == 2 && abs(l - n) == 1))
		{
			cout << "КОНЬ на поле (" << k << ", " << l << ")" << " угрожает полю (" << m << ", " << n << ")." << endl;
			date_time();
			file << "OUTPUT: " << "КОНЬ на поле (" << k << ", " << l << ")" << " угрожает полю (" << m << ", " << n << ").\n" << endl;
		}

		else
		{
			cout << "КОНЬ на поле (" << k << ", " << l << ")" << " НЕ угрожает полю (" << m << ", " << n << ")." << endl;
			date_time();
			file << "OUTPUT: " << "КОНЬ на поле (" << k << ", " << l << ")" << " НЕ угрожает полю (" << m << ", " << n << ").\n" << endl;
		}
	}

	cout << endl;
	// проверка на количество ходов
	while (true)
	{		
		date_time();
		dual_write("Для определения необходимого количества ходов укажите фигуру, стоящую на ПЕРВОМ поле (нажмите 1 - для ФЕРЗЯ, 2 - для ЛАДЬИ, 3 - для СЛОНА): \n");
		
		cin >> figure_2;
		dual_write("\n");
		date_time();
		file << "INPUT: " << figure_2 << "\n" << endl;

		// обработка ввода неверного типа данных
		if (cin.fail() || cin.get() != '\n')
		{
			date_time();
			dual_write("Некорректный ввод. Повторите попытку.\n\n");
			cin.clear();
			cin.ignore(1000, '\n');
		}

		// обработка ввода не того числа
		else if (figure_2 < 1 || figure_2 > 3)
		{
			date_time();
			dual_write("Введено неверное число. Введите число 1, 2 или 3.\n\n");
		}

		else
		{
			break;
		}
	}

	// ферзь
	if (figure_2 == 1)
	{
		// 1 ход
		if (k == m || l == n || abs(k - m) == abs(l - n))
		{
			cout << "ФЕРЗЬ может за 1 ход попасть с поля (" << k << ", " << l << ")" << " на поле (" << m << ", " << n << ")." << endl;
			date_time();
			file << "OUTPUT: " << "ФЕРЗЬ может за 1 ход попасть с поля (" << k << ", " << l << ")" << " на поле (" << m << ", " << n << ").\n" << endl;
			cout << endl;
		}

		// 2 хода
		else
		{
			cout << "ФЕРЗЬ может за 2 хода попасть с поля (" << k << ", " << l << ")" << " на поле (" << m << ", " << n << ")." << endl;
			date_time();
			file << "OUTPUT: " << "ФЕРЗЬ может за 2 хода попасть с поля (" << k << ", " << l << ")" << " на поле (" << m << ", " << n << ").\n" << endl;

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
			date_time();
			file << "OUTPUT: " << "Первый ход на поле (" << k << ", " << l << ")\n" << endl;
			cout << endl;
		}

	}

	// ладья
	else if (figure_2 == 2)
	{
		// 1 ход
		if (k == m || l == n)
		{
			cout << "ЛАДЬЯ может за 1 ход попасть с поля (" << k << ", " << l << ")" << " на поле (" << m << ", " << n << ")." << endl;
			date_time();
			file << "OUTPUT: " << "ЛАДЬЯ может за 1 ход попасть с поля (" << k << ", " << l << ")" << " на поле (" << m << ", " << n << ").\n" << endl;
			cout << endl;
		}

		// 2 хода
		else
		{
			cout << "ЛАДЬЯ может за 2 хода попасть с поля (" << k << ", " << l << ")" << " на поле (" << m << ", " << n << ")." << endl;
			date_time();
			file << "OUTPUT: " << "ЛАДЬЯ может за 2 хода попасть с поля (" << k << ", " << l << ")" << " на поле (" << m << ", " << n << ").\n" << endl;

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
			date_time();
			file << "OUTPUT: " << "Первый ход на поле (" << k << ", " << l << ")\n" << endl;
		}
	}

	// слон
	else if (figure_2 == 3)
	{
		// 1 ход
		if (abs(k - m) == abs(l - n))
		{
			cout << "СЛОН может за 1 ход попасть с поля (" << k << ", " << l << ")" << " на поле (" << m << ", " << n << ")." << endl;
			date_time();
			file << "OUTPUT: " << "СЛОН может за 1 ход попасть с поля (" << k << ", " << l << ")" << " на поле (" << m << ", " << n << ").\n" << endl;
			cout << endl;
		}

		// не может попасть
		else if (board[amount - k][l - 1] != board[amount - m][n - 1])
		{
			cout << "СЛОН не может попасть с поля (" << k << ", " << l << ")" << " на поле (" << m << ", " << n << ")." << endl;
			date_time();
			file << "OUTPUT: " << "СЛОН не может попасть с поля (" << k << ", " << l << ")" << " на поле (" << m << ", " << n << ").\n" << endl;
			cout << endl;
		}

		// 2 хода
		else
		{
			cout << "СЛОН может за 2 хода попасть с поля (" << k << ", " << l << ")" << " на поле (" << m << ", " << n << ")." << endl;
			date_time();
			file << "OUTPUT: " << "СЛОН может за 2 хода попасть с поля (" << k << ", " << l << ")" << " на поле (" << m << ", " << n << ").\n" << endl;

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
			date_time();
			file << "OUTPUT: " << "Первый ход на поле (" << k << ", " << l << ")\n" << endl;
		}
	}
	file.close();
	return 0;
}