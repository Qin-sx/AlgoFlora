// leetcode 62 63
#include <bits/stdc++.h>
using namespace std;

class Solution_62
{
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = 0; i < m; ++i)
        {
            dp[i][0] = 1;
        }

        for (int j = 0; j < n; ++j)
        {
            dp[0][j] = 1;
        }

        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};

class Solution_63
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = 0; i < m; ++i)
        {
            if (obstacleGrid[i][0] == 1)
                break;
            dp[i][0] = 1;
        }

        for (int j = 0; j < n; ++j)
        {
            if (obstacleGrid[0][j] == 1)
                break;
            dp[0][j] = 1;
        }

        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                if (obstacleGrid[i][j] == 1)
                    continue;
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main()
{
    int m = 3, n = 7;
    Solution_62 s62;
    cout << s62.uniquePaths(m, n) << endl; // 28

    vector<vector<int>> obstacleGrid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    Solution_63 s63;
    cout << s63.uniquePathsWithObstacles(obstacleGrid) << endl; // 2

    return 0;
}