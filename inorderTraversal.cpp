//����һ���������ĸ��ڵ� root ���������� ���� ������

/*���룺root = [1,null,2,3]
�����[1,3,2]
ʾ�� 2��

���룺root = []
�����[]
ʾ�� 3��

���룺root = [1]
�����[1]

���룺root = [1,2]
�����[2,1]

���룺root = [1,null,2]
�����[1,2]
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