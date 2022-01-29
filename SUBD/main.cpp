#include <iostream>
#include "view/View.h"
#include "front-end/DrawTable.h"
#include <vector>

int main(int argc, char** argv) 
{
	View view;
	Draw draw;
	ItemView data = view.GetViewItems("C:\\DB\\item.csv");
	TableParameters parameters = TableParameters(3, 20, data.Header, data.Items);
	draw.DrawTable(parameters);
	
	getchar();
	return 0;
}