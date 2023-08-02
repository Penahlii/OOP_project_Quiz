#pragma once


HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);



void menu_print(char** arr, int a, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		if (i == a)
			SetConsoleTextAttribute(console, 10);
		else
			SetConsoleTextAttribute(console, 7);
		cout << arr[i] << endl;
	}
}


void user_menu(User*& user, Data_Base* data_base, All_Quizes& all_quizes)
{
	char** mymenu = new char* [3];

	mymenu[0] = new char[] {"  Start Quiz"};
	mymenu[1] = new char[] {"  LeaderBoard"};
	mymenu[2] = new char[] {"  Exit"};
	int input;
	int a = 0, b = 0;
	while (true)
	{
		system("cls");

		mymenu[a][b] = '>';


		menu_print(mymenu, a, 3);
		input = _getch();
		if (input == 224)
		{
			input = _getch();
			if (int(input) == 72)
			{
				if (a == 0)
				{
					mymenu[a][b] = ' ';
					a = 2;
				}
				else
				{
					a--;
					mymenu[a + 1][b] = ' ';
				}

			}
			else if (int(input) == 80)
			{

				if (a == 2)
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
				a = 2;
			}
			if (a == 3 && int(input) == 80)
			{
				a = 2;
				mymenu[a][b] = ' ';
				a = 0;
			}
		}
		else if (input == 87)
		{
			if (a == 0)
			{
				mymenu[a][b] = ' ';
				a = 2;
			}
			else
			{
				a--;
				mymenu[a + 1][b] = ' ';
			}
		}
		else if (input == 83)
		{
			if (a == 2)
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
			if (a == 0)
			{
				for (size_t i = 0; i < all_quizes.Quizes.size(); i++)
				{
					cout << all_quizes.Quizes[i] << endl;
				}
				cout << endl;
				cout << endl;
				string quiz_wanted;
				cout << "Enter Quiz Name Correctly: ";
				cin >> quiz_wanted;
				string question;
				string answer1;
				string answer2;
				string answer3;
				string answer4;
				string correct_answer;

				vector<Question> questions;
				

				ifstream file(quiz_wanted + ".txt");
				if (file.is_open())
				{
					/*do
					{
						file >> question;
						char symbol;
						string content;
						while (file.get(symbol))
						{
							if (symbol == '?')
								break;
							content += symbol;
						}
						if (!file.eof())
						{
							file >> answer1;
							file >> answer2;
							file >> answer3;
							file >> answer4;
							file >> correct_answer;

							Answer answers(answer1, answer2, answer3, answer4, correct_answer);
							Question new_question(question, answers);
							questions.push_back(new_question);
						}
					} while (!file.eof() && question.length() >= 1);*/
					if (!file.eof())
					{
						while (std::getline(file, question, '?')) {
						char nextChar;
						// Read and discard any remaining characters until newline '\n'
						while (file.get(nextChar) && nextChar != '\n') {}

						if (file >> answer1 >> answer2 >> answer3 >> answer4 >> correct_answer) {
							Answer answers(answer1, answer2, answer3, answer4, correct_answer);
							Question new_question(question + '?', answers);
							questions.push_back(new_question);
						}
					}
					}
						file.close();
				}

				system("cls");

				Quiz current(quiz_wanted, questions);


				for (size_t i = 0; i < current.questions.size(); i++)
				{
					cout << current.questions[i].get_question() << endl;
				}

				Sleep(5000);

				/*for (size_t i = 0; i < questions.size(); i++)
				{
					cout << questions[i].get_question() << endl << endl;
					cout << questions[i].get_answers().get_first() << endl;
					cout << questions[i].get_answers().get_second() << endl;
					cout << questions[i].get_answers().get_third() << endl;
					cout << questions[i].get_answers().get_fourth() << endl;

					string answer_choice;

					cout << "Enter Your Answer: ";

					cin.ignore();
					getline(cin, answer_choice);

					if (answer_choice == questions[i].get_answers().get_correct_answer())
						user->subtotal += 1;

					system("cls");
				}*/
			}
			else if (a == 1)
			{
				system("cls");
				LeaderBoard a;
				a.Top10(data_base);
				Sleep(3000);
			}
			else if (a == 2)
				break;
		}
	}
}