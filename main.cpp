#include <bits/stdc++.h>
using namespace std;

long long total_checks;

bool can(vector<vector<char>>& b, int sx , int ex, int sy, int ey, char tar)
{
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
    total_checks++;
    return can( b , x , x+1 , 0 , 9, tar ) &&
           can( b , 0 , 9 , y , y+1, tar ) &&
           can( b , x-x%3 , x-x%3+3 , y-y%3 , y-y%3+3 , tar );
}
bool solving(vector<vector<char>>& board)
{
    if(total_checks > pow(9,8))
    { return false; }
    for(int x = 0; x < 9; x++)
    {
        for(int y = 0; y < 9; y++)
        {
            if(board[x][y] == '.')
            {
                for(char c = '1'; c <='9'; c++)
                {
                    if( isonly(board,x,y,c) )
                    {
                        board[x][y] = c;
                        if( solving(board) )
                        {
                            return true;
                        }
                        else
                        {
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
			cin >> board[i][j];
		}
	}

	if(solving(board))
	{
		cout << "A solution found !\n";
		for(int i = 0; i < 9; i++)
		{
			for(int j = 0; j < 9; j++)
			{
				cout << board[i][j] << " ";
                if(j == 2 || j == 5)
                {
                    cout << "  ";
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
		cout << "Invalid/Unsolvable Sudoku :(";
	}
	cout << endl;
}
