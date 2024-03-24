#include "IDString.h"


int main()
{
	IDString mainstr("tag0 :5;tag :AVA;tag1 :20;tag2 :202;");

	auto list = mainstr.GetTags();
	for (auto f : list)
	{
		std::cout << f << std::endl;
	}

	std::cout << mainstr.getPrimary() <<std::endl;


	

	return 0;
}