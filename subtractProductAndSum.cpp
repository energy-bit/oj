/*
1281. 整数的各位积和之差
给你一个整数 n，请你帮忙计算并返回该整数「各位数字之积」与「各位数字之和」的差。

示例 1：

输入：n = 234
输出：15
解释：
各位数之积 = 2 * 3 * 4 = 24
各位数之和 = 2 + 3 + 4 = 9
结果 = 24 - 9 = 15
示例 2：

输入：n = 4421
输出：21
解释：
各位数之积 = 4 * 4 * 2 * 1 = 32
各位数之和 = 4 + 4 + 2 + 1 = 11
结果 = 32 - 11 = 21
*/
class Solution {
public:
	int subtractProductAndSum(int n)
	{
		vector<int> iv;
		while (n != 0)
		{
			int x = n % 10;
			n = n / 10;
			iv.push_back(x);
		}
		int s = 1;
		int i = 0;
		int q = 0;
		for (i = 0; i<iv.size(); i++)
		{
			s = s*iv[i];
			q = q + iv[i];
		}
		return s - q;
	}
};