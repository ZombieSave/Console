#include <string>

using namespace std;

class ItemData
{
	public:
		int Id;
		string Name;
		int CategoryId;
		float Price;
		bool InStock;	
};

class ItemDTO
{
	public:
		ItemData* Data;
		string* Header;
};



