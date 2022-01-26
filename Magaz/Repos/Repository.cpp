#include <iostream>
#include "Repository.h"
#include <fstream>

string* Split(string str);

ItemEntity* GetItemEntities(string fileName)
{
	ItemEntity *entities = new ItemEntity[4];
	ifstream nameFileout;
	nameFileout.open(fileName);
	string line;
	int i = 0;
	
	while (getline(nameFileout, line))
	{
		string* fileStr = Split(line);

		entities[i].Id = fileStr[0];
		entities[i].Name = fileStr[1];
		entities[i].Category = fileStr[2];
		entities[i].Price = fileStr[3];
		entities[i].InStock = fileStr[4];
		
		++i;
	}
	
	return entities;
}

CategoryEntity* GetCategories()
{
	CategoryEntity* result = new CategoryEntity[2];
	result[0].Id = "1";
	result[0].Name = "Boards";

	result[1].Id = "2";
	result[1].Name = "Boots";
	
	return result;
}

string* Split(string str)
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