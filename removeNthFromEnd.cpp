/*
����һ������ɾ������ĵ����� nn ���ڵ㲢���������ͷָ��
���磬
����������Ϊ: 1\to 2\to 3\to 4\to 51��2��3��4��5, n= 2n=2.
ɾ��������ĵ����� nn ���ڵ�֮��,�����Ϊ1\to 2\to 3\to 51��2��3��5.

��ע��
��Ŀ��֤ nn һ������Ч��
����������ʱ�临�Ӷ�Ϊ\ O(n) O(n) ���㷨
ʾ��1
����
����
{1,2},2
����ֵ
����
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
	* @param head ListNode��
	* @param n int����
	* @return ListNode��
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
