/*
448. �ҵ�������������ʧ������
����һ����Χ��  1 �� a[i] �� n ( n = �����С ) �� �������飬�����е�Ԫ��һЩ���������Σ���һЩֻ����һ�Ρ�

�ҵ������� [1, n] ��Χ֮��û�г����������е����֡�

�����ڲ�ʹ�ö���ռ���ʱ�临�Ӷ�ΪO(n)�������������������? ����Լٶ����ص����鲻���ڶ���ռ��ڡ�

ʾ��:

����:
[4,3,2,7,8,2,3,1]

���:
[5,6]
*/

class Solution {
public:
	vector<int> findDisappearedNumbers(vector<int>& nums)
	{
		vector<int> res;
		if (nums.empty())
			return nums;
		for (int i = 0; i<nums.size(); i++)
		{
			int index = (nums[i] - 1) % nums.size();
			nums[index] += nums.size();
		}
		for (int i = 0; i<nums.size(); i++)
		{
			if (nums[i] <= nums.size())
				res.push_back(i + 1);
		}
		return res;
	}
};