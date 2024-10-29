#include <bits/stdc++.h>
using namespace std;

class Solution_51 {
    vector<vector<string>> ans;
    
    bool isValid(vector<string>& chessboard, int row, int col, int n)
    {
        for (int i = 0; i < row; ++i)
        {
            if (chessboard[i][col] == 'Q')
                return false;
        }

        for (int i = row - 1, j = col - 1; i >=0 && j >= 0; --i,--j)
        {
            if (chessboard[i][j] == 'Q')
                return false;
        }

        for (int i = row - 1, j = col + 1; i >=0 && j < n; --i, ++j)
        {
            if (chessboard[i][j] == 'Q')
                return false;
        }
        return true;
    }

    void backtrack(vector<string>& chessboard, int index, int n)
    {
        if(index == n)
        {
            ans.push_back(chessboard);
            return;
        }

        for (int col = 0; col < n; ++col)
        {
            if(isValid(chessboard, index, col, n))
            {
                chessboard[index][col] = 'Q';
                backtrack(chessboard, index + 1, n);
                chessboard[index][col] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> chessboard = vector<string>(n, string(n,'.'));
        backtrack(chessboard, 0, n);
        return ans;
    }
};

class Solution_37 {

    bool isValid(int row, int col, char val, vector<vector<char>>& board)
    {
        for (int i = 0; i < 9; ++i)
        {
            if (board[i][col] == val)
                return false;
        }

        for (int j = 0; j < 9; ++j)
        {
            if (board[row][j] == val)
                return false;
        }

        int rowId = row / 3 * 3;
        int colId = col / 3 * 3;
        for (int i = 0;i < 3; ++i)
            for (int j = 0; j < 3; ++j)
            {
                if (board[rowId + i][colId + j] == val)
                    return false;
            }

        return true;
    }

    bool backtrack(vector<vector<char>>& board)
    {
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[0].size(); ++j)
            {
                if (board[i][j] == '.')
                {
                    for (char k = '1'; k <= '9'; ++k )
                    {
                        if(isValid(i, j, k, board))
                        {
                            board[i][j] = k;
                            if (backtrack(board)) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board);
    }
};

int main()
{

    Solution_51 s51;
    vector<vector<string>> ans = s51.solveNQueens(4);
    for (auto& v : ans)
    {
        for (auto& s : v)
        {
            cout << s << endl;
        }
        cout << endl;
    }

    Solution_37 s37;
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    s37.solveSudoku(board);
    for (auto& v : board)
    {
        for (auto& c : v)
        {
            cout << c << " ";
        }
        cout << endl;
    }
    


    return 0;
}