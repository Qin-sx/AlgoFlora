#include <bits/stdc++.h>
using namespace std;

class Solution_93 {
    vector<string> ans;
    vector<int> path;
    int cal_IP(string s, int iBegin, int iEnd)
    {
        long int sum = 0;
        if (iEnd - iBegin > 0)
        {
            if(s[iBegin] == '0')
            {
                return 256;
            }
        }
        for (int i = iBegin; i <= iEnd; ++i)
        {
            if(sum >= 256)
            {
                return 256;
            }
            sum = sum * 10 + int(s[i] - '0');
        }
        return sum;
        // if(sum >= 0 && sum <= 255)
        //     return true;
        // return false;
    }

    void backtrack(string s, int index)
    {
        if (index >= s.size() && path.size() == 4)
        {   
            string a;
            for (int i = 0; i < 3; ++i)
            {
                a += to_string(path[i]);
                a += '.';
            }
            a += to_string(path[3]);
            ans.push_back(a);
            return;
        }
        if (path.size() > 4)
        {
            return;
        }

        for (int i = index; i < s.size(); ++i)
        {
            int IP = cal_IP(s, index, i);
            if(IP >= 0 && IP <= 255)
            {
                path.push_back(IP);
            }
            else
            {
                break;
            }

            backtrack(s, i + 1);
            path.pop_back();
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        backtrack(s,0);
        return ans;
    }
};

class Solution_17 {
    const vector<string> numMaps = {
        "", // 0
        "", // 1
        "abc", // 2
        "def", // 3
        "ghi", // 4
        "jkl", // 5
        "mno", // 6
        "pqrs", // 7
        "tuv", // 8
        "wxyz" // 9
    };
    vector<string> ans;
    vector<char> path;
    void backtrack(string digits, int index)
    {
        if(path.size() == digits.size())
        {   
            string s;
            for( auto p : path)
            {
                s += p;
            }
            ans.push_back(s);
            return;
        }

        if (index == digits.size())
        {
            // return;
        }

        int digit = digits[index] - '0';
        string letters = numMaps[digit];

        for (int i = 0; i < letters.size(); ++i)
        {
            path.push_back(letters[i]);
            backtrack(digits, index + 1);
            path.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0)
            return vector<string>{};
        backtrack(digits, 0);
        return ans;
    }
};

class Solution_131 {
    vector<vector<string>> ans;
    vector<string> path;
    vector<vector<bool>> isPalindrome;
    // bool is_palindrome(string s, int iStart, int iEnd)
    // {
    //     // int n = s.size();
    //     for (int i = iStart, j = iEnd; i < j; ++i, --j)
    //     {
    //         if(s[i] != s[j])
    //         {
    //             return false;
    //         }
    //     }
    //     return true;
    // }
    void cal_isPalindrome(string s)
    {
        int n = s.size();
        isPalindrome.resize(n, vector<bool>(n, false));
        for (int i = n - 1; i >= 0; --i)
        {
            for (int j = i; j < n; ++j)
            {
                if(i == j)
                {
                    isPalindrome[i][j] = true;
                }
                else if (j - i == 1)
                {
                    if(s[i] == s[j])
                        isPalindrome[i][j] = true;
                }
                else
                {
                    if(s[i] == s[j] && isPalindrome[i+1][j-1]==true)
                        isPalindrome[i][j] = true;
                }
            }
        }
    }
    void backtrack(string& s, int index)
    {
        if(index >= s.size())
        {
            ans.push_back(path);
            return;
        }

        for (int i = index; i < s.size(); ++i)
        {
            // if (is_palindrome(s, index, i))
            if(isPalindrome[index][i])
            {
                path.push_back(s.substr(index, i - index + 1));
            }
            else
            {
                continue;
            }
            backtrack(s, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<string>> partition(string s) {
        cal_isPalindrome(s);
        backtrack(s, 0);
        return ans;
    }
};

int main()
{

    Solution_93 s93;
    vector<string> res = s93.restoreIpAddresses("25525511135");
    cout << "[";
    for (auto &s : res)
    {
        cout << s << " ";
    }
    cout << "]" << endl;

    Solution_17 s17;
    vector<string> res2 = s17.letterCombinations("23");
    cout << "[";
    for (auto &s : res2)
    {
        cout << s << " ";
    }
    cout << "]" << endl;

    Solution_131 s131;
    vector<vector<string>> res3 = s131.partition("aab");
    cout << "[";
    for (auto &v : res3)
    {
        cout << "[";
        for (auto &s : v)
        {
            cout << s << " ";
        }
        cout << "]";
    }
    cout << "]" << endl;


    return 0;
}