#pragma once

class Answer
{
	string first;
	string second;
	string third;
	string fourth;
	string correct_answer;

public:

	Answer() = default;
	Answer(string first, string second, string third, string fourth, string correct_answer) : first(first), second(second) , third(third) , fourth(fourth),correct_answer(correct_answer) {}

	// Get Methods

	inline string get_first() const { return this->first; }
	inline string get_second() const { return this->second; }
	inline string get_third() const { return this->third; }
	inline string get_fourth() const { return this->fourth; }
	inline string get_correct_answer() const { return this->correct_answer; }

	// Get All

	inline string get_all() const { return this->first + " " + this->second + " " + this->third + " " + this->fourth + " " + this->correct_answer; }
};



class Question
{
	string question;
	Answer answers;

public:

	Question(string question, Answer answers) : question(question), answers(answers) {}

	// Get Methods

	inline string get_question() const { return this->question; }
	inline Answer get_answers() const { return this->answers; }

	// Get All

	inline string get_all() const { return this->question + " " + this->answers.get_all() + "\n"; }
};



class Quiz
{

public:

	string quiz_name;
	string file_name;
	vector<Question> questions;



	Quiz() = default;
	Quiz(string quiz_name, vector<Question> questions) : quiz_name(quiz_name), questions(questions) { this->file_name = this->quiz_name + ".txt"; }

	// Start Quiz

	/*void start_quiz(string file_of_quiz)
	{
		vector<Question> all_quiz;
		string sual;
		string birinci_cavab;
		string ikinci_cavab;
		string ucuncu_cavab;
		string dorduncu_cavab;
		string dogru_cavab;
		ifstream file(file_of_quiz);
		if (file.is_open())
		{
			
			do
			{
				file >> sual;
				if (!file.eof())
				{
					file >> birinci_cavab;
					file >> ikinci_cavab;
					file >> ucuncu_cavab;
					file >> dorduncu_cavab;
					file >> dogru_cavab;
					Answer cavablar(birinci_cavab, ikinci_cavab, ucuncu_cavab, dorduncu_cavab, dogru_cavab);
					Question sual(sual, cavablar);
					all_quiz.push_back(sual);
				}
			} while (!file.eof() && sual.length() >= 1);
		}

		
		random_shuffle(all_quiz.begin(), all_quiz.end());
		

		for (size_t i = 0; i < all_quiz.size(); i++)
		{
			cout << all_quiz[i].get_question();

			cout << endl;
			cout << endl;

			menu_for_answers(all_quiz[i].get_answers());
		}
	}*/

	// Program Start

	void program_start()
	{
		vector<Question> questions;
		string question;
		string first;
		string second;
		string third;
		string fourth;
		string correct_answer;
		ifstream file(this->file_name);
		if (file.is_open())
		{
			do
			{
				file >> question;
				if (!file.eof())
				{
					file >> first;
					file >> second;
					file >> third;
					file >> fourth;
					file >> correct_answer;
					Answer answers(first, second, third, fourth, correct_answer);
					Question new_question(question, answers);
					questions.push_back(new_question);
				}
			} while (!file.eof() && question.length() >= 1);
			file.close();
			this->questions = questions;
		}
	}
	
	// Save To File

	void save_to_file()
	{
		ofstream file(this->file_name);
		if (file.is_open())
		{
			for (size_t i = 0; i < this->questions.size(); i++)
				file << this->questions[i].get_all();
			file.close();
		}
	}
};