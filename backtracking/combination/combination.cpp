// leetcode 62 63
#include <bits/stdc++.h>
using namespace std;

class Solution_77
{
    void backtrack(int startID, vector<int> &path, vector<std::vector<int>> &res, int n, int k)
    {
        if (path.size() == k)
        {
            res.emplace_back(path);
            return;
        }

        for (int j = startID; j <= n; ++j)
        {
            path.emplace_back(j);
            backtrack(j + 1, path, res, n, k);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> res;
        vector<int> path;
        backtrack(1, path, res, n, k);
        return res;
    }
};

class Solution_39 {
private:
    vector<vector<int>> ans;
    vector<int> path;
    void backtrack(int iStart, vector<int>& candidates, int sum, int target) {
        if (sum == target) {
            ans.emplace_back(path);
            return;
        } else if (sum > target) {
            return;
        }

        for (int i = iStart; i < candidates.size(); ++i) {
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtrack(i, candidates, sum, target);
            sum -= candidates[i];
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        int sum = 0;
        int iStart = 0;
        backtrack(0, candidates, sum, target);
        return ans;
    }
};

class Solution_40 {
    vector<vector<int>> ans;
    vector<int> path;
    
    void backtrack(vector<int>& candidates, int target, int sum, int iStart, vector<bool>& used)
    {
        if (sum == target)
        {
            ans.push_back(path);
            return;
        }
        else if (sum > target)
        {
            return;
        }

        for (int i = iStart; i < candidates.size(); ++i)
        {   
            if (i > 0 && candidates[i] == candidates[i-1] && used[i - 1] == false)
            {
                continue;
            }

            used[i] = true;
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtrack(candidates, target, sum, i + 1, used);
            sum -= candidates[i];
            used[i] = false;
            path.pop_back();
        }

    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<bool> used(candidates.size(), false);
        int sum = 0;
        int iStart = 0;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, sum, iStart, used);
        return ans;
    }
};

int main()
{
    Solution_77 s77;
    vector<vector<int>> res = s77.combine(4, 2);
    cout << "[";
    for (auto &v : res)
    {
        cout << "[";
        for (auto &i : v)
        {
            cout << i << " ";
        }
        cout <<"]";
    }
    cout <<"]"<< endl;

    Solution_39 s39;
    vector<int> candidates = {2, 3, 6, 7};
    vector<vector<int>> ans = s39.combinationSum(candidates, 7);
    cout << "[";
    for (auto &v : ans)
    {
        cout << "[";
        for (auto &i : v)
        {
            cout << i << " ";
        }
        cout <<"]";
    }
    cout <<"]"<< endl;
    
    Solution_40 s40;
    vector<int> candidates1 = {1,2,7,1,5};
    vector<vector<int>> ans1 = s40.combinationSum2(candidates1, 8);
    cout << "[";
    for (auto &v : ans1)
    {
        cout << "[";
        for (auto &i : v)
        {
            cout << i << " ";
        }
        cout <<"]";
    }
    cout <<"]"<< endl;

    return 0;
}