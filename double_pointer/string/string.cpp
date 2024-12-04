#include <bits/stdc++.h>
using namespace std;

class Solution_2825
{
public:
    bool canMakeSubsequence(string str1, string str2) {
        int str2Index = 0;
        int lengthStr1 = str1.size();
        int lengthStr2 = str2.size();
        for (int str1Index = 0; str1Index < lengthStr1 && str2Index < lengthStr2; ++str1Index)
        {
            if (str1[str1Index] == str2[str2Index] ||
                str1[str1Index] + 1 == str2[str2Index] ||
                str1[str1Index] - 25 == str2[str2Index])
                {
                    str2Index++;
                }
        }
        return str2Index == lengthStr2;
    }
};

int main()
{

    Solution_2825 s2825;
    cout << s2825.canMakeSubsequence("abc", "ad") << endl;
    cout << s2825.canMakeSubsequence("zc", "ad") << endl;
    cout << s2825.canMakeSubsequence("ab", "d") << endl;

    return 0;
}