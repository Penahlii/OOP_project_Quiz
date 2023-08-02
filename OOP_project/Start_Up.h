#pragma once

class Start_Up
{
public:

	static void start()
	{
		Data_Base* data_base_of_all = new Data_Base();

		data_base_of_all->program_start_1();
		data_base_of_all->program_start_2();

		Boss_Admin* boss_admin = new Boss_Admin("Jeff", "Bezos", 59, "jeffbozes10@gmail.com", "jeffbozesquiz2023");

		Registration quiz_regis(data_base_of_all);

		All_Quizes all_quizes;

		all_quizes.program_start();

		main_menu(data_base_of_all, quiz_regis, boss_admin, all_quizes);
	}
};