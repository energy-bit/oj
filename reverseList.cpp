/*
定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。

 

 示例:

 输入: 1->2->3->4->5->NULL
 输出: 5->4->3->2->1->NULL

*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		stack<ListNode*> s;
		if (head == NULL)
			return NULL;
		while (head->next != NULL)
		{
			s.push(head);
			head = head->next;
		}
		ListNode *realHead = head;
		while (!s.empty())
		{
			head->next = s.top();
			head = head->next;
			s.pop();
		}
		head->next = NULL;
		return realHead;
	}
};
/////////////////////////////////////////////////////////////////////////////////

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };

*/
// 双指针法

struct ListNode* reverseList(struct ListNode* head)
{
	if (head == NULL || head->next == NULL)
		return head;
	struct ListNode *prv = NULL;
	struct ListNode *q = head;
	while (q)
	{
		struct ListNode *tmp = q->next;
		q->next = prv;// 头先指向空
		prv = q;//在移动prv
		q = tmp;
	}
	return prv;
}
/*
递归解法
struct ListNode* reverseList(struct ListNode* head)
{
	if (head == NULL || head->next == NULL)
		return head;
	struct  ListNode *q = reverseList(head->next);
	head->next->next = head;
	head->next = NULL;
	return q;
}
*/
