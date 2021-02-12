/*给定一棵二叉搜索树，请找出其中第k大的节点。

 

示例 1:

输入: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
输出: 4
示例 2:

输入: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
输出: 4
*/
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	int res = 0;
	int kthLargest(TreeNode* root, int k)
	{
		inorder(root, k);
		return res;
	}
	void inorder(TreeNode* root, int &k)
	{   //注意k是引用形式
		if (root == NULL)
			return;
		inorder(root->right, k);        //中序倒序遍历，右-根-左，可以得到递减序列
		if (--k == 0)
		{
			res = root->val;
			return;
		}
		inorder(root->left, k);
	}
};
/*
//非递归方式。就需要我们自己手动维护一个调用栈。
//，只要把访问左右子树的顺序换一下，就成了正常的中序遍历了。
class Solution {
public:
int kthLargest(TreeNode* root, int k) {
vector<TreeNode*> worker;
while (root || worker.size()) {
while (root) {
worker.push_back(root); // 根入栈
root = root->right; // 访问右子树，向下探
}
root = worker.back(), worker.pop_back(); // 出栈
if (!--k) return root->val;
root = root->left; // 访问左子树
}
return 0;
}
};
*/