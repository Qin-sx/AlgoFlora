
leetcode 234 
双指针：slow走到中心
遍历过程中，用pre指针反转前半部分指针。
最后从中心开始判断slow是否等于pre。（pre向前走，slow向后走）
```c++
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* pre = head;
        ListNode* before = nullptr;

        while (fast != nullptr && fast->next != nullptr)
        {
            pre = slow;

            slow = slow->next;
            fast = fast->next->next;

            pre->next = before;
            before = pre;
        }

        if(fast != nullptr) // odd number
            slow = slow->next;

        while (slow != nullptr)
        {
            if (slow->val != pre->val)
            {
                return false;
            }

            pre = pre->next;
            slow = slow->next;
        }

        return true;
    }
};
```
