#define GAME_H
#ifdef GAME_H
 
#include <iostream>
#include <cstdlib>
#include <iomanip>
 
const int MAXROW = 3;
const int MAXCOL = 3;
 
class Game
{
    char Board[3][3] = {{'1', '2', '3'},
                       {'4', '5', '6'},
                       {'7', '8', '9'}};
    int p1_score = 0, p2_score = 0;
    int draw_count = 0;
    bool state = true;
public:
    bool gstate();
    void run();
    void display();
    bool update();
    void events();
    void disp_scores();
    bool game_end();
    bool board_chck();
    bool game_state(bool);
};
 
void Game::disp_scores()
{
    if(p1_score == p2_score)
        std::cout << "draw" << std::endl;
    else if(p1_score > p2_score)
        std::cout << "player 1 win " << std::endl;
    else
        std::cout << "player 2 win " << std::endl;
}
 
bool Game::gstate()
{
    return state;
}
 
bool Game::game_state(bool g_state)
{
    if(g_state == true){
        return true;
    }
    else{
        return false;
        }
}
 
bool Game::update()
{
    if(board_chck()){
            disp_scores();
            state = game_end();
            return state;
    }
    else{
        display();
        state = true;
        return state;
    }
}
 
bool Game::game_end()
{
    display();
    return false;
}
 
bool Game::board_chck()
{
 
    if(Board[0][0] == 'X' && Board[0][1] == 'X' && Board[0][2] == 'X'){
        p1_score++;
        return true;
    }
    else if(Board[1][0] == 'X' && Board[1][1] == 'X' && Board[1][2] == 'X'){
        p1_score++;
        return true;
    }
    else if(Board[2][0] == 'X' && Board[2][1] == 'X' && Board[2][2] == 'X'){
        p1_score++;
        return true;
    }
    else if(Board[0][0] == 'X' && Board[1][0] == 'X' && Board[2][0] == 'X'){
        p1_score++;
        return true;
    }
    else if(Board[0][1] == 'X' && Board[1][1] == 'X' && Board[2][1] == 'X'){
        p1_score++;
        return true;
    }
    else if(Board[0][2] == 'X' && Board[1][2] == 'X' && Board[2][2] == 'X'){
        p1_score++;
        return true;
    }
    else if(Board[0][0] == 'X' && Board[1][1] == 'X' && Board[2][2] == 'X'){
        p1_score++;
        return true;
    }
    else if(Board[0][2] == 'X' && Board[1][1] == 'X' && Board[2][0] == 'X'){
        p1_score++;
        return true;
    }
    else if(Board[0][0] == 'O' && Board[0][1] == 'O' && Board[0][2] == 'O'){
         p2_score++;
        return true;
    }
    else if(Board[1][0] == 'O' && Board[1][1] == 'O' && Board[1][2] == 'O'){
         p2_score++;
        return true;
    }
    else if(Board[2][0] == 'O' && Board[2][1] == 'O' && Board[2][2] == 'O'){
         p2_score++;
        return true;
    }
    else if(Board[0][0] == 'O' && Board[1][0] == 'O' && Board[2][0] == 'O'){
         p2_score++;
        return true;
    }
    else if(Board[0][1] == 'O' && Board[1][1] == 'O' && Board[2][1] == 'O'){
         p2_score++;
        return true;
    }
    else if(Board[0][2] == 'O' && Board[1][2] == 'O' && Board[2][2] == 'O'){
         p2_score++;
        return true;
    }
    else if(Board[0][0] == 'O' && Board[1][1] == 'O' && Board[2][2] == 'O'){
         p2_score++;
        return true;
    }
    else if(Board[0][2] == 'O' && Board[1][1] == 'O' && Board[2][0] == 'O'){
         p2_score++;
        return true;
    }
    else{
        draw_count++;
            if(draw_count == 9){
                    p1_score++; p2_score++;
                    return true;
            }
    }
 
    return false;
}
 
void Game::display()
{
    std::cout << "tic tac toe " << "\n"
              << "X for player, O for player 2" << std::endl;
 
    std::cout << std::setw(45)<< "     |     |     " << std::endl;
    std::cout << std::setw(30)<< "  " << Board[0][0] << "  |  " << Board[0][1] << "  |  " << Board[0][2] << std::endl;
    std::cout << std::setw(45)<< "_____|_____|_____" << std::endl;
    std::cout << std::setw(45)<<"     |     |     " << std::endl;
    std::cout << std::setw(30)<<"  " << Board[1][0] << "  |  " << Board[1][1] << "  |  " << Board[1][2] << std::endl;
    std::cout << std::setw(45)<<"_____|_____|_____" << std::endl;
    std::cout << std::setw(45)<<"     |     |     " << std::endl;
    std::cout << std::setw(30)<<"  " << Board[2][0] << "  |  " << Board[2][1] << "  |  " << Board[2][2] << std::endl;
    std::cout << std::setw(45)<< "     |     |     " << std::endl;
}
 
void Game::events()
{
   bool loop = true;
   int p1_input, p2_input;
 
   while(loop){
   std::cout << "player 1: "; std::cin >> p1_input;
   if(p1_input <= 9){
   switch(p1_input) {
   case 1:
       if(Board[0][0] == 'X' || Board[0][0] == 'O'){
       loop = true;
       break;
       }
       else{
       Board[0][0] = 'X';
       loop = false;
       break;
       }
   case 2:
      if(Board[0][1] == 'X' || Board[0][1] == 'O'){
       loop = true;
       break;
       }
       else{
       Board[0][1] = 'X';
       loop = false;
       break;
       }
   case 3:
       if(Board[0][2] == 'X' || Board[0][2] == 'O'){
       loop = true;
       break;
       }
       else{
       Board[0][2] = 'X';
       loop = false;
       break;
       }
   case 4:
       if(Board[1][0] == 'X' || Board[1][0] == 'O'){
       loop = true;
       break;
       }
       else{
       Board[1][0] = 'X';
       loop = false;
       break;
       }
   case 5:
       if(Board[1][1] == 'X' || Board[1][1] == 'O'){
       loop = true;
       break;
       }
       else{
       Board[1][1] = 'X';
       loop = false;
       break;
       }
   case 6:
       if(Board[1][2] == 'X' || Board[1][2] == 'O'){
       loop = true;
       break;
       }
       else{
       Board[1][2] = 'X';
       loop = false;
       break;
       }
   case 7:
       if(Board[2][0] == 'X' || Board[2][0] == 'O'){
       loop = true;
       break;
       }
       else{
       Board[2][0] = 'X';
       loop = false;
       break;
       }
   case 8:
       if(Board[2][1] == 'X' || Board[2][1] == 'O'){
       loop = true;
       break;
       }
       else{
       Board[2][1] = 'X';
       loop = false;
       break;
       }
   case 9:
       if(Board[2][2] == 'X' || Board[2][2] == 'O'){
       loop = true;
       break;
       }
       else{
       Board[2][2] = 'X';
       loop = false;
       break;
       }
   }
   }
   else{
    std::cout << "invalid input: " << std::endl;
    continue;
   }
   }
 
 
   loop = true;
   if(update() == false)
        return;
 
   while(loop){
   std::cout << "player 2: "; std::cin >> p2_input;
   if(p2_input <= 9){
   switch(p2_input) {
   case 1:
       if(Board[0][0] == 'O' || Board[0][0] == 'X'){
       loop = true;
       break;
       }
       else{
       Board[0][0] = 'O';
       loop = false;
       break;
       }
   case 2:
      if(Board[0][1] == 'O' || Board[0][1] == 'X'){
       loop = true;
       break;
       }
       else{
       Board[0][1] = 'O';
       loop = false;
       break;
       }
   case 3:
       if(Board[0][2] == 'O' || Board[0][2] == 'X'){
       loop = true;
       break;
       }
       else{
       Board[0][2] = 'O';
       loop = false;
       break;
       }
   case 4:
       if(Board[1][0] == 'O' || Board[1][0] == 'X'){
       loop = true;
       break;
       }
       else{
       Board[1][0] = 'O';
       loop = false;
       break;
       }
   case 5:
       if(Board[1][1] == 'O' || Board[1][1] == 'X'){
       loop = true;
       break;
       }
       else{
       Board[1][1] = 'O';
       loop = false;
       break;
       }
   case 6:
       if(Board[1][2] == 'O' || Board[1][2] == 'X'){
       loop = true;
       break;
       }
       else{
       Board[1][2] = 'O';
       loop = false;
       break;
       }
   case 7:
       if(Board[2][0] == 'O' || Board[2][0] == 'X'){
       loop = true;
       break;
       }
       else{
       Board[2][0] = 'O';
       loop = false;
       break;
       }
   case 8:
       if(Board[2][1] == 'O' || Board[2][1] == 'X'){
       loop = true;
       break;
       }
       else{
       Board[2][1] = 'O';
       loop = false;
       break;
       }
   case 9:
       if(Board[2][2] == 'O' || Board[2][2] == 'X'){
       loop = true;
       break;
       }
       else{
       Board[2][2] = 'O';
       loop = false;
       break;
       }
   }
   }
   else{
    std::cout << "invalid input: " << std::endl;
    continue;
   }
   }
 
 
}
 
void Game::run()
{
    display();
    events();
    update();
}
 
#endif // GAME_H
