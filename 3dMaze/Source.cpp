#include <iostream>
#include "Application.h"
#include "Game.h"
using namespace std;



int main()
{

	ApplicationPtr x = Application::get();
	if(x->init())
		x->start(GamePtr(new Game()));

	return 0;
}