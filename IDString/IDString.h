#pragma once
#ifndef IDSTRING_H
#define IDSTRING_H

#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <regex>

class IDString
{
	std::string primaryStr{ "" };
public:
	IDString() = default;
	IDString(std::string str):primaryStr(str){}
	std::string getPrimary();

	bool SetValue(std::string tag, std::string val);
	bool SetValue(std::string tag, int val);
	//void SetValue(std::string tag, double val);

	std::string GetValueStrByTag(std::string tag);
	int GetValueNumByTag(std::string tag);

	bool AddAttribut(std::string newTag, std::string newValue);
	bool AddAttribut(std::string newTag, int newValue);

	int GetAttrCount();

	bool DelAttribut(std::string delTag);

	std::string GetValueStrByAttrNo(int numberAttr);
	int GetValueNumByAttrNo(int numberAttr);


	//ReadFile
	//WriteFile
	//GetValueDoub
	//GetTags()

};


#endif // !IDSTRING_H


