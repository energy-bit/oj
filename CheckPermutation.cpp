/*
给定两个字符串 s1 和 s2，请编写一个程序，确定其中一个字符串的字符重新排列后，能否变成另一个字符串。

示例 1：

输入: s1 = "abc", s2 = "bca"
输出: true
示例 2：

输入: s1 = "abc", s2 = "bad"
输出: false

*/
class Solution {
public:
	bool CheckPermutation(string s1, string s2)
	{
		if (s1.size() != s2.size())
			return false;
		unordered_map <char, int> umap;
		for (int i = 0; i<s1.size(); i++)
		{
			umap[s1[i]]++;//计数 如果两个相同一个加一个减 最后为0
			umap[s2[i]]--;
		}
		for (int i = 0; i<s1.size(); i++)
		{
			if (umap[s1[i]] != 0)
				return false;
		}
		return true;
	}
};
