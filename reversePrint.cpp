/*
����һ�������ͷ�ڵ㣬��β��ͷ����������ÿ���ڵ��ֵ�������鷵�أ���



ʾ�� 1��

���룺head = [1,3,2]
�����[2,3,1]
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
	vector<int> reversePrint(ListNode* head)
	{
		vector<int> iv;
		while (head != nullptr)
		{
			iv.push_back(head->val);
			head = head->next;
		}
		reverse(iv.begin(), iv.end());
		return iv;

	}
};

//�����Ǳ��������鷵��  ����Ƿ����ӡ�Ļ�  ������ջ��ջ
* /
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

	void  reversePrint(ListNode* head)
	{
		std::stack<ListNode*> nodes;
		ListNode *pNode = head;
		while (pNode != nullptr)
		{
			nodes.push(pNode);
			pNode = pNode->next;
		}
		while (!nodes.empty())
		{
			pNode = nodes.top();
			printf("%d\t", pNode->val);
			nodes.pop()
		}
	};

	// �ݹ�Ҳ����  ������������Ļ��ͻ� ���º�������ջ���

		void  reversePrint(ListNode* head)
		{
			if (head != nullptr)
			{
				if (head->next != nullptr)
				{
					reversePrint(head->next);
				}
				printf("%d\t", head->val);
			}
		}
