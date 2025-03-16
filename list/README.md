
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
### leetcode 445 (leetcode 2进阶版)
用于熟悉反转过程
用于熟悉加法过程
并且每次循环要进行0和空指针的判断
```c++
class Solution {

    ListNode* reverse(ListNode* head)
    {
        ListNode* prev = nullptr;

        while(head)
        {
            ListNode* after = head->next;
            head->next = prev;
            prev = head;
            head = after;
        }
        return prev;
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        l1 = reverse(l1);
        l2 = reverse(l2);

        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;

        int carry = 0;
        while((l1) || (l2) || carry)
        {
            int digit1 = (l1) ? l1->val : 0;
            int digit2 = (l2) ? l2->val : 0;

            int sum = digit1 + digit2 + carry;

            int digit = sum % 10;
            carry = sum / 10;

            ListNode* newNode = new ListNode(digit);

            cur->next = newNode;
            cur = cur->next;

            l1 = (l1) ? l1->next : nullptr;
            l2 = (l2) ? l2->next : nullptr;
        }

        auto ans = dummy->next;
        delete dummy;

        ans = reverse(ans);
        return ans;
    }
};
```

### leetcode 138
通过hashmap建立索引，使得new list可以轻而易举地复制old list。
```c++
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        std::unordered_map<Node*, Node*> hash;
        Node* cur = head;

        while (cur)
        {
            hash[cur] = new Node(cur->val);
            cur = cur->next;
        }

        cur = head;

        while (cur)
        {
            Node* copy = hash[cur];
            copy->next = hash[cur->next];
            copy->random = hash[cur->random];
            cur = cur->next;
        }

        return hash[head];
    }
};
```
