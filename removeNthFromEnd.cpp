/*
给定一个链表，删除链表的倒数第 nn 个节点并返回链表的头指针
例如，
给出的链表为: 1\to 2\to 3\to 4\to 51→2→3→4→5, n= 2n=2.
删除了链表的倒数第 nn 个节点之后,链表变为1\to 2\to 3\to 51→2→3→5.

备注：
题目保证 nn 一定是有效的
请给出请给出时间复杂度为\ O(n) O(n) 的算法
示例1
输入
复制
{1,2},2
返回值
复制
{2}
*/

/**
* struct ListNode {
*	int val;
*	struct ListNode *next;
* };
*/

class Solution {
public:
	/**
	*
	* @param head ListNode类
	* @param n int整型
	* @return ListNode类
	*/


	ListNode* removeNthFromEnd(ListNode* head, int n)
	{
		ListNode *p, *slow, *fast;
		p = slow = fast = head;
		int len = 0;
		while (p != nullptr)
		{
			len++;
			p = p->next;
		}
		if (head == nullptr || n<0 || n>len)
			return NULL;
		if (n == len)
			return head->next;
		while (n-->0)
		{
			fast = fast->next;
			if (fast == nullptr)
				return NULL;
		}
		while (fast->next != nullptr)
		{
			fast = fast->next;
			slow = slow->next;
		}
		slow->next = slow->next->next;
		return head;
	}
};

///////////////////////////////////////////////////////////////////////
class Solution {
public:
	ListNode *removeNthFromEnd(ListNode *head, int n) 
	{
		if (head == NULL){
			return head;
		}
		ListNode* dummy = new ListNode(0);
		dummy->next = head;
		head = dummy;
		ListNode* slow = head;
		ListNode* fast = head;
		for (int i = 0; i < n; i++){
			fast = fast->next;
		}
		while (fast->next != NULL){
			fast = fast->next;
			slow = slow->next;
		}
		ListNode* temp = slow->next;
		slow->next = slow->next->next;
		delete temp;
		return dummy->next;
	}
};
