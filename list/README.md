
### leetcode 234 
双指针：slow走到中心。  
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
### leetcode 2
用于熟悉加法过程
并且每次循环要进行0和空指针的判断
```c++
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0); // 保留的头指针
        ListNode* cur = dummy; // 当前指针，进行移动


        int carry = 0;

        while (l1 || l2 || carry !=0)
        {
            int digit1 = (l1) ? l1->val : 0;
            int digit2 = (l2) ? l2->val : 0;

            int sum = digit1 + digit2 + carry;
            int digit = sum % 10;
            carry = sum / 10;

            ListNode* n = new ListNode(digit);
            cur->next = n;
            cur = cur->next;

            l1 = (l1) ? l1->next : nullptr;
            l2 = (l2) ? l2->next : nullptr;
        }

        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};
```
