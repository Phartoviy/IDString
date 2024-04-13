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

void Phoin::generateKey(std::string key)
{
	std::hash<std::string> hasher;
	size_t hash = hasher(key);
	idKey = std::to_string(hash);
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
	std::ofstream fileCont("phoin.bin", std::ios::out | std::ios::binary);
	if (fileCont.is_open())
	{
		size_t sizeKey = idKey.size();
		fileCont.write((char*)&sizeKey, sizeof(sizeKey));//write size Key
		fileCont.write(idKey.c_str(), sizeof(idKey));//write Key
		size_t volumeElement = listIdentifyString.size();
		fileCont.write((char*)&volumeElement, sizeof(volumeElement));//write kol-vo elements
		for (size_t i = 0; i < volumeElement; i++)
		{
			std::string strMesssage = listIdentifyString[i].getPrimary();
			size_t sizeElement = strMesssage.size();
			fileCont.write((char*)&sizeElement, sizeof(sizeElement));// write size str
			fileCont.write(strMesssage.c_str(), sizeof(strMesssage));// write str

		}
		fileCont.close();

		return true;
	}

	return false;
}

bool Phoin::ReadFile(std::string pathToFile)
{
	std::ifstream fileCont("phoin.bin", std::ios::binary);

	if (fileCont.is_open())
	{
		



		return true;
	}

	return false;
}
