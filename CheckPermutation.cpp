/*
���������ַ��� s1 �� s2�����дһ������ȷ������һ���ַ������ַ��������к��ܷ�����һ���ַ�����

ʾ�� 1��

����: s1 = "abc", s2 = "bca"
���: true
ʾ�� 2��

����: s1 = "abc", s2 = "bad"
���: false

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
			umap[s1[i]]++;//���� ���������ͬһ����һ���� ���Ϊ0
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
