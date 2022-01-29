#include "model/ItemView.h"
#include "../service/Service.h"

class View
{
	private:
		Service _service;
		std::vector<ItemDataView> MapToView(std::vector<ItemDataDTO> data, std::vector<CategoriesDTO> categories);
		string GetCategoryName(int id, std::vector<CategoriesDTO> categories);
	public:
		ItemView GetViewItems(string fileName);
};
		