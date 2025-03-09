#include <bits/stdc++.h>
using namespace std;

class Solution_704 {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right)
        {
            int middle = left + ((right - left) >> 1);
            if (target < nums[middle])
            {
                right = middle - 1; // for breaking the loop
            }
            else if (target > nums[middle])
            {
                left = middle + 1; // for breaking the loop
            }
            else
            {
                return middle;
            }
        }
        return -1;
    }
};

class Solution_49 {
    string get_signature(const string& s) {
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        stringstream ss;
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) {
                ss << (char)('a' + i) << count[i];
            }
        }
        return ss.str();
    }

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> groups;

        for (int i = 0; i < strs.size(); ++i)
        {
            auto sign = get_signature(strs[i]);
            groups[sign].emplace_back(strs[i]);
        }

        for (auto g : groups)
        {
            ans.emplace_back(g.second);
        }
        return ans;
    }
};

int main()
{

    Solution_704 s704;
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;
    cout << s704.search(nums, target) << endl;
    

    Solution_49 s49;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto ans = s49.groupAnagrams(strs);
    for (auto v : ans)
    {
        for (auto s : v)
        {
            cout << s << " ";
        }
        cout << endl;
    }


    return 0;
}