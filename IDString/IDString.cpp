#include "IDString.h"


std::string IDString::getPrimary()
{
	return primaryStr;
}

bool IDString::SetValue(std::string tag, std::string val)
{
	if (primaryStr.find(tag + ' ') == std::string::npos)
		return false;
	std::string subline = primaryStr.substr(primaryStr.find(tag+' '));
	subline = subline.substr(0, subline.find(';'));
	int sizeSubStr = subline.length();
	subline.replace(subline.find(':') + 1, subline.find(';') - 1,val);
	int it = primaryStr.find(tag + ' ');
	primaryStr.replace(it,sizeSubStr, subline);
	return true;
}

bool IDString::SetValue(std::string tag, int val)
{
	if (primaryStr.find(tag + ' ') == std::string::npos)
		return false;
	std::string num = std::to_string(val);
	std::string subline = primaryStr.substr(primaryStr.find(tag + ' '));
	subline = subline.substr(0, subline.find(';'));
	int sizeSubStr = subline.length();
	subline.replace(subline.find(':') + 1, subline.find(';') - 1,num);
	int it = primaryStr.find(tag + ' ');
	primaryStr.replace(it, sizeSubStr, subline);
	return true;
}

/*void IDString::SetValue(std::string tag, double val)
{
	//TODO ������� ���������� �����
	std::string num = std::to_string(val);

	std::string subline = primaryStr.substr(primaryStr.find(tag + ' '));

	subline = subline.substr(0, subline.find(';'));
	int sizeSubStr = subline.length();
	subline.replace(subline.find(':') + 1, subline.find(';') - 1,num);
	int it = primaryStr.find(tag + ' ');
	primaryStr.replace(it, sizeSubStr, subline);
}*/

std::string IDString::GetValueStrByTag(std::string tag)
{
	std::string temp = tag + ' ';
	int bpos = primaryStr.find(temp);
	std::string subline = primaryStr.substr(bpos);
	int epos = subline.find(';');
	std::string resultSubline  = subline.substr(0, epos+1);//��������� ���������
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
	std::string resultSubline = subline.substr(0, epos + 1);//��������� ���������
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

bool IDString::AddAttribut(std::string newTag, std::string newValue)
{
	if (!newTag.empty())
	{
		std::string term = newTag + " :" + newValue + ";";
		primaryStr = primaryStr + term;
		return true;
	}
	return false;
}

bool IDString::AddAttribut(std::string newTag, int newValue)
{
	if (!newTag.empty())
	{
		std::string num = std::to_string(newValue);
		std::string term = newTag + " :" + num + ";";
		primaryStr = primaryStr + term;
		return true;
	}
	return false;
}

int IDString::GetAttrCount()
{
	char ch = ';';
	int count = 0;
	for (auto c : primaryStr)
	{
		if (c == ch)
			count++;
	}
	return count;
}

bool IDString::DelAttribut(std::string delTag)
{
	std::string temp = delTag + ' ';
	int bpos = primaryStr.find(temp);
	if (bpos == std::string::npos)
		return false;
	std::string subline = primaryStr.substr(bpos);
	int epos = subline.find(';');
	std::string resultSubline = subline.substr(0, epos + 1);//��������� ���������
	primaryStr.erase(bpos,epos+1);

	return true;
}

std::string IDString::GetValueStrByAttrNo(int numberAttr)
{
	if (primaryStr.find(";") == std::string::npos)
		return "";
	size_t findPos{}, findLastPos{};
	for (int i = 0; i < numberAttr; i++)
	{
		findLastPos = findPos;
		findPos = primaryStr.find(";", findLastPos+1);
	}
	std::string subStr = primaryStr.substr(findLastPos+1, findPos-findLastPos);
	std::regex pattern(":(.+?);");
	std::smatch matches;
	if (std::regex_search(subStr, matches, pattern))
	{
		if (matches.size() > 1)
		{
			std::string tagValue = matches[1];
			return tagValue;
		}
	}

	return "";
}

int IDString::GetValueNumByAttrNo(int numberAttr)
{
	if (primaryStr.find(";") == std::string::npos)
		return 0;
	size_t findPos{}, findLastPos{};
	for (int i = 0; i < numberAttr; i++)
	{
		findLastPos = findPos;
		findPos = primaryStr.find(";", findLastPos + 1);
	}
	std::string subStr = primaryStr.substr(findLastPos + 1, findPos - findLastPos);
	std::regex pattern(":(.+?);");
	std::smatch matches;
	if (std::regex_search(subStr, matches, pattern))
	{
		if (matches.size() > 1)
		{
			std::string tagValue = matches[1];
			return atoi(tagValue.c_str());
		}
	}

	return 0;
}
