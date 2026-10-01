#include<iostream>
using namespace std ;

//====================================
string player1 , player2 ;
char symbol1 , symbol2 ;
string start_player , end_player ;
char start_symbol , end_symbol ;
int score1 = 0 ;
int score2 = 0 ;

char game[3][3] = { 
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'} }; 
//====================================
void display( char game[3][3] )
{
    for ( int rows = 0 ; rows < 3 ; rows++ )
    {
        cout << "\n-------------------\n";
        for ( int column = 0 ; column < 3 ; column++ )
        {   
            cout << "|  " << game[rows][column] << "  " ;        
        }
        cout << "|" ;
    }
    cout << "\n-------------------\n\n";
}  
void reset_array_game( char game[3][3] )
{
    char arr[3][3] = { 
        {'1','2','3'},
        {'4','5','6'},
        {'7','8','9'}
    };
    for ( int rows = 0 ; rows < 3 ; rows++ )
    {
        for ( int column = 0 ; column < 3 ; column++ )
        {   
            game[rows][column] = arr[rows][column] ;        
        }
    }
}

bool win(char game[3][3], string player1, string player2,
         char symbol1, char symbol2)
{
    for (int i = 0; i < 3; i++)
    {
        if (game[i][0] == game[i][1] && game[i][0] == game[i][2])
        {
            if (game[i][0] == symbol1)
            {
                cout << ">>> { " << player1 << " } is winner <<<\n";
                start_player = player1 ;
                end_player = player2 ;
                start_symbol = symbol1 ;
                end_symbol = symbol2 ;
                score1++ ;
            }    
            else
            {
                cout << ">>> { " << player2 << " } is winner <<<\n";
                start_player = player2 ;
                end_player = player1 ;
                start_symbol = symbol2 ;
                end_symbol = symbol1 ;
                score2++ ;
            }
            return true;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        if (game[0][i] == game[1][i] &&
            game[0][i] == game[2][i])
        {
            if (game[0][i] == symbol1)
            {
                cout << ">>> { " << player1 << " } is winner <<<\n";
                start_player = player1 ;
                end_player = player2 ;
                start_symbol = symbol1 ;
                end_symbol = symbol2 ;
                score1++ ;
            }
            else
            {
                cout << ">>> { " << player2 << " } is winner <<<\n";
                start_player = player2 ;
                end_player = player1 ;
                start_symbol = symbol2 ;
                end_symbol = symbol1 ;
                score2++ ;
            }
            return true;
        }
    }
    if (game[0][0] == game[1][1] &&
        game[0][0] == game[2][2])
    {
        if (game[0][0] == symbol1)
        {
            cout << ">>> { " << player1 << " } is winner <<<\n";
            start_player = player1 ;
            end_player = player2 ;
            start_symbol = symbol1 ;
            end_symbol = symbol2 ;
            score1++ ;
        }    
        else
        {
            cout << ">>> { " << player2 << " } is winner <<<\n";
            start_player = player2 ;
            end_player = player1 ;
            start_symbol = symbol2 ;
            end_symbol = symbol1 ;
            score2++ ;
        }
        return true;
    }
    if (game[0][2] == game[1][1] &&
        game[0][2] == game[2][0])
    {
        if (game[0][2] == symbol1)
        {
            cout << ">>> { " << player1 << " } is winner <<<\n";
            start_player = player1 ;
            end_player = player2 ;
            start_symbol = symbol1 ;
            end_symbol = symbol2 ;
            score1++ ;
        }
        else
        {
            cout << ">>> { " << player2 << " } is winner <<<\n";
            start_player = player2 ;
            end_player = player1 ;
            start_symbol = symbol2 ;
            end_symbol = symbol1 ;
            score2++ ;
        }
        return true;
    }
    return false;
}

int main ()
{
// ===== التسميه =====
    cout << "Player 1 Enter Your Name : " ;
    cin >> player1 ;
    cout << "Player 2 Enter Your Name : " ;
    cin >> player2 ;
    start_player = player1 ;
    end_player = player2 ;
// ===== تحديد الرمز =====
    do
    {
        cout << "\n" << player1 << " Choose Your Symbol ( x or o ) : " ;
        cin >> symbol1 ;
        cout << endl ;
        if ( symbol1 != 'x' && symbol1 != 'o' )
        {
            cout << "!!! Please Choose ( x or o ) only !!!\n";
        }
    }
    while ( symbol1 != 'x' && symbol1 != 'o' );
    if ( symbol1 == 'x' )
    {
        symbol2 = 'o' ;
    }
    else
    {
        symbol2 = 'x' ;
    }
    start_symbol = symbol1 ;
    end_symbol = symbol2 ;
    cout << player1 << " You are " << symbol1 << endl ;    
    cout << player2 << " You are " << symbol2 << endl << endl ;       
// ===== تشغيل اللعبه =====
    bool on = true ;
    char answer_to_again ;
    int rounds = 1 ;
    while ( on )
    {
        cout << "***************\n" ;
        cout << player1 << " : " << player2 << endl ;
        cout << "   " << score1 << "   :   "
             << score2 << "    " << endl ;
        cout << "***************\n" ;

        char position ;
        int count_turns = 1 ;
        bool w = false ;

        cout << "\n====================\n" ;
        cout << "      Round " << rounds << endl ;
        cout << "====================\n" ;
        display (game) ;

        while ( count_turns <= 9 && !w )
        {
            if ( count_turns % 2 != 0)
            {
                bool found ;
                do
                {
                    found = false ;
                    cout << start_player
                         << " Choose Your Position =  " ;
                    cin >> position ;
                    if ( position < '1' || position > '9' )
                    {
                        cout << "invalid Position ,try again\n" ;
                        continue ;
                    }
                    for ( int rows = 0 ; rows < 3 ; rows++ )
                    {
                        for ( int column = 0 ; column < 3 ; column++ )
                        {   
                            if ( game[rows][column] == position )
                            {
                                game[rows][column] = start_symbol ; 

                                found = true ;

                                break ;
                            }       
                        }
                        if (found)
                            break ;        
                    }
                    if ( !found )
                    {
                        cout << "invalid Position ,try again\n" ;
                    }
                }while(!found);
                display (game);
                w = win( game , start_player , end_player , start_symbol , end_symbol );
            }
            else
            {
                bool found ;
                do
                {
                    found = false ;
                    cout << end_player
                         << " Choose Your Position =  " ;
                    cin >> position ;
                    if ( position < '1' || position > '9' )
                    {
                        cout << "invalid Position ,try again\n" ;
                        continue ;
                    }
                    for ( int rows = 0 ; rows < 3 ; rows++ )
                    {
                        for ( int column = 0 ; column < 3 ; column++ )
                        {   
                            if ( game[rows][column] == position )
                            {
                                game[rows][column] = end_symbol ; 

                                found = true ;

                                break ;
                            }       
                        }
                        if (found)
                            break ;        
                    }
                    if ( !found )
                    {
                        cout << "invalid Position ,try again\n" ;
                    }
                }while(!found);
                display (game);

                w = win( game , start_player , end_player , start_symbol , end_symbol );
            } 
            count_turns++ ;
        }
        if (!w && count_turns > 9)
        {
            cout << ">>> Draw! <<<\n";
        }
        do
        {
            cout << "Play Again ? (y/n) : " ;
            cin >> answer_to_again ;
            cout << endl ;
            if ( answer_to_again != 'y' &&
                 answer_to_again != 'n' )
            {
                cout << "!!! Please Choose ( y or n ) only !!!\n";  
            }
        }while ( answer_to_again != 'y' && answer_to_again != 'n' );
        if ( answer_to_again == 'n' )
        {
            on = false ;
        }
        else 
        {
            reset_array_game(game) ;
            rounds++ ;
        }
    }
    return 0;
}