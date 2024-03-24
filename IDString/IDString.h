#pragma once
#ifndef IDSTRING_H
#define IDSTRING_H

#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <regex>
#include <set>
/// <summary>
/// Класс предоставляющий интерфейс для работы с идентифицирующими строками,
/// определены методы позволяющие выпонять CRUD операции
/// </summary>
class IDString
{
	std::string primaryStr{ "" };/// Строка идентификации(содержит атрибуты)
	std::string nameID{ "" };/// Имя строки идентификации(может быть пустой) 
public:
	IDString() = default;
	IDString(std::string str):primaryStr(str){}
	/// <summary>
	/// Функция возвращающая строку идентификации
	/// </summary>
	/// <returns>Строка идентификации</returns>
	std::string getPrimary();
	/// <summary>
	/// Функция устанавливает значение атрибута по его тегу в формате строки
	/// </summary>
	/// <param name="tag">Имя тега</param>
	/// <param name="val">Значение в строковом формате</param>
	/// <returns>Выполнено(true)/Не выполнено(false)</returns>
	bool SetValue(std::string tag, std::string val);
	/// <summary>
	/// Функция устанавливает значение атрибута по его тегу в формате целого числа
	/// </summary>
	/// <param name="tag">Имя тега</param>
	/// <param name="val">Значение в формате целого числа</param>
	/// <returns>Выполнено(true)/Не выполнено(false)</returns>
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

	std::set<std::string> GetTags();

	std::string GetNameID();
	void setNameID(std::string name);

	
	//GetValueDoub

};


#endif // !IDSTRING_H


