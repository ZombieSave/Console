#include <string>
#include <vector>

using namespace std;

class TableParameters
{
	public:
		TableParameters(int cellHeight, int cellWidth, std::vector<string> header, std::vector<ItemDataView> items)
		{
			CellHeight = cellHeight;
			CellWidth = cellWidth;
			Header = header;
			Items = items;
			Rows = items.size();
			Columns = header.size();
		}
		
		int Rows;
		int Columns;
		int CellWidth;
		int CellHeight;		
		std::vector<string> Header;
		std::vector<ItemDataView> Items;
};