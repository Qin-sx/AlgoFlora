// Reference: https://github.com/youngyangyang04/leetcode-master/blob/master/problems
#include <bits/stdc++.h>
using namespace std;

int method_2D(const vector<int>& weight, const vector<int>& value, int bagweight)
{
    int n = weight.size();
    // dp数组, dp[i][j]代表行李箱空间为j的情况下,从下标为[0, i]的物品里面任意取,能达到的最大价值
    vector<vector<int>> dp(n, vector<int>(bagweight + 1, 0));

    for (int j = weight[0]; j <= bagweight; ++j)
    {
        dp[0][j] = value[0];
    }

    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j <= bagweight; ++j)
        {
            if (j < weight[i])
            {
                dp[i][j] = dp[i - 1][j];
            }
            else // j >= weight[i]
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
            }
        }
    }

    return dp[n - 1][bagweight];
};

int method_1D(const vector<int>& weight, const vector<int>& value, int bagweight)
{
    int n = weight.size();
    vector<int> dp(bagweight + 1, 0);

    for (int j = weight[0]; j <= bagweight; ++j)
    {
        dp[j] = value[0];
    }
    
    // 从j = weight[i]开始是不行的，因为每次需要用到dp[i - 1][j]的值，这个值在一维数组中的j循环中会被覆盖
    // for (int i = 1; i < n; ++i)
    // {
    //     for (int j = weight[i]; j <= bagweight; ++j)
    //     {
    //         dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
    //         // cout << "i: " << i << ", j: " << j << ", dp[j]: " << dp[j] <<", dp[j - weight[i]] + value[i] "<<dp[j - weight[i]] + value[i] << endl;
    //     }
    // }

    for (int i = 1; i < n; ++i)
    {
        for (int j = bagweight; j >= weight[i]; --j)
        {
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
            // cout << "i: " << i << ", j: " << j << ", dp[j]: " << dp[j] <<", dp[j - weight[i]] + value[i] "<<dp[j - weight[i]] + value[i] << endl;
        }
    }
    return dp[bagweight];
}

int method_unbounded(const vector<int>& weight, const vector<int>& value, int bagweight)
{
    int n = weight.size();
    vector<int> dp(bagweight + 1, 0);

    for (int j = weight[0]; j <= bagweight; ++j)
    {
        dp[j] = value[0] + dp[j - weight[0]];
        // cout << "j: " << j << ", dp[j]: " << dp[j] << endl;
    }
    
    // 从j = weight[i]开始遍历，相当于j循环中每次都尝试放入weight[i]
    for (int i = 1; i < n; ++i)
    {
        for (int j = weight[i]; j <= bagweight; ++j)
        {
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
            // cout << "i: " << i << ", j: " << j << ", dp[j]: " << dp[j] <<", dp[j - weight[i]] + value[i] "<<dp[j - weight[i]] + value[i] << endl;
        }
    }
    return dp[bagweight];
}


int main()
{
    int bagweight = 10;
    // vector<int> weight = {1, 1};
    // vector<int> value = {3, 6};

    vector<int> weight = {2, 2, 6, 5, 4};
    vector<int> value = {6, 7, 5, 4, 6};
    int n = weight.size();
    
    cout << method_2D(weight, value, bagweight) << endl;
    cout << method_1D(weight, value, bagweight) << endl;
    cout << method_unbounded(weight, value, bagweight) << endl;

    return 0;
}