#### 题目描述
您将获得两个非空链表，表示两个非负整数。数字以相反的顺序存储，每个节点包含一个数字。  
添加两个数字并将其作为链接列表返回。 您可以假设这两个数字第一位不会是零，除了数字0本身。
```
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
```

#### 代码实现
```cpp 
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
```
```cpp
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        int sum = 0;
        
        ListNode* head = new ListNode(0);
        ListNode* curr = head;
        
        while(l1 && l2){
            sum = l1->val + l2->val + carry;
            carry = sum / 10;
            
            curr->next = new ListNode(sum % 10);;
            curr = curr->next;
            
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while(l1){
            sum = l1->val + carry;
            carry = sum / 10;
            
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            
            l1 = l1->next;
        }
        
        while(l2){
            sum = l2->val + carry;
            carry = sum / 10;
            
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            
            l2 = l2->next;
        }
        
        if(carry > 0){
            curr->next = new ListNode(carry);
        }
        
        
        return head->next;
    }
};
```
```cpp
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        int sum = 0;
        
        ListNode* head = new ListNode(0);
        ListNode* curr = head;
        
        while(l1 || l2){
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0;
            
            sum = x + y + carry;
            carry = sum / 10;
            
            curr->next = new ListNode(sum % 10);;
            curr = curr->next;
            
            if(l1)  l1 = l1->next;
            if(l2)  l2 = l2->next;
        }
        
     
        
        if(carry > 0){
            curr->next = new ListNode(carry);
        }
        
        
        return head->next;
    }
};
```