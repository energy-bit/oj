/*
����һ���������� nums ��

���һ������ (i,j) ���� nums[i] == nums[j] �� i < j ���Ϳ�����Ϊ����һ�� ������ ��
���غ����Ե���Ŀ��

 ʾ�� 1��

 ���룺nums = [1,2,3,1,1,3]
 �����4
 ���ͣ��� 4 ������ԣ��ֱ��� (0,3), (0,4), (3,4), (2,5) ���±�� 0 ��ʼ
 ʾ�� 2��

 ���룺nums = [1,1,1,1]
 �����6
 ���ͣ������е�ÿ�����ֶ��Ǻ�����
 ʾ�� 3��

 ���룺nums = [1,2,3]
 �����0
*/
class Solution {
public:
	int numIdenticalPairs(vector<int>& nums)
	{
		int count = 0;
		for (int i = 0; i<nums.size(); i++)
		{
			for (int j = i + 1; j<nums.size(); j++)
			{
				if (nums[i] == nums[j])
					count++;
			}
		}
		return count;
	}
};