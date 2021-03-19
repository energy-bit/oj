/*
给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right 。请你反转从位置 left 到位置 right 的链表节点，返回 反转后的链表 。


1->2->3->4->5
left=2   right=4
输出：1->4->3->2->5


1->2->3->4->5
left=1  right=5
输出： 5->4->3->2->1

head = [5], left = 1, right = 1
输出：[5]

*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode() : val(0), next(nullptr) {}
*     ListNode(int x) : val(x), next(nullptr) {}
*     ListNode(int x, ListNode *next) : val(x), next(next) {}
* };
*/
class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int left, int right)
	{
		vector<int> iv;
		ListNode *q = head;
		while (q != nullptr)
		{
			iv.push_back(q->val);
			q = q->next;
		}
		reverse(iv.begin() + left - 1, iv.begin() + right);
		ListNode* p = head;
		for (size_t i = 0; i < iv.size(); ++i)
		{
			p->val = iv[i];
			p = p->next;
		}
		return head;

	}
};