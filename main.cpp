#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
 
int main()
{
    Game game;
 
    while(game.game_state(game.gstate())){
    game.run();
    }
 
    return 0;
}
