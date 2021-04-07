/*
���ж�һ�������Ƿ�Ϊ��������

ʾ�� 1:

����: 1->2
���: false
ʾ�� 2:

����: 1->2->2->1
���: true
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

//��һ�ַ���
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
             fast=fast->next->next;//��������

                 //��ת
             q->next=pre;
             pre=q;
         }
         if(fast!=nullptr)//�������ڵ�ʱ�����м�ڵ�
         {
             slow=slow->next;
         }
         while(q!=nullptr)//ǰ�벿�ֺͺ�벿�ֱȽ�
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



//�ڶ��ַ���
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