/*
����һ�����飬�ҳ�������С��K��������������Ԫ����4,5,1,6,2,7,3,8��8�����֣�����С��4��������1,2,3,4�����K>����ĳ��ȣ���ô����һ���յ�����
ʾ��1
����
����
[4,5,1,6,2,7,3,8],4
����ֵ
����
[1,2,3,4]

*/
class Solution {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
	{
		vector<int> nums;
		int len = input.size();
		if (k>len || k == 0)
			return nums;
		sort(input.begin(), input.end());
		/*
		int i=0;
		for( i=0;i<k;i++)
		{
		nums.push_back(input[i]);
		}
		return nums;
		*/
		return vector<int>{input.begin(), input.begin() + k};
	}
};