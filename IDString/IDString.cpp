#include "IDString.h"

std::string IDString::getPrimary()
{
	return primaryStr;
}

void IDString::SetValue(std::string tag, std::string val)
{
	std::string subline = primaryStr.substr(primaryStr.find(tag+' '));
	
	subline = subline.substr(0, subline.find(';'));
	int sizeSubStr = subline.length();
	subline.replace(subline.find(':') + 1, subline.find(';') - 1, " " + val);
	int it = primaryStr.find(tag + ' ');
	primaryStr.replace(it,sizeSubStr, subline);
}

void IDString::SetValue(std::string tag, int val)
{
	std::string num = std::to_string(val);

	std::string subline = primaryStr.substr(primaryStr.find(tag + ' '));

	subline = subline.substr(0, subline.find(';'));
	int sizeSubStr = subline.length();
	subline.replace(subline.find(':') + 1, subline.find(';') - 1, " " + num);
	int it = primaryStr.find(tag + ' ');
	primaryStr.replace(it, sizeSubStr, subline);

}

void IDString::SetValue(std::string tag, double val)
{
	std::string num = std::to_string(val);

	std::string subline = primaryStr.substr(primaryStr.find(tag + ' '));

	subline = subline.substr(0, subline.find(';'));
	int sizeSubStr = subline.length();
	subline.replace(subline.find(':') + 1, subline.find(';') - 1, " " + num);
	int it = primaryStr.find(tag + ' ');
	primaryStr.replace(it, sizeSubStr, subline);
}

std::string IDString::GetValueStr(std::string tag)
{
	std::string subLine = primaryStr.substr(primaryStr.find(tag+' '));
	std::string result = subLine.substr(subLine.find(":") + 1, subLine.find(";") - subLine.find(":") - 1);
	std::string value = result.substr(result.find_first_not_of(' '), result.find_last_not_of(' ') - result.find_first_not_of(' ') + 1);
	return value;
}

int IDString::GetValueNum(std::string tag)
{
	std::string subLine = primaryStr.substr(primaryStr.find(tag + ' '));
	std::string result = subLine.substr(subLine.find(":") + 1, subLine.find(";") - subLine.find(":") - 1);
	std::string value = result.substr(result.find_first_not_of(' '), result.find_last_not_of(' ') - result.find_first_not_of(' ') + 1);
	int num = atoi(value.c_str());
	return num;
}
