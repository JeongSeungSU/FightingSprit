#include "FightingSprit.h"

void main()
{
	try
	{
		FightingSprit GameManager;
		GameManager.Run();
	}
	catch(JsException e)
	{
		e.PrintErrorMessage();
	}
	catch(NetworkException e)
	{
		std::cout<<"Network ErrorMessage \n";
		e.PrintErrorMessage();
	}
}