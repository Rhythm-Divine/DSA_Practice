#include <bits/stdc++.h>
using namespace std;

bool valid(vector<vector<char>> &board, int row, int col, char val)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] == val)
        {
            return false;
        }
        if (board[i][col] == val)
        {
            return false;
        }
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val)
        {
            return false;
        }
    }
    return true;
}
bool solve(vector<vector<char>> &board)
{
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            if (board[row][col] == '.')
            {
                for (char i = '1'; i <= '9'; i++)
                {
                    if (valid(board, row, col, i))
                    {
                        board[row][col] = i;

                        if (solve(board) == true)
                        {
                            return true;
                        }
                        else
                        {
                            board[row][col] = '.';
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<char>> &board)
{
    solve(board);
}

// bool valid(vector<vector<char>> &board, int row, int col, char val)
// {
//     for (int i = 0; i < 9; i++)
//     {
//         if (board[row][i] == val)
//         {
//             return false;
//         }
//         if (board[i][col] == val)
//         {
//             return false;
//         }
//         if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3])
//         {
//             return false;
//         }
//     }
//     return true;
// }
// bool solve(vector<vector<char>> &board)
// {
//     for (int i = 0; i < 9; i++)
//     {
//         for (int j = 0; j < 9; j++)
//         {
//             if (board[i][j] == '.')
//             {
//                 for (char c = '1'; c <= '9'; c++)
//                 {
//                     if (valid(board, i, j, c))
//                     {
//                         board[i][j] = c;
//                         if (solve(board) == true)
//                         {
//                             return true;
//                         }
//                         else
//                         {
//                             board[i][j] = '.';
//                         }
//                     }
//                 }
//                 return false;
//             }
//         }
//     }
//     return true;
// }

// void solveSudoku(vector<vector<char>> &board)
// {
//     solve(board);
// }
int main()
{
    vector<vector<char>> board{
        {'9', '5', '7', '.', '1', '3', '.', '8', '4'},
        {'4', '8', '3', '.', '5', '7', '1', '.', '6'},
        {'.', '1', '2', '.', '4', '9', '5', '3', '7'},
        {'1', '7', '.', '3', '.', '4', '9', '.', '2'},
        {'5', '.', '4', '9', '7', '.', '3', '6', '.'},
        {'3', '.', '9', '5', '.', '8', '7', '.', '1'},
        {'8', '4', '5', '7', '9', '.', '6', '1', '3'},
        {'.', '9', '1', '.', '3', '6', '.', '7', '5'},
        {'7', '.', '6', '1', '8', '5', '4', '.', '9'}};

    solveSudoku(board);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            cout << board[i][j] << " ";
        cout << "\n";
    }
}