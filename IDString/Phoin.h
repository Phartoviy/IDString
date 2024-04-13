#pragma once
#ifndef PHOIN_H
#define PHOIN_H

#include "IDString.h"
#include <fstream>
#include <string>
#include <unordered_map>
//#include <crypt>
/// <summary>
///  ласс Phoin контейнера позвол€ющего хранить строки идентификации и производить запись/чтение 
/// идентифицирующих строк в бинарный файл
/// </summary>
class Phoin
{
	std::string idKey{ "" };///  люч контейнера
public:
	Phoin() = default;
	Phoin(std::string key):idKey(key){}
	std::string getKey();
	bool setKey(std::string key);
	void generateKey(std::string key);
	bool addIDString(IDString obj);
	bool WriteFile();
	bool ReadFile(std::string pathToFile);



private:
	std::vector<IDString> listIdentifyString{};
};

#endif // !PHOIN_H