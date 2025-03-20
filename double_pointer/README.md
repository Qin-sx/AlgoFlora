### leetcode 76
双指针：先走右指针，符合条件后走右指针

```c++
class Solution {
    bool is_covered(vector<int> s_cnt, vector<int> t_cnt)
    {
        for (int i = 0; i < 128; ++i)
        {
            if (s_cnt[i] < t_cnt[i])
            {
                return false;
            }
        }
        return true;
    }

public:
    string minWindow(string s, string t) {
        int m = s.size();

        vector<int> s_cnt(128);
        vector<int> t_cnt(128);

        for(char c : t)
        {
            t_cnt[c]++;
        }

        int left = 0;
        int ans_left = -1, ans_right = m;
        for (int right = 0; right < m; right++)
        {
            s_cnt[s[right]]++;
            while(is_covered(s_cnt, t_cnt))
            {
                if (right - left < ans_right - ans_left)
                {
                    ans_left = left;
                    ans_right = right;
                }
                s_cnt[s[left]]--;
                left++;
            }
        }
        return ans_left < 0 ? "" : s.substr(ans_left, ans_right - ans_left + 1);
    }
};
```

优化版本，用count来记录是否所有字母都满足

```c++
class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size();

        unordered_map<char, int> hash;

        for(char c : t)
        {
            hash[c]++;
        }
        int count = hash.size();
        int left = 0;
        int ans_left = -1, ans_right = m;
        for (int right = 0; right < m; right++)
        {
            if (hash.contains(s[right]));
            {
                hash[s[right]]--;
                // 减到0时说明这个字母已经全部包含，count可以减1。同时hash中的字母可以减到负数
                if(hash[s[right]]==0)
                {
                    count--;
                }
            }
            while(count == 0)
            {
                if (right - left < ans_right - ans_left)
                {
                    ans_left = left;
                    ans_right = right;
                }
                if (hash.contains(s[left]))
                {
                    // 加到0说明这个字母和需要的子字符串中的字母数量相等了，这时不能再加了，需要移动右指针了
                    if (hash[s[left]] == 0)
                    {
                        count++;
                    }
                    // 为什么这个在后面？
                    hash[s[left]]++;
                }
                left++;
            }
        }
        return ans_left < 0 ? "" : s.substr(ans_left, ans_right - ans_left + 1);
    }
};
```