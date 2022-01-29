#include <fstream>
#include "Repository.h"

std::vector<ItemEntity> Repository::GetItemEntities(string fileName)
{
	std::vector<ItemEntity> entities;
	ifstream nameFileout;
	nameFileout.open(fileName);
	string line;
	
	while (getline(nameFileout, line))
	{
		string* fileStr = Split(line);
		ItemEntity entity;
		entity.Id = fileStr[0];
		entity.Name = fileStr[1];
		entity.Category = fileStr[2];
		entity.Price = fileStr[3];
		entity.InStock = fileStr[4];
		entities.push_back(entity);
	}
	
	return entities;
}

std::vector<CategoryEntity> Repository::GetCategories()
{
	std::vector<CategoryEntity> result;
	CategoryEntity item;
	item.Id = "1";
	item.Name = "Boards";
    result.push_back(item);

	item.Id = "2";
	item.Name = "Boots";
	result.push_back(item);
	
	return result;
}

string* Repository::Split(string str)
{
	int count = 0;
	
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ';')
			++count;
	}
	
	string* result	= new string[count];
	string currentString = "";
	int resultIndex = 0;
	int lenfth = str.length();
	
	for (int i = 0; i < lenfth; i++)
	{
		if (str[i] == ';')
		{
			result[resultIndex] = currentString;
			++resultIndex;
			currentString = "";
		}
		else
			currentString += str[i]; 	
	}
	
	return result;
}