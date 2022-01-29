#include "Service.h"


ItemDTO Service::GetItemsDTO()
{
	ItemDTO result;
	std::vector<ItemEntity> entities = _repository.GetItemEntities("C:\\DB\\item.csv");
	result.Header.push_back(entities[0].Id);
	result.Header.push_back(entities[0].Name);
	result.Header.push_back(entities[0].Category);
	result.Header.push_back(entities[0].Price);
	result.Header.push_back(entities[0].InStock);
	
	int j = 1;
	
	for (int i = 0; i < entities.size()-1; i++)
	{
		ItemDataDTO item;
		item.Id = stoi(entities[j].Id);
		item.Name = entities[j].Name;
		item.CategoryId = stoi(entities[j].Category);
		item.Price = stof(entities[j].Price);
		item.InStock = stoi(entities[j].InStock);
		result.Data.push_back(item);
		++j;
	}
	
	return result;
}

std::vector<CategoriesDTO> Service::GetCategoriesDTO()
{
	std::vector<CategoriesDTO> result;
	std::vector<CategoryEntity> categories = _repository.GetCategories();
	
	for (int i = 0; i < categories.size(); i++)
	{
		CategoriesDTO item;
		item.Id = stoi(categories[i].Id);
		item.Name = categories[i].Name;
		result.push_back(item);
	}
	
	return result;
}