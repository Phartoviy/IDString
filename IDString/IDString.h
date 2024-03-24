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
/// ����� ��������������� ��������� ��� ������ � ����������������� ��������,
/// ���������� ������ ����������� �������� CRUD ��������
/// </summary>
class IDString
{
	std::string primaryStr{ "" };/// ������ �������������(�������� ��������)
	std::string nameID{ "" };/// ��� ������ �������������(����� ���� ������) 
public:
	IDString() = default;
	IDString(std::string str):primaryStr(str){}
	/// <summary>
	/// ������� ������������ ������ �������������
	/// </summary>
	/// <returns>������ �������������</returns>
	std::string getPrimary();
	/// <summary>
	/// ������� ������������� �������� �������� �� ��� ���� � ������� ������
	/// </summary>
	/// <param name="tag">��� ����</param>
	/// <param name="val">�������� � ��������� �������</param>
	/// <returns>���������(true)/�� ���������(false)</returns>
	bool SetValue(std::string tag, std::string val);
	/// <summary>
	/// ������� ������������� �������� �������� �� ��� ���� � ������� ������ �����
	/// </summary>
	/// <param name="tag">��� ����</param>
	/// <param name="val">�������� � ������� ������ �����</param>
	/// <returns>���������(true)/�� ���������(false)</returns>
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


