#include "Models/ItemDTO.h"
#include "Models/CategoriesDTO.h"
#include "../Repos/Repository.h"

ItemDTO GetItemsDTO()
{
	int rowsNumber = 3;
	ItemDTO result;
	result.Data = new ItemData[rowsNumber];
	
	ItemEntity* entities = GetItemEntities("C:\\DB\\item.csv");
	result.Header = new string[5];
	result.Header[0] = entities[0].Id;
	result.Header[1] = entities[0].Name;
	result.Header[2] = entities[0].Category;
	result.Header[3] = entities[0].Price;
	result.Header[4] = entities[0].InStock;
	
	int j = 1;
	
	for (int i = 0; i < rowsNumber; i++)
	{
		result.Data[i].Id = stoi(entities[j].Id);
		result.Data[i].Name = entities[j].Name;
		result.Data[i].CategoryId = stoi(entities[j].Category);
		result.Data[i].Price = stof(entities[j].Price);
		result.Data[i].InStock = stoi(entities[j].InStock);
		++j;
	}
	
	return result;
}

CategoriesDTO* GetCategoriesDTO()
{
	int categoryNumber = 2;
	CategoriesDTO* result = new CategoriesDTO[categoryNumber];
	CategoryEntity* categories = GetCategories();
	
	for (int i = 0; i < categoryNumber; i++)
	{
		result[i].Id = stoi(categories[i].Id);
		result[i].Name = categories[i].Name;
	}
	
	return result;
}