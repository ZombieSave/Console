#include "model/ItemDTO.h"
#include "model/CategoriesDTO.h"
#include "../repository/Repository.h"

class Service
{
	private:
		Repository _repository;
	public:
		ItemDTO GetItemsDTO();
		std::vector<CategoriesDTO> GetCategoriesDTO();
};

