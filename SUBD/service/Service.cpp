#include "Service.h"


ItemDTO Service::GetItemsDTO(string fileName)
{
	ItemDTO result;
	std::vector<ItemEntity> entities = _repository.GetItemEntities(fileName);
	result.Header.push_back(entities[0].Id);
	result.Header.push_back(entities[0].Name);
	result.Header.push_back(entities[0].Category);
	result.Header.push_back(entities[0].Price);
	result.Header.push_back(entities[0].InStock);
	
	for (int i = 1; i < entities.size(); i++)
	{
		ItemDataDTO item;
		item.Id = stoi(entities[i].Id);
		item.Name = entities[i].Name;
		item.CategoryId = stoi(entities[i].Category);
		item.Price = stof(entities[i].Price);
		item.InStock = stoi(entities[i].InStock);
		result.Data.push_back(item);
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