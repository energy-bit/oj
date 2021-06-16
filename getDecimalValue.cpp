/*
给你一个单链表的引用结点 head。链表中每个结点的值不是 0 就是 1。已知此链表是一个整数数字的二进制表示形式。

请你返回该链表所表示数字的 十进制值 。

 示例 1：

 输入：head = [1,0,1]
 输出：5
 解释：二进制数 (101) 转化为十进制数 (5)
 示例 2：

 输入：head = [0]
 输出：0
 示例 3：

 输入：head = [1]
 输出：1
 示例 4：

 输入：head = [1,0,0,1,0,0,1,1,1,0,0,0,0,0,0]
 输出：18880
 示例 5：

 输入：head = [0,0]
 输出：0

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
	int getDecimalValue(ListNode* head)
	{
		ListNode* p = head;
		int ans = 0;
		while (p != NULL)
		{
			ans = ans * 2 + p->val;
			p = p->next;
		}
		return ans;
	}
};


/*
5÷2=2余1
2÷2=1余0
1÷2=0余1
===> 得出二进制 101 .
反推回去 商 x 除数 + 余数
=> 0 x 2 + 1 = 1
-> 1 x 2 + 0 = 2
-> 2 x 2 +1 = 5
*/


