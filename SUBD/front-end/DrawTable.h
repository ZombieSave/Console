#include "../view/model/ItemDataView.h"
#include "model/TableParameters.h"

class Draw
{
	private:
		void DrawHeaderCap(int colsNumber, int cellWidth);
		void DrawBodyCap(int colsNumber, int cellWidth);
		void DrawCellSpace(int colsNumber, int cellWidth);
		void DrawCellValue(int colsNumber, int cellWidth, std::vector<string> values);
		void DrawRowBorder(int colsNumber, int cellWidth);
		void DrawBottom(int colsNumber, int cellWidth);
		void PrintPaddedValue(string str, int valueSpaceLength);
		void DrawHeader(TableParameters parameters);
		std::vector<string> MapData(ItemDataView item, int length);
		void DrawBody(TableParameters parameters, std::vector<ItemDataView> data);		
	public:
		void DrawTable(TableParameters parameters);
};