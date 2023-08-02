#pragma once

class Data_Base
{

	Admin** admins;
	int admins_count;
	User** users;
	int users_count;
	string file_name_admins = "data_base_of_admins.txt";
	string file_name_users = "data_base_of_users.txt";

public:

	// Write to Files

	void write_to_file_admins();
	void write_to_file_users();

	// Constructors

	Data_Base() {}
	Data_Base(Admin** admins, int admins_count, User** users, int user_count)
	{
		this->set_admins(admins, admins_count);
		this->set_users(users, user_count);
	}


	// Set Methods

	void set_admins(Admin** admins, int admins_count);
	void set_users(User** users, int users_count);

	// Add User

	void add_user(User* new_user);

	// Add Admin

	void add_admin(Admin* new_admin);

	// Delete User

	void delete_user(string email, string password);

	// Delete Admin

	void delete_admin(string email, string password);

	// Get Admin By Email

	Admin* get_admin_by_email(string email);

	// Get User By Email

	User* get_user_by_email(string email);

	// Get Methods

	inline string get_file_of_admins() const noexcept { return this->file_name_admins; }
	inline string get_file_of_users() const noexcept { return this->file_name_users; } 
	inline int get_users_count() const noexcept { return this->users_count; }
	inline int get_admins_count() const noexcept { return this->admins_count; }

	// friend classes
	
	friend class Registration;
	friend class LeaderBoard;

	// Destructor

	~Data_Base();

	// Program Start

	void program_start_1();
	void program_start_2();

	// show

	void show_all_admins();
	void show_all_users();
};





void Data_Base::write_to_file_admins()
{
	ofstream file(this->file_name_admins);
	if (file.is_open())
	{
		for (size_t i = 0; i < this->admins_count; i++)
			file << this->admins[i]->get_all();
		file.close();
	}
	else
		throw InvalidArugmentException("Unable to Open File", __DATE__, __TIME__, __FILE__, __LINE__);
}

void Data_Base::write_to_file_users()
{
	ofstream file(this->file_name_users);
	if (file.is_open())
	{
		for (size_t i = 0; i < this->users_count; i++)
			file << this->users[i]->get_all();
		file.close();
	}
	else
		throw InvalidArugmentException("Unable to Open File", __DATE__, __TIME__, __FILE__, __LINE__);
}

void Data_Base::set_admins(Admin** admins, int admins_count)
{
	if (admins != nullptr)
	{
		if (this->admins != nullptr)
		{
			for (size_t i = 0; i < this->admins_count; i++)
				delete this->admins[i];
			delete[] this->admins;
		}
		this->admins = new Admin * [admins_count];
		for (size_t i = 0; i < admins_count; i++)
			this->admins[i] = admins[i];
		this->admins_count = admins_count;
		this->write_to_file_admins();
	}
	else
		throw InvalidArugmentException("NULL Parametr", __DATE__, __TIME__, __FILE__, __LINE__);
}

void Data_Base::set_users(User** users, int users_count)
{
	if (users != nullptr)
	{
		if (this->users != nullptr)
		{
			for (size_t i = 0; i < this->users_count; i++)
				delete this->users[i];
			delete[] this->users;
		}
		this->users = new User * [users_count];
		for (size_t i = 0; i < users_count; i++)
			this->users[i] = users[i];
		this->users_count = users_count;
		this->write_to_file_users();
	}
	else
		throw InvalidArugmentException("NULL Parametr", __DATE__, __TIME__, __FILE__, __LINE__);
}

void Data_Base::add_user(User* new_user)
{
	for (size_t i = 0; i < this->users_count; i++)
	{
		if (new_user->getEmail() == this->users[i]->getEmail())
			throw DataBaseException("Email Exists. Try new One", __DATE__, __TIME__, __FILE__, __LINE__);
		if (new_user->getPassword() == this->users[i]->getPassword())
			throw DataBaseException("Password Exists. Try new One", __DATE__, __TIME__, __FILE__, __LINE__);
	}
	User** new_users = new User * [this->users_count + 1];
	for (size_t i = 0; i < this->users_count; i++)
		new_users[i] = this->users[i];
	new_users[this->users_count] = new_user;
	this->users_count++;
	delete[] this->users;
	this->users = new_users;
	this->write_to_file_users();
}

void Data_Base::add_admin(Admin* new_admin)
{
	for (size_t i = 0; i < this->admins_count; i++)
	{
		if (new_admin->getEmail() == this->admins[i]->getEmail())
			throw DataBaseException("Email Exists. Try new One", __DATE__, __TIME__, __FILE__, __LINE__);
		if (new_admin->getPassword() == this->admins[i]->getPassword())
			throw DataBaseException("Password Exists. Try new One", __DATE__, __TIME__, __FILE__, __LINE__);
	}
	Admin** new_admins = new Admin * [this->admins_count + 1];
	for (size_t i = 0; i < this->admins_count; i++)
		new_admins[i] = this->admins[i];
	new_admins[this->admins_count] = new_admin;
	this->admins_count++;
	delete[] this->admins;
	this->admins = new_admins;
	this->write_to_file_admins();
}

void Data_Base::delete_user(string email, string password)
{
	for (size_t i = 0; i < this->users_count; i++)
	{
		if (this->users[i]->getEmail() == email && this->users[i]->getPassword() == password)
		{
			User** new_users = new User * [this->users_count - 1];
			for (size_t j = 0; j < i; j++)
				new_users[j] = this->users[j];
			for (size_t b = i; b < this->users_count; b++)
				new_users[b] = this->users[b + 1];
			this->users_count--;
			delete[] this->users;
			this->users = new_users;
			this->write_to_file_users();
			return;
		}
	}
	throw DataBaseException("Invalid Account Information", __DATE__, __TIME__, __FILE__, __LINE__);
}

void Data_Base::delete_admin(string email, string password)
{
	for (size_t i = 0; i < this->admins_count; i++)
	{
		if (this->admins[i]->getEmail() == email && this->admins[i]->getPassword() == password)
		{
			Admin** new_admins = new Admin * [this->admins_count - 1];
			for (size_t j = 0; j < i; j++)
				new_admins[j] = this->admins[j];
			for (size_t a = i; a < this->admins_count; a++)
				new_admins[a] = this->admins[a + 1];
			this->admins_count--;
			delete[] this->admins;
			this->admins = new_admins;
			this->write_to_file_admins();
			return;
		}
	}
	throw DataBaseException("Invalid Account Information", __DATE__, __TIME__, __FILE__, __LINE__);
}

Admin* Data_Base::get_admin_by_email(string email)
{
	for (size_t i = 0; i < this->admins_count; i++)
	{
		if (this->admins[i]->getEmail() == email)
			return this->admins[i];
	}
}

User* Data_Base::get_user_by_email(string email)
{
	for (size_t i = 0; i < this->users_count; i++)
	{
		if (this->users[i]->getEmail() == email)
			return this->users[i];
	}
}

Data_Base::~Data_Base()
{
	if (this->admins != nullptr)
	{
		for (size_t i = 0; i < this->admins_count; i++)
			delete this->admins[i];
		delete[] this->admins;
	}
	if (this->users != nullptr)
	{
		for (size_t i = 0; i < this->users_count; i++)
			delete this->users[i];
		delete[] this->users;
	}
}

// Program Start

void Data_Base::program_start_1()
{
	int count = 0;
	User** new_users = new User * [count];
	string name, surname, email, password; ushort age; int subtotal;
	ifstream file(this->file_name_users);
	if (file.is_open())
	{
		do
		{
			file >> name;
			if (!file.eof())
			{
				file >> surname;
				file >> age;
				file >> email;
				file >> password;
				file >> subtotal;
				User* new_user = new User(name, surname, age, email, password, subtotal);
				User** new_users_2 = new User * [count + 1];
				for (size_t i = 0; i < count; i++)
					new_users_2[i] = new_users[i];
				new_users_2[count] = new_user;
				count++;
				delete[] new_users;
				new_users = new_users_2;
			}
		} while (!file.eof() && name.length() >= 1);
		this->users = new_users;
		this->users_count = count;
		file.close();
	}
}

void Data_Base::program_start_2()
{
	int count = 0;
	Admin** new_admins = new Admin * [count];
	string name, surname, email, password; ushort age;
	ifstream file(this->file_name_admins);
	if (file.is_open())
	{
		do
		{
			file >> name;
			if (!file.eof())
			{
				file >> surname;
				file >> age;
				file >> email;
				file >> password;
				Admin* new_admin = new Admin(name, surname, age, email, password);
				Admin** new_admins_2 = new Admin * [count + 1];
				for (size_t i = 0; i < count; i++)
					new_admins_2[i] = new_admins[i];
				new_admins_2[count] = new_admin;
				count++;
				delete[] new_admins;
				new_admins = new_admins_2;
			}
		} while (!file.eof() && name.length() >= 1);
		this->admins = new_admins;
		this->admins_count = count;
		file.close();
	}
}

void Data_Base::show_all_admins()
{
	if (this->admins_count == 0)
		cout << "There is Not Any Admin Yet";
	for (size_t i = 0; i < this->admins_count; i++)
	{
		cout << i + 1 << ")" << endl;
		this->admins[i]->show();
	}
}

void Data_Base::show_all_users()
{
	if (this->users_count == 0)
		cout << "There is Not Any User Yet";
	for (size_t i = 0; i < this->users_count; i++)
	{
		cout << i + 1 << ")" << endl;
		this->users[i]->show();
	}
}