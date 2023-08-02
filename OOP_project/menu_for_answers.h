#pragma once

void menu_print(char** arr, int a, int size);

string menu_for_answers(Answer answers)
{
	char** mymenu = new char* [4];

	mymenu[0] = new char[answers.get_first().length() + 1];
	strcpy(mymenu[0], answers.get_first().c_str());
	mymenu[1] = new char[answers.get_second().length() + 1];
	strcpy(mymenu[1], answers.get_second().c_str());
	mymenu[2] = new char[answers.get_third().length() + 1];
	strcpy(mymenu[2], answers.get_third().c_str());
	mymenu[3] = new char[answers.get_fourth().length() + 1];
	strcpy(mymenu[3], answers.get_fourth().c_str());

	int input;
	int a = 0, b = 0;
	while (true)
	{
		

		mymenu[a][b] = '>';


		menu_print(mymenu, a, 4);
		input = _getch();
		if (input == 224)
		{
			input = _getch();
			if (int(input) == 72)
			{
				if (a == 0)
				{
					mymenu[a][b] = ' ';
					a = 3;
				}
				else
				{
					a--;
					mymenu[a + 1][b] = ' ';
				}

			}
			else if (int(input) == 80)
			{

				if (a == 3)
				{
					mymenu[a][b] = ' ';
					a = 0;
				}
				else
				{
					a++;
					mymenu[a - 1][b] = ' ';
				}
			}

			if (a == -1 && int(input) == 72)
			{
				a = 0;
				mymenu[a][b] = ' ';
				a = 3;
			}
			if (a == 4 && int(input) == 80)
			{
				a = 3;
				mymenu[a][b] = ' ';
				a = 0;
			}
		}
		else if (input == 87)
		{
			if (a == 0)
			{
				mymenu[a][b] = ' ';
				a = 3;
			}
			else
			{
				a--;
				mymenu[a + 1][b] = ' ';
			}
		}
		else if (input == 83)
		{
			if (a == 3)
			{
				mymenu[a][b] = ' ';
				a = 0;
			}
			else
			{
				a++;
				mymenu[a - 1][b] = ' ';
			}
		}
		else if (input == '\r')
		{
			string answer_choice = mymenu[a];
			return answer_choice;
		}
	}
}