using namespace std;

class ViewItemsTable
{
	public:
		string Id;
		string Name;
		string Category;
		string Price;
		string InStock;
};

class ViewItems
{
	public:
		ViewItemsTable* Items;
		string* Header;
};