#include"Gaming.h"

void Game_process(char a[])
{
	std::ofstream fout;
	char out[4];
	int count1 = 0;
	int count2 = 0;
	int count3 = 0;
	int count4 = 0;
	int count = 0;
	std::cout << "Угадайте число(четырёхзначное)" << std::endl;
	while (true)
	{
		fout.open("logs.txt", std::ofstream::app);
		count1 = 0;
		count2 = 0;
		count3 = 0;
		count4 = 0;
		count = 0;
		std::cin >> out;
		for (size_t i = 0; i < 4; i++)
		{
			if (a[i] == out[i])
			{
				++count;
			}
			if (out[i] == a[0])
			{
				++count1;
				if (count1 > 1)
				{
					count1 = 1;
				}
			}
			else if (out[i] == a[1])
			{
				++count2;
				if (count2 > 1)
				{
					count2 = 1;
				}
			}
			else if (out[i] == a[2])
			{
				++count3;
				if (count3 > 1)
				{
					count3 = 1;
				}
			}
			else if (out[i] == a[3])
			{
				++count4;
				if (count4 > 1)
				{
					count4 = 1;
				}
			}
		}
		if (count == 4)
		{
			std::cout << "****Вы Угадали!****" << std::endl;
			fout << out << "****Вы Угадали!****\n";
			fout.close();
			break;
		}
		else
		{
			std::cout << "Ваш вариант -> " << out << "Угадано: " << count1+count2 + count3 + count4 << ". " << "На своих местах: " << count << '.' << std::endl;
			fout << "Ваш вариант -> " << out << "Угадано: " << count1 + count2 + count3 + count4 << ". " << "На своих местах: " << count << '.' << '\n';
			fout.close();
		}
	}
}
