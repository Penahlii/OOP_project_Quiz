#pragma once

class Registration
{
	Data_Base* data_base;

public:
	
	// Constructor

	Registration() {}
	Registration(Data_Base* data_base) { this->data_base = data_base; }

	// Sign In Admin

	Admin* sign_in_admin(string email, string password)
	{
		bool check_email = true;
		for (size_t i = 0; i < this->data_base->admins_count; i++)
		{
			if (this->data_base->admins[i]->getEmail() == email)
			{
				check_email = false;
				if (this->data_base->admins[i]->getPassword() == password)
					return this->data_base->admins[i];
			}
		}
		if (check_email)
			throw DataBaseException("Incorrect Email", __DATE__, __TIME__, __FILE__, __LINE__);
		throw DataBaseException("Incorrect Password", __DATE__, __TIME__, __FILE__, __LINE__);
	}

	// Sign Up Admin

	void sign_up_admin(Admin* new_admin) { this->data_base->add_admin(new_admin); }

	// Sign In User

	User* sign_in_user(string email, string password)
	{
		bool check_email = true;
		for (size_t i = 0; i < this->data_base->users_count; i++)
		{
			if (this->data_base->users[i]->getEmail() == email) 
			{
				check_email = false;
				if (this->data_base->users[i]->getPassword() == password)
					return this->data_base->users[i];
			}
		}
		if (check_email)
			throw DataBaseException("Incorrect Email", __DATE__, __TIME__, __FILE__, __LINE__);
		throw DataBaseException("Incorrect Password", __DATE__, __TIME__, __FILE__, __LINE__);
	}

	// Sign Up User

	void sign_up_user(User* new_user) { this->data_base->add_user(new_user); }

	// Destructor

	~Registration()
	{
		if (this->data_base != nullptr)
			delete this->data_base;
	}
};