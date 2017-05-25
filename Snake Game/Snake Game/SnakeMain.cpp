#include "Common.h"
#include "Snake.h"
#include "Display.h"
#include "Util.h"
#include "SnakeManager.h"

int main()
{
	SnakeManager snakeManager;
	
	snakeManager.Init();

	while (1)
		snakeManager.Game();

	return 0;
}