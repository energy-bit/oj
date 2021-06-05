/*
给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
 
 示例 1：


 输入：head = [1,2,6,3,4,5,6], val = 6
 输出：[1,2,3,4,5]
 示例 2：

 输入：head = [], val = 1
 输出：[]
 示例 3：

 输入：head = [7,7,7,7], val = 7
 输出：[]

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

//第一种方法
class Solution {
public:
	ListNode* removeElements(ListNode* head, int val)
	{
		if (head == NULL)
			return NULL;
		ListNode* p = head;
		vector<int> nums;
		while (p != NULL)
		{
			if (p->val != val)
			{
				nums.push_back(p->val);
			}
			p = p->next;
		}
		if (nums.empty())
		{
			return NULL;
		}
		int n = nums.size();
		ListNode* k = head;
		while (--n)
		{
			head = head->next;
		}
		head->next = NULL;

		ListNode* q = k;
		for (size_t i = 0; i<nums.size(); i++)
		{

			q->val = nums[i];
			q = q->next;
		}
		return k;
	}
};

//////////////////////////////////////////////////////////////////////////////
     //小优化一下

class Solution {
public:
	ListNode* removeElements(ListNode* head, int val)
	{
		if (head == NULL)
			return NULL;
		ListNode* p = head;
		vector<int> nums;
		while (p != NULL)
		{
			if (p->val != val)
			{
				nums.push_back(p->val);
			}
			p = p->next;
		}
		if (nums.empty())
		{
			return NULL;
		}
		ListNode* q = head;
		for (size_t i = 0; i<nums.size(); i++)
		{

			q->val = nums[i];
			if (i == nums.size() - 1)
			{
				q->next = NULL;
			}
			else
			{
				q = q->next;
			}
		}

		return head;
	}
};

//第二种方法  
class Solution
{
public:
	ListNode* removeElements(ListNode* head, int val)
	{
		ListNode * dummy = new ListNode(-1);
		dummy->next = head;
		ListNode * p = dummy;
		while (p->next)
		{
			if (p->next->val == val)
				p->next = p->next->next;  //删除(p->next)
			else
				p = p->next;
		}
		return dummy->next;
	}
};