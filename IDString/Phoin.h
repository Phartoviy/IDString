#pragma once
#ifndef PHOIN_H
#define PHOIN_H

#include "IDString.h"


/// <summary>
/// ����� Phoin ���������� ������������ ������� ������ ������������� � ����������� ������/������ 
/// ���������������� ����� � �������� ����
/// </summary>
class Phoin
{
	std::string idKey{ "" };/// ���� ����������
public:
	Phoin() = default;
	Phoin(std::string key):idKey(key){}
	std::string getKey();
	bool setKey(std::string key);
	//ReadFile
	//WriteFile


private:
	std::vector<IDString> listIdentifyString{};
};

#endif // !PHOIN_H