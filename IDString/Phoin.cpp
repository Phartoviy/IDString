#include "Phoin.h"

std::string Phoin::getKey()
{
	return idKey;
}

bool Phoin::setKey(std::string key)
{
	if (!key.empty())
	{
		idKey = key;
		return true;
	}
	else
	{
		return false;
	}
}

bool Phoin::addIDString(IDString obj)
{
	if (!obj.getPrimary().empty())
	{
		listIdentifyString.push_back(obj);
		return true;
	}
	return false;
}

bool Phoin::WriteFile()
{
	return false;
}
