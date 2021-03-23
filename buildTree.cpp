/*


输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。

 例如，给出

 前序遍历 preorder = [3,9,20,15,7]
 中序遍历 inorder = [9,3,15,20,7]
 返回如下的二叉树：

 3
 / \
 9  20
 /  \
 15   7

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
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
	{
		if (preorder.empty() || inorder.empty())
			return nullptr;
		int *p = &preorder[0];// 保留vector 首元素的地址。
		int *q = &inorder[0];
		return tree(p, p + (preorder.size() - 1), q, q + (inorder.size() - 1));
	}
	TreeNode *tree(int *startpreorder, int *endpreorder, int *startinorder, int *endinorder)
	{
		int rootVal = startpreorder[0];//  根就是前序遍历的第一个数
		TreeNode *root = new TreeNode();
		root->val = rootVal;
		root->left = root->right = nullptr;
		if (startpreorder == endpreorder&&startinorder == endinorder&&startpreorder == startinorder)
		{
			return root;
		}
		int *rootinorder = startinorder;
		while (rootinorder <= endinorder&&*rootinorder != rootVal)
		{
			++rootinorder;  //  找到中序遍历根的位置
		}
		// if(rootinorder==endinorder&&*rootinorder!=rootVal)
		// return false;
		int LeftLength = rootinorder - startinorder;//   中序遍历根的左边就是左子树
		int* LeftPreoeder = startpreorder + LeftLength;
		if (LeftLength>0)
		{
			root->left = tree(startpreorder + 1, LeftPreoeder, startinorder, rootinorder - 1);
		}
		if (LeftLength<endpreorder - startpreorder)
		{
			root->right = tree(LeftPreoeder + 1, endpreorder, rootinorder + 1, endinorder);
		}
		return root;
	}
};