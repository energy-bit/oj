/*
请判断一个链表是否为回文链表。

示例 1:

输入: 1->2
输出: false
示例 2:

输入: 1->2->2->1
输出: true
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
     bool isPalindrome(ListNode* head) 
     {
         if(head==nullptr||head->next==nullptr)
         {
             return true;
         }
         ListNode *fast=head,*slow=head;
         ListNode *q,*pre=NULL;
         while(fast!=nullptr&&fast->next!=nullptr)
         {
             q=slow;
             slow=slow->next;
             fast=fast->next->next;//快慢遍历

                 //翻转
             q->next=pre;
             pre=q;
         }
         if(fast!=nullptr)//奇数个节点时跳过中间节点
         {
             slow=slow->next;
         }
         while(q!=nullptr)//前半部分和后半部分比较
         {
             if(q->val!=slow->val)
             {
                 return false;
             }
             q=q->next;
             slow=slow->next;
         }
         return true;
     }
 };



//第二种方法
class Solution {
public:
	bool isPalindrome(ListNode* head)
	{
		if (head == nullptr || head->next == nullptr)
		{
			return true;
		}
		int  length = 0;
		ListNode* q = head;
		while (q != nullptr)
		{
			length++;
			q = q->next;
		}
		vector<int> st(length, 0);
		int k = 0;
		while (head != nullptr)
		{
			st[k++] = head->val;
			head = head->next;
		}
		int j = 0, i = 0;
		for (i = 0, j = st.size() - 1; i < j; ++i, --j)
		{
			if (st[i] != st[j])
			{
				return false;
			}
		}
		return true;
	}
};