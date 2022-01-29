#include "model/ItemEntity.h"
#include "model/CategoryEntity.h"
#include <vector>

class Repository
{
	public:
		std::vector<ItemEntity> GetItemEntities(string fileName);
		std::vector<CategoryEntity> GetCategories();
	private:
		string* Split(string str);	
};