#include "IDString.h"


int main()
{
	IDString mainstr("tag0 :5;tag :AVA;tag1 :20;tag2 :202;");

	std::cout << mainstr.GetValueNumByAttrNo(4) << std::endl;

	std::cout << mainstr.getPrimary() <<std::endl;


	

	return 0;
}