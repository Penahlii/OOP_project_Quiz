#pragma once


void admin_menu(Data_Base*& data_base, All_Quizes& all_quizes)
{
	char** mymenu = new char* [4];

	mymenu[0] = new char[] {"  Create Quiz"};
	mymenu[1] = new char[] {"  Delete User"};
	mymenu[2] = new char[] {"  See All Users"};
	mymenu[3] = new char[] {"  Exit"};

	int input;
	int a = 0, b = 0;
	while (true)
	{
		system("cls");

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
			if (a == 0)
			{
				system("cls");
				string quiz_name;
				cout << "Enter Quiz Name: ";
				cin >> quiz_name;

				vector<Question> questions;

				char** mymenu = new char* [3];

				mymenu[0] = new char[] {"  New"};
				mymenu[1] = new char[] {"  Back"};
				mymenu[2] = new char[] {"  Save"};

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
							system("cls");
							string question;
							string answer_1;
							string answer_2;
							string answer_3;
							string answer_4;
							string correct_answer;
							cin.ignore();
							cout << "Enter Question: ";
							getline(cin, question);
							cout << "Enter First Answer: ";
							getline(cin, answer_1);
							cout << "Enter Second Answer: ";
							getline(cin, answer_2);
							cout << "Enter Third Answer: ";
							getline(cin, answer_3);
							cout << "Enter Fourth Answer: ";
							getline(cin, answer_4);
							cout << "Correct Answer (1-4): ";
							int duz;
							cin >> duz;
							if (duz == 1)
								correct_answer = answer_1;
							else if (duz == 2)
								correct_answer = answer_2;
							else if (duz == 3)
								correct_answer = answer_3;
							else if (duz == 4)
								correct_answer = answer_4;
							else
								throw InvalidArugmentException("Incorrect Choice", __DATE__, __TIME__, __FILE__, __LINE__);
							Answer new_answers(answer_1, answer_2, answer_3, answer_4, correct_answer);
							Question new_question(question, new_answers);
							questions.push_back(new_question);
						}
						else if (a == 1)
							break;
						else if (a == 2)
						{
							Quiz new_quiz(quiz_name, questions);
							all_quizes.Quizes.push_back(quiz_name);
							new_quiz.save_to_file();
							all_quizes.write_to_file();
							break;
						}
					}
				}
			}
			else if (a == 1)
			{
				system("cls");
				string email, password;
				cout << "Enter User's Email: ";
				cin >> email;
				cout << "Enter User's Password: ";
				cin >> password;

				system("cls");

				try
				{
					data_base->delete_user(email, password);
					cout << "User Deleted Succesfully !!";
					Sleep(3000);
				}
				catch (exception& ex)
				{
					cout << ex.what();
					Sleep(5000);
				}
			}
			else if (a == 2)
			{
				system("cls");
				data_base->show_all_users();
				Sleep(7000);
			}
			else if (a == 3)
				break;
		}
	}
}



int sign_in_sign_up_menu()
{
	char** mymenu = new char* [3];

	mymenu[0] = new char[] {"  Sing In"};
	mymenu[1] = new char[] {"  Sign Up"};
	mymenu[2] = new char[] {"  Exit"};
	int input;
	int a = 0, b = 0;
	while (true)
	{
		system("cls");

		mymenu[a][b] = '>';


		menu_print(mymenu, a ,3);
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
				return 0;
			else if (a == 1)
				return 1;
			else if (a == 2)
				break;
		}
	}
}


void boss_admin_menu(Data_Base*& data_base)
{
	char** mymenu = new char* [4];

	mymenu[0] = new char[] {"  Add Admin"};
	mymenu[1] = new char[] {"  Delete Admin"};
	mymenu[2] = new char[] {"  Show All Admins"};
	mymenu[3] = new char[] {"  Exit"};
	int input;
	int a = 0, b = 0;
	while (true)
	{
		system("cls");

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
			if (a == 0)
			{
				system("cls");
				string name, surname, email, password; ushort age;
				cout << "Enter New Admin's Name: ";
				cin >> name;
				cout << "Enter New Admin's Surname: ";
				cin >> surname;
				cout << "Enetr New Admin's Age: ";
				cin >> age;
				cout << "Enter New Admin's Email: ";
				cin >> email;
				cout << "Enter New Admin's Password: ";
				cin >> password;
				system("cls");
				try
				{
					Admin* new_admin = new Admin(name, surname, age, email, password);
					data_base->add_admin(new_admin);
					cout << "Admin Addes Succesfully !!";
					Sleep(3000);
				}
				catch (exception& ex)
				{
					cout << ex.what();
					Sleep(5000);
				}
			}
			else if (a == 1)
			{
				system("cls");
				string email, password;
				cout << "Enter Admin's Email: ";
				cin >> email;
				cout << "Ener Admin's Password: ";
				cin >> password;
				system("cls");
				try
				{
					data_base->delete_admin(email, password);
					cout << "Admin Deleted Succesfully !!";
					Sleep(3000);
				}
				catch (exception& ex)
				{
					cout << ex.what();
					Sleep(5000);
				}
			}
			else if (a == 2)
			{
				system("cls");
				data_base->show_all_admins();
				Sleep(5000);
			}
			else if (a == 3)
			{
				break;
			}
		}
	}
}


void main_menu(Data_Base*& data_base, Registration& registration, Boss_Admin* boss_admin, All_Quizes& all_quizes)
{
	char** mymenu = new char* [4];

	mymenu[0] = new char[] {"  Sign In As Boss Admin"};
	mymenu[1] = new char[] {"  Sign In As Admin"};
	mymenu[2] = new char[] {"  Register As User"};
	mymenu[3] = new char[] {"  Exit "};

	int input;
	int a = 0, b = 0;
	while (true)
	{
		system("cls");

		mymenu[a][b] = '>';


		menu_print(mymenu, a ,4);
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
			if (a == 0)
			{
				system("cls");
				string email, password;
				cout << "Enter Email: ";
				cin >> email;
				cout << "Enter Password: ";
				cin >> password;
				if (email == boss_admin->getEmail() && password == boss_admin->getPassword())
				{
					boss_admin_menu(data_base);
				}
				else
				{
					try
					{
						system("cls");
						throw DataBaseException("Wrong Email or Password", __DATE__, __TIME__, __FILE__, __LINE__);
					}
					catch (exception& ex)
					{
						cout << ex.what();
						Sleep(5000);
					}
				}
			}
			else if (a == 1)
			{
				system("cls");
				string email, password;
				cout << "Enter Email: ";
				cin >> email;
				cout << "Enter Password: ";
				cin >> password;
				system("cls");
				try
				{
					registration.sign_in_admin(email, password);
					admin_menu(data_base, all_quizes);
				}
				catch (exception& ex)
				{
					cout << ex.what();
					Sleep(5000);
				}
			}
			else if (a == 2)
			{
				int choice = sign_in_sign_up_menu();
				if (choice == 0)
				{
					system("cls");
					string email, password;
					cout << "Enter Email: ";
					cin >> email;
					cout << "Enter Password: ";
					cin >> password;
					User* current_user = nullptr;
					try
					{
						system("cls");
						current_user = registration.sign_in_user(email, password);

						user_menu(current_user, data_base, all_quizes);

						//cout << "Salam DostLarrrr"; /////////////////////////////////////////////////////////////////
						//Sleep(3000); ////////////////////////////////////////////////////
					}
					catch (exception& ex)
					{
						cout << ex.what();
						Sleep(5000);
					}
				}
				else if (choice == 1)
				{
					system("cls");
					string name, surname, email, password; ushort age;
					cout << "Enter Name: ";
					cin >> name;
					cout << "Enter Surname: ";
					cin >> surname;
					cout << "Enter Age: ";
					cin >> age;
					cout << "Enter Email: ";
					cin >> email;
					cout << "Enter Password: ";
					cin >> password;

					system("cls");
					try
					{
						User* new_user = new User(name, surname, age, email, password);
						registration.sign_up_user(new_user);
						cout << "Signed Up Succesfully !!";
						Sleep(3000);
					}
					catch (exception& ex)
					{
						cout << ex.what();
						Sleep(5000);
					}
				}
			}
			else if (a == 3)
			{
				system("cls");
				SetConsoleTextAttribute(console, 7);
				cout << "Good - Bye !!!";
				break;
			}
		}
	}
}