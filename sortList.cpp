/*
���������ͷ��� head ���뽫�䰴 ���� ���в����� ���������� ��

���룺head = [4,2,1,3]
�����[1,2,3,4]

���룺head = [-1,5,3,4,0]
�����[-1,0,3,4,5]
ʾ�� 3��

���룺head = []
�����[]
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
	ListNode* sortList(ListNode* head)
	{
		vector<int> iv;
		ListNode *q = head;
		while (q != nullptr)
		{
			iv.push_back(q->val);
			q = q->next;
		}
		sort(iv.begin(), iv.end());
		ListNode *p = head;
		for (size_t i = 0; i<iv.size(); i++)
		{
			p->val = iv[i];
			p = p->next;
		}
		return head;
	}
};