#include <iostream>
#include <string>

#include "Util/util.h"

#include "Service/Models/ItemDTO.h"
#include "Service/Models/CategoriesDTO.h"
#include "Service/Service.h"

#include "View/TableParameters.h"
#include "View/Models/ViewItemsTable.h"
#include "View/DrawTable.h"

using namespace std;

int main(int argc, char** argv) 
{
	ViewItems viewItems = GetViewItems();
	
	TableParameters parameters;
	parameters.Rows = 3;
	parameters.Columns = 5;
	parameters.CellHeight = 3,
	parameters.CellWidth = 20;
	parameters.Header = viewItems.Header;
	
	DrawTable(parameters, viewItems.Items);
	
    getchar();
    return 0;
}