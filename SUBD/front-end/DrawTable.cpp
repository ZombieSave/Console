#include <iostream>
#include <string>
#include "DrawTable.h"

using namespace std;

void Draw::DrawTable(TableParameters parameters)
{
	DrawHeader(parameters);
	DrawBodyCap(parameters.Columns, parameters.CellWidth);
	DrawBody(parameters, parameters.Items);
	DrawBottom(parameters.Columns, parameters.CellWidth);
}

std::vector<string> Draw::MapData(ItemDataView item, int length)
{
	std::vector<string> result;
	
	result.push_back(item.Id);
	result.push_back(item.Name);
	result.push_back(item.Category);
	result.push_back(item.Price);
	result.push_back(item.InStock);
	
	return result;
}

void Draw::DrawHeader(TableParameters parameters)
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

void Draw::DrawHeaderCap(int colsNumber, int cellWidth)
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

void Draw::DrawBodyCap(int colsNumber, int cellWidth)
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

void Draw::DrawBody(TableParameters parameters, std::vector<ItemDataView> data)
{
	for (int i = 0; i < parameters.Rows; i++)
	{
		for (int j = 0; j < parameters.CellHeight-2; j++)
		{
			if (j == 0)
			{
				std::vector<string> values = MapData(data[i], parameters.Columns);
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

void Draw::DrawCellSpace(int colsNumber, int cellWidth)
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

void Draw::DrawCellValue(int colsNumber, int cellWidth, std::vector<string> values)
{
	int valueSpaceLength = cellWidth-2;
	printf("%c", 179);//vertical line
	
	for (int col = 0; col < colsNumber; col++)
	{
		PrintPaddedValue(values[col], valueSpaceLength);
		printf("%c", 179);//vertical line
	}
}

void Draw::DrawRowBorder(int colsNumber, int cellWidth)
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

void Draw::DrawBottom(int colsNumber, int cellWidth)
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

void Draw::PrintPaddedValue(string str, int valueSpaceLength)
{
	string result = str;
	int l = valueSpaceLength - result.length();
	result.insert(0, l, ' ');
	cout <<  result;	
}




