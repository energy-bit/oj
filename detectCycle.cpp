/*

����һ���������������ػ�����ڽڵ㣬���û�л�������null
��չ��
���ܸ��������ö���ռ�Ľⷨô��
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
	ListNode *detectCycle(ListNode *head)
	{
		if (head == NULL)
			return 0;
		ListNode* fast, *slow;
		fast = slow = head;
		while (fast != NULL&&fast->next != NULL)
		{
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow)
				break;
		}
		if (fast == NULL || fast->next == NULL)
			return NULL;
		fast = head;
		while (fast != slow)
		{
			fast = fast->next;
			slow = slow->next;
		}
		return fast;
	}
};
