/*
输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。



示例 1：

输入：head = [1,3,2]
输出：[2,3,1]
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

//上面是必须用数组返回  如果是反向打印的话  可用入栈出栈
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

	// 递归也可以  但是链表过长的话就会 导致函数调用栈溢出

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
