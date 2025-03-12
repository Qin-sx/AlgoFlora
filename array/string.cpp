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



int main()
{

    Solution_704 s704;
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;
    cout << s704.search(nums, target) << endl;

    return 0;
}