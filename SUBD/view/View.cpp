#include "View.h"

ItemView View::GetViewItems()
{
	ItemView result;
	ItemDTO data = _service.GetItemsDTO();
	std::vector<CategoriesDTO> categories = _service.GetCategoriesDTO();
	result.Items = MapToView(data.Data, categories);
	result.Header = data.Header;
	
	return result;
};

std::vector<ItemDataView> View::MapToView(std::vector<ItemDataDTO> data, std::vector<CategoriesDTO> categories)
{
	std::vector<ItemDataView> result;
	
	for (int i = 0; i < data.size(); i++)
	{ 
		ItemDataView item;
		item.Id = std::to_string(data[i].Id);
		item.Name = data[i].Name;
		item.Category = GetCategoryName(data[i].CategoryId, categories);
		item.Price = std::to_string(data[i].Price);
							
		if (data[i].InStock)								
			item.InStock = "Y";
		else	
			item.InStock = "N";
			
		result.push_back(item);	
	}
	
	return result;
};

string View::GetCategoryName(int id, std::vector<CategoriesDTO> categories)
{
	string result;
	
	for (int i = 0; i < categories.size(); i++)
	{
		if (categories[i].Id == id)
			result = categories[i].Name;
	}
			
	return result;
};