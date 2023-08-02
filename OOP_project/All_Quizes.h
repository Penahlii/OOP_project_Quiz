#pragma once

class All_Quizes
{
public:

	vector<string> Quizes;
	string file_name = "All_Quizes.txt";

	// write to file

	void write_to_file()
	{
		ofstream file(this->file_name);
		if (file.is_open())
		{
			for (size_t i = 0; i < this->Quizes.size(); i++)
				file << this->Quizes[i];
			file.close();
		}
		else
			throw InvalidArugmentException("File Can Not Open", __DATE__, __TIME__, __FILE__, __LINE__);
	}

	// Program Start

	void program_start()
	{
		vector<string> NewQuizes;
		string nameQuiz;
		ifstream file(file_name);
		if (file.is_open())
		{
			do
			{
				file >> nameQuiz;
				NewQuizes.push_back(nameQuiz);
			} while (!file.eof() && nameQuiz.length() >= 1);
			file.close();
			this->Quizes = NewQuizes;
		}
	}

	// friend

	friend class Menu;
};