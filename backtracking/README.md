### 解法

(Reference)[https://labuladong.online/algo/essential-technique/backtrack-framework/#%E5%85%A8%E6%8E%92%E5%88%97%E9%97%AE%E9%A2%98%E8%A7%A3%E6%9E%90]
```python
result = []
def backtrack(路径, 选择列表):
    if 满足结束条件:
        result.add(路径)
        return
    
    for 选择 in 选择列表:
        做选择
        backtrack(路径, 选择列表)
        撤销选择
```

```c++
void traverse(TreeNode* root) {
    for (TreeNode* child : root->childern) {
        // 前序位置需要的操作
        traverse(child);
        // 后序位置需要的操作
    }
}
```

### leetcode 51

```c++
class Solution {

    vector<vector<string>> ans;

    bool is_valid(int row, int col, vector<string> s, int n)
    {
        for (int i = 0; i < row; ++i)
        {
            if(s[i][col] == 'Q')
            {
                return false;
            }
        }

        for (int i = row - 1, j = col-1; i>=0 && j>=0; --i,--j)
        {
            if(s[i][j] == 'Q')
            {
                return false;
            }
        }

        for (int i = row - 1, j = col+1; i>=0 && j<n; --i,++j)
        {
            if(s[i][j] == 'Q')
            {
                return false;
            }
        }
        return true;
    }

    void backtrace(int row, int n, vector<string>& chessboard)
    {
        // 判断终止条件
        if (row == n)
        {
            ans.push_back(chessboard);
            return;
        }

        // 多叉树遍历
        for (int i = 0; i < n; ++i)
        {
            if(!is_valid(row,i,chessboard,n))
            {
                continue;
            }
            // 做选择
            chessboard[row][i] = 'Q';
            backtrace(row+1, n, chessboard);
            // 撤销选择
            chessboard[row][i] = '.';
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {

        std::vector<std::string> chessboard(n, std::string(n, '.'));
        backtrace(0,n,chessboard);
        return ans;
    }
};
```



### leetcode 77

```c++
class Solution {
    vector<vector<int>> ans;

    void backtrace(int iBegin, int n, int k, vector<int>& path)
    {
        // 终止条件
        if(path.size() == k)
        {
            ans.push_back(path);
            return;
        }

        // 多叉树遍历，iBegin代表 数字不做重复选择
        for(int i = iBegin; i < n; ++i)
        {
            // 做选择
            path.push_back(i+1);
            backtrace(i+1, n, k, path);
            // 撤销选择
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> path;
        backtrace(0, n, k, path);
        return ans;
    }
};
```