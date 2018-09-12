/*
题目描述：
给定具有头节点头的非空的单链表，返回链表的中间节点。 
如果有两个中间节点，则返回第二个中间节点。
Input: [1,2,3,4,5]
Output: Node 3 from this list (Serialization: [3,4,5])
Input: [1,2,3,4,5,6]
Output: Node 4 from this list (Serialization: [4,5,6])
解题思路：
1.设置一个slow指针和一个fast指针，slow一次走一步，fast一次走两步
2.当fast指针走到末尾时，slow指针刚好走到中间
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
*/

#include<iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x): val(x), next(NULL){}
};

ListNode* middleNode(ListNode* head)
{
	ListNode* slow = head;
	ListNode* fast = head;

	while(fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	return slow;
}

int main()
{
	
}

