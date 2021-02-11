#include <conio.h>
#include <ctime>
#include"Gaming.h"
int main()
{
	int c,r,count;
	char in[5];
	setlocale(LC_ALL, "ru");
	std::ofstream fout;
	std::ifstream fin;
	while (true)
	{
		std::cout << "Играем-1, Загадываем новое чсло-2, Выход-3" << std::endl;
		c = _getch();
		switch (c)
		{
		case '1':
		{
			count = 0;
			srand(time(NULL));			fin.open("variants.txt");
			while (!fin.eof())
			{
				fin >> in;
				++count;
			}
			--count;
			fin.close();
			//r = rand() % count + 1;
			r = 1;
			fin.open("variants.txt");
			for (size_t i = 0; i < r; i++)
			{
				fin >> in;
			}
			fin.close();
			system("cls");
			Game_process(in);
			break;
		}
		case '2':
		{
			system("cls");
			std::cout << "Введите 4-х значное число" << std::endl;
			std::cin >> in;
			fout.open("variants.txt", std::ostream::app);
			fout << in << '\n';
			fout.close();
			system("cls");
			Game_process(in);
			break;
		}
		default:
			break;
		}
		if (c == '3')
		{
			break;
		}
	}
	system("pause");
	return 0;
}