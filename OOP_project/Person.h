#pragma once

class Person
{
	string name;
	string surname;
	ushort age;
	string email;
	string password;

public:

	Person() = default;
	Person(string name, string surname, ushort age, string email, string password) 
	{
		setName(name);
		setSurname(surname);
		setAge(age);
		setEmail(email);
		setPassword(password);
	}

	// Get Method

	inline string getName() const { return this->name; }
	inline string getSurname() const { return this->surname; }
	inline ushort getAge() const { return this->age; }
	inline string getEmail() const { return this->email; }
	inline string getPassword() const { return this->password; }

	// Set Methods

	void setName(string name)
	{
		if (name.length() >= 3 && isupper(name[0]))
			this->name = name;
		else
			throw InvalidArugmentException("Invalid Name", __DATE__, __TIME__, __FILE__, __LINE__);
	}

	void setSurname(string surname)
	{
		if (name.length() >= 4 && isupper(surname[0]))
			this->surname = surname;
		else
			throw InvalidArugmentException("Invalid Surname", __DATE__, __TIME__, __FILE__, __LINE__);
	}

	void setAge(ushort age)
	{
		if (age > 10 && age <= 65)
			this->age = age;
		else
			throw InvalidArugmentException("Invalid Age", __DATE__, __TIME__, __FILE__, __LINE__);
	}

	void setEmail(string email)
	{
		if (email.length() > 6 && email.length() <= 50)
			this->email = email;
		else
			throw InvalidArugmentException("Invalid Email", __DATE__, __TIME__, __FILE__, __LINE__);
	}

	void setPassword(string password)
	{
		if (password.length() >= 8 && password.length() <= 20)
			this->password = password;
		else
			throw InvalidArugmentException("Invalid Password", __DATE__, __TIME__, __FILE__, __LINE__);
	}

	// Show

	virtual void show() const
	{
		cout << "Name: " << this->name << endl;
		cout << "Surname: " << this->surname << endl;
		cout << "Age: " << this->age << endl;
		cout << "Email: " << this->email << endl;
	}

	// Get All

	virtual inline string get_all() const { return (this->name + " " + this->surname + " " + to_string(this->age) + " " + this->email + " " + this->password); }
};

class User : public Person
{

public:

	int subtotal = 0;

	User() {}
	User(string name, string surname, ushort  age, string email, string password, int subtotal = 0) : Person(name, surname, age, email, password) { this->subtotal = subtotal; }

	inline string get_all() const override { return (Person::get_all() + " " + to_string(this->subtotal) + "\n"); }

	// Get Sub

	inline int get_total() const noexcept { return this->subtotal; }

	// Show

	void show() const override
	{
		Person::show();
		cout << "Subtotal: " << this->subtotal << endl;
	}
};

class Admin : public Person
{

public:

	// Constructors

	Admin() {}
	Admin(string name, string surname, ushort age, string email, string password) : Person(name, surname, age, email, password) { }

	// Show

	void show() const override { Person::show(); }
};

class Boss_Admin : public Person
{
public:

	// Constructors

	Boss_Admin(string name, string surname, ushort age, string email ,string password) : Person(name,surname,age,email,password) {}

};