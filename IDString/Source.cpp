#include "IDString.h"


int main()
{
	IDString mainstr("tag0 :5.4;tag :AVA;tag1 :20;tag2 :202;");


	int str1 = mainstr.GetValueNumByTag("tag1");
	std::cout << str1 <<std::endl;


	

	return 0;
}