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

bool Phoin::WriteFile()
{
	return false;
}
