#include "IDString.h"


int main()
{
	IDString mainstr("tag0 :5.4;tag :AVA;tag1 :20;tag2 :202;");


	std::cout << mainstr.getPrimary() <<std::endl;


	

	return 0;
}