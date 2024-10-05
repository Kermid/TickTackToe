#include <iostream>
#include <ctime>


void drawBoard(char *spaces);
void playerMove(char *spaces,char player);
void computerMove(char *spaces,char computer);
bool checkWinner(char *spaces,char computer,char player);
bool checkTie(char *spaces);

int main()
{
    char spaces[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
    char player = 'X';
    char computer = 'O';
    bool running = true;

    drawBoard(spaces);
    
    while(running == true)
    {   
        
         playerMove(spaces,player);
         drawBoard(spaces);
         if(checkWinner(spaces,computer,player))
         {

            running = false;
            break;
            
         }
         else if(checkTie(spaces))
         {
            running = true;
            break;
         }
         computerMove(spaces,computer);
         drawBoard(spaces);
         if(checkWinner(spaces,computer,player))
         {

            running = false;
            break;
            
         }
         else if(checkTie(spaces))
        {
            running = false;
            break;
        }
    }


    return 0;
}
void drawBoard(char *spaces)
{
    std::cout <<  "     |      |     " <<  "   Oznaczenia pol:" << std::endl;
    std::cout <<  "  " << spaces[0] << "  |  "<< spaces[1] <<"   |   "  << spaces[2] << "   " << "   1   2   3" << std::endl;
    std::cout <<  "_____|______|_____" << std::endl;
    std::cout <<  "     |      |     " << std::endl;
    std::cout <<  "  " << spaces[3] << "  |   "<< spaces[4] <<"  |   " << spaces[5] << "   " << "  4   5   6" << std::endl;
    std::cout <<  "_____|______|_____" << std::endl;
    std::cout <<  "     |      |     " << std::endl;
    std::cout <<  "  " << spaces[6] << "  |   "<< spaces[7] <<"  |   " << spaces[8] << "   " << "  7   8   9"  << std::endl;
    std::cout <<  "     |      |     " << std::endl;
}
void playerMove(char *spaces,char player)
{
    int move;
    std::cout << "Podaj number 1-9 miejsca gdzie chcesz postawic krzyzyk" << std::endl;
    std::cin >> move;
    move--;
    while(move < 0 || move > 9 || spaces[move] != ' ')
    {
        std::cout << "Nieprawidlowy wybor.Wybierz liczbe z zakresu 1-9." << std::endl;
        std::cin >> move;
        move--;
    }
    spaces[move] = player;

}
void computerMove(char *spaces,char computer)
{
    srand(time(NULL));

    int move;

    while(true)
    {
         move = rand() % 9;

        if(spaces[move] == ' ' )
        {

            spaces[move] = computer;

            break;
        }
        
    }
    
}
bool checkWinner(char *spaces,char computer,char player)
{
    //sprawdzanie rzedow
    if( spaces[0] != ' ' && spaces[0] == spaces[1] && spaces[1] == spaces[2])
    {
        spaces[0] == player ? std::cout << "Wygrales!" << std::endl : std::cout << "Przegrales!" << std::endl;
        return true;
    }
    else if(spaces[3] != ' ' && spaces[3] == spaces[4] && spaces[4] == spaces[5])
    {
        spaces[3] == player ? std::cout << "Wygrales!" << std::endl : std::cout << "Przegrales!" << std::endl;
        return true;
    }
    else if( spaces[6] != ' ' && spaces[6] == spaces[7] && spaces[7] == spaces[8])
    {
        spaces[6] == player ? std::cout << "Wygrales!" << std::endl : std::cout << "Przegrales!" << std::endl;
        return true;
    }
    //sprawdzanie kolumn
     else if( spaces[0] != ' ' && spaces[0] == spaces[3] && spaces[3] == spaces[6])
    {
        spaces[0] == player ? std::cout << "Wygrales!" << std::endl : std::cout << "Przegrales!" << std::endl;
        return true;
    }
    else if( spaces[1] != ' ' && spaces[1] == spaces[4] && spaces[4] == spaces[7])
    {
        spaces[1] == player ? std::cout << "Wygrales!" << std::endl : std::cout << "Przegrales!" << std::endl;
        return true;
    }
    else if(spaces[2] != ' ' && spaces[2] == spaces[5] && spaces[5] == spaces[8])
    {
        spaces[2] == player ? std::cout << "Wygrales!" << std::endl : std::cout << "Przegrales!" << std::endl;
        return true;
    }
    //sprawdzanie przekatnych
     else if (spaces[0] != ' ' && spaces[0] == spaces[4] && spaces[4] == spaces[8])
    {
        spaces[0] == player ? std::cout << "Wygrales!" << std::endl : std::cout << "Przegrales!" << std::endl;
        return true;
    }
    else if(spaces[2] != ' ' && spaces[2] == spaces[4] && spaces[4] == spaces[6])
    {
        spaces[2] == player ? std::cout << "Wygrales!" << std::endl : std::cout << "Przegrales!" << std::endl;
        return true;
    }
    else
    {
        return false;
    }
    
}
bool checkTie(char *spaces)
{
    for(int i = 0; i < 9 ; i++)
    {
        if(spaces[i] == ' ')
        {
            return false;
        }
    }
    std::cout << "Remis!" << std::endl;
    return true;
}