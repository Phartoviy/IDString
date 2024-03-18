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

std::string IDString::GetValueStrByTag(std::string tag)
{
	std::string temp = tag + ' ';
	int bpos = primaryStr.find(temp);
	std::string subline = primaryStr.substr(bpos);
	int epos = subline.find(';');
	std::string resultSubline  = subline.substr(0, epos+1);//получение подстроки
	std::regex pattern(temp + ":(.+?);");
	std::smatch matches;
	if (std::regex_search(resultSubline, matches, pattern))
	{
		if (matches.size() > 1)
		{
			std::string tagValue = matches[1];
			return tagValue;
		}
	}
	return "";

}

int IDString::GetValueNumByTag(std::string tag)
{
	std::string temp = tag + ' ';
	int bpos = primaryStr.find(temp);
	std::string subline = primaryStr.substr(bpos);
	int epos = subline.find(';');
	std::string resultSubline = subline.substr(0, epos + 1);//получение подстроки
	std::regex pattern(temp + ":([0-9]+);");
	std::smatch matches;
	if (std::regex_search(resultSubline, matches, pattern))
	{
		if (matches.size() > 1)
		{
			int tagValue = std::stoi(matches[1]);
			return tagValue;
		}
	}
	return 0;
}
