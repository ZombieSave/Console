#include <string>
#include <iostream>
#include "TableParameters.h"
#include "Models/ViewItemsTable.h"
#include "../Service/Models/ItemDTO.h"
#include "../Service/Models/CategoriesDTO.h"
#include "../Service/Service.h"

//using namespace std;

void DrawHeaderCap(int colsNumber, int cellWidth);
void DrawBodyCap(int colsNumber, int cellWidth);
void DrawCellSpace(int colsNumber, int cellWidth);
void DrawCellValue(int colsNumber, int cellWidth, string* values);
void DrawRowBorder(int colsNumber, int cellWidth);
void DrawBottom(int colsNumber, int cellWidth);
void PrintPaddedValue(string str, int valueSpaceLength);
void DrawHeader(TableParameters parameters);
string* MapData(ViewItemsTable item, int length);
string GetCategoryName(int id, CategoriesDTO* categories);
void DrawBody(TableParameters parameters, ViewItemsTable *data);
ViewItemsTable* MapToView(ItemData* data, CategoriesDTO* categories);

void DrawTable(TableParameters parameters, ViewItemsTable *data)
{
	DrawHeader(parameters);
	DrawBodyCap(parameters.Columns, parameters.CellWidth);
	DrawBody(parameters, data);
	DrawBottom(parameters.Columns, parameters.CellWidth);
}

string* MapData(ViewItemsTable item, int length)
{
	string* result = new string[length];
	result[0] = item.Id;
	result[1] = item.Name;
	result[2] = item.Category;
	result[3] = item.Price;
	result[4] = item.InStock;
	
	return result;
}

void DrawHeader(TableParameters parameters)
{
	DrawHeaderCap(parameters.Columns, parameters.CellWidth);
	printf("\n");
	
	for (int i = 0; i < parameters.CellHeight-2; i++)
	{
		if (i == 0)
			DrawCellValue(parameters.Columns, parameters.CellWidth, parameters.Header);
		else
			DrawCellSpace(parameters.Columns, parameters.CellWidth);
			
		printf("\n");
	}
}

void DrawHeaderCap(int colsNumber, int cellWidth)
{
	printf("%c", 218);//left top corner
	
	for(int i = 0; i < colsNumber; i++)
	{
		for (int j = 0; j < cellWidth-2; j++)
		{
			printf("%c", 196);//horizontal line
		}
		
		if (i != colsNumber-1)
			printf("%c", 194);//top t-cross
	}
	
	printf("%c", 191);//right top corner
}

void DrawBodyCap(int colsNumber, int cellWidth)
{
	printf("%c", 195);//left t-cross
	
	for(int i = 0; i < colsNumber; i++)
	{
		for (int j = 0; j < cellWidth-2; j++)
		{
			printf("%c", 196);//horizontal line
		}
		
		if (i != colsNumber-1)
			printf("%c", 197);//cross
	}
	
	printf("%c", 180);//right t-cross
	printf("\n");
}

void DrawBody(TableParameters parameters, ViewItemsTable *data)
{
	for (int i = 0; i < parameters.Rows; i++)
	{
		for (int j = 0; j < parameters.CellHeight-2; j++)
		{
			if (j == 0)
			{
				string* values = MapData(data[i], parameters.Columns);
				DrawCellValue(parameters.Columns, parameters.CellWidth, values);
			}
			else
				DrawCellSpace(parameters.Columns, parameters.CellWidth);
				
			printf("\n");
		}
		
		if (i != parameters.Rows-1)
		{
			DrawRowBorder(parameters.Columns, parameters.CellWidth);
			printf("\n");
		}
	}	
}

void DrawCellSpace(int colsNumber, int cellWidth)
{
	printf("%c", 179);//vertical line
	
	for (int i = 0; i < colsNumber; i++)
	{
		for(int j = 0; j < cellWidth-2; j++)
		{
			printf("%c", 255);//space
		}
		
		printf("%c", 179);//vertical line
	}
}

void DrawCellValue(int colsNumber, int cellWidth, string* values)
{
	int valueSpaceLength = 18;
	printf("%c", 179);//vertical line
	
	for (int col = 0; col < colsNumber; col++)
	{
		PrintPaddedValue(values[col], valueSpaceLength);
		printf("%c", 179);//vertical line
	}
}

void DrawRowBorder(int colsNumber, int cellWidth)
{
	printf("%c", 195);//left t-cross
	
	for (int i = 0; i < colsNumber; i++)
	{
		for(int j = 0; j < cellWidth-2; j++)
		{
			printf("%c", 196);//horizontal line
		}
		
		if (i != colsNumber-1)
			printf("%c", 197);//cross		
	}
	
	printf("%c", 180);//right t-cross
}

void DrawBottom(int colsNumber, int cellWidth)
{
	printf("%c", 192);//left bottom corner
	
	for (int i = 0; i < colsNumber; i++)
	{
		for (int j = 0; j < cellWidth-2; j++)
		{
			printf("%c", 196);//horizontal line
		}
		
		if (i != colsNumber-1)
			printf("%c", 193);//bottom t-cross			
	}
	
	printf("%c", 217);//right bottom corner	
}

void PrintPaddedValue(string str, int valueSpaceLength)
{
	string result = str;
	int l = valueSpaceLength - result.length();
	result.insert(0, l, ' ');
	cout <<  result;	
}

ViewItems GetViewItems()
{
	ViewItems result;
	ItemDTO itemdto = GetItemsDTO();
	CategoriesDTO* categories = GetCategoriesDTO();
	ViewItemsTable* data = MapToView(itemdto.Data, categories);
	result.Items = data;
	result.Header = itemdto.Header;
	
	return result;
}

ViewItemsTable* MapToView(ItemData* data, CategoriesDTO* categories)
{
	int rowNumber = 3;
	ViewItemsTable* result = new ViewItemsTable[rowNumber];
	
	for (int i = 0; i < rowNumber; i++)
	{
		result[i].Id = std::to_string(data[i].Id);
		result[i].Name = data[i].Name;
		result[i].Category = GetCategoryName(data[i].CategoryId, categories);
		result[i].Price = std::to_string(data[i].Price);
							
		if (data[i].InStock)								
			result[i].InStock = "Y";
		else	
			result[i].InStock = "N";
	}
	
	return result;
}

string GetCategoryName(int id, CategoriesDTO* categories)
{
	string result;
	
	for (int i = 0; i < 2; i++)
	{
		if (categories[i].Id == id)
			result = categories[i].Name;
	}
			
	return result;
}