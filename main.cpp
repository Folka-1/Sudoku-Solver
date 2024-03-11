#include <bits/stdc++.h>
using namespace std;

long long total_checks;

bool can(vector<vector<char>>& b, int sx , int ex, int sy, int ey, char tar)
{
	// Check if there is no copy of {tar} in 2d range { [sx:ex-1][sy:ey-1] }
    for(int i = sx; i < ex; i++)
    {
        for(int j = sy; j < ey; j++)
        {
            if(b[i][j] == tar)
            {
                return false;
            }
        }
    }
    return true;
}
bool isonly(vector<vector<char>>& b, int x, int y, char tar)
{
	// Check if there is no copy of { tar } with coordinates (x,y) 
	// Horizontally , Vertically , in Block

    total_checks++; // increase the { total_checks } counter to stop when it reaches 9 to the power of 8
    return can( b , x , x+1 , 0 , 9, tar ) &&
           can( b , 0 , 9 , y , y+1, tar ) &&
           can( b , x-x%3 , x-x%3+3 , y-y%3 , y-y%3+3 , tar );
}
bool solving(vector<vector<char>>& board)
{
    if(total_checks > pow(9,8)) //stop when it reaches more than 9 to the power of 8
    { 
		return false; 
	}
    for(int x = 0; x < 9; x++)
    {
        for(int y = 0; y < 9; y++)
        {
            if(board[x][y] == '.')
            {
				// if the cell (x,y) is empty them find any possible solution

                for(char c = '1'; c <='9'; c++)
                {
                    if( isonly(board,x,y,c) ) // if this element { c } is unique according to the rules  
                    {
						// then set the cell (x,y) to { c } and recursion to continue and find possible solutions 
                        board[x][y] = c;
                        if( solving(board) )
                        {
							// if it is possible to solve till now then return true
                            return true;
                        }
                        else
                        {
							// other wise reset the cell (x,y) to empty and continue over possible solutions
                            board[x][y] = '.';
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}


int main() {
    total_checks = 0;
	cout << "Enter your sudoku in form of (a number or dot'.' for empty)\n";

/* Template
... ... ...
... ... ...
... ... ...

... ... ...
... ... ...
... ... ...

... ... ...
... ... ...
... ... ...
*/

	vector<vector<char>> board(9,vector<char>(9));
	for(int i = 0; i < 9; i++)
	{
		for(int j = 0; j < 9; j++)
		{
			// Input of the board
			cin >> board[i][j];
		}
	}

	if(solving(board))
	{
		// if it is solvable then print the board
		cout << "A solution found !\n";
		for(int i = 0; i < 9; i++)
		{
			for(int j = 0; j < 9; j++)
			{
				cout << board[i][j];
                if(j == 2 || j == 5)
                {
                    cout << " ";
                }
			}
			cout << endl;
			if(i == 2 || i == 5)
            {
                cout << endl;
            }
		}

	}
	else
	{
		// if not solvable then print invalid input or unsolvable
		cout << "Invalid/Unsolvable Sudoku :(";
	}
	cout << endl;
}
