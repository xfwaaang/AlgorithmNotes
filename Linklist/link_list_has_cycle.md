#### 题目描述
给定一个链表，确定它是否含有一个循环  
要求空间复杂度：O(1)

#### 代码实现

[code](/Linklist/link_list_has_cycle.cpp)

```cpp
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL){}
};

bool hasCycle(ListNode *head)
{
	if(head == NULL)	
		return false;
	ListNode *slow = head;	//慢指针,一次走一步
	ListNode *fast = head;	//快指针,一次走两步
	// 如果有环，快指针一定能追上慢指针
	while(fast->next != NULL && fast->next->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast)	
			return true;
	}
	return false;
}
```