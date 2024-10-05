#include <iostream>
#include <ctime>


void drawBoard(char *spaces);
void playerMove(char *spaces,char player);
void computerMove(char *spaces,char computer);
bool checkWinner(char *spaces,char computer,char player);
bool checkTie(char *spaces);

int main()
{
    char playerMove;
    char spaces[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
    char player = 'X';
    char computer = 'O';
    bool running = true;

    drawBoard(spaces);
    
    while(running == true)
    {
        
    }

    return 0;
}
void drawBoard(char *spaces)
{
    std::cout <<  "     |      |     " <<  "   Oznaczenia pol:" << std::endl;
    std::cout <<  "  " << spaces[0] << "  |  "<< spaces[1] <<"   |  "  << spaces[2] << "   " << "   1   2   3" << std::endl;
    std::cout <<  "_____|______|_____" << std::endl;
    std::cout <<  "     |      |     " << std::endl;
    std::cout <<  "  " << spaces[3] << "  |   "<< spaces[4] <<"  |   " << spaces[5] << "   "<< std::endl;
    std::cout <<  "_____|______|_____" << std::endl;
    std::cout <<  "     |      |     " << std::endl;
    std::cout <<  "  " << spaces[6] << "  |   "<< spaces[7] <<"  |   " << spaces[8] << "   "<< std::endl;
    std::cout <<  "     |      |     " << std::endl;
}
void playerMove(char *spaces,char player)
{
    std::cout << "Podaj number miejsca gdzie chcesz postawic krzyzyk" << std::endl;
}
void computerMove(char *spaces,char computer)
{
    srand(time(NULL));

    computer = (rand() % 9) + 1;
}
bool checkWinner(char *spaces,char computer,char player)
{

    return true;
}
bool checkTie(char *spaces)
{

    return true;
}