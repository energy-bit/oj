//给定一个二叉树的根节点 root ，返回它的 中序 遍历。

/*输入：root = [1,null,2,3]
输出：[1,3,2]
示例 2：

输入：root = []
输出：[]
示例 3：

输入：root = [1]
输出：[1]

输入：root = [1,2]
输出：[2,1]

输入：root = [1,null,2]
输出：[1,2]
*/

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode() : val(0), left(nullptr), right(nullptr) {}
*     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
*     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
* };
*/
class Solution {
public:
	void _inorderTraversal(TreeNode *root, vector<int> &v)
	{
		if (root != NULL)
		{
			_inorderTraversal(root->left, v);
			v.push_back(root->val);
			_inorderTraversal(root->right, v);
		}
	}
	vector<int> inorderTraversal(TreeNode* root)
	{
		vector<int> v;
		_inorderTraversal(root, v);
		return v;
	}
};