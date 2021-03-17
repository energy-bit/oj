/*

����һ����������������һ������s���������в�����������ʹ�����ǵĺ�������s������ж�����ֵĺ͵���s�����������һ�Լ��ɡ�

 ʾ�� 1��

 ���룺nums = [2,7,11,15], target = 9
 �����[2,7] ���� [7,2]
 ʾ�� 2��

 ���룺nums = [10,26,30,31,47,60], target = 40
 �����[10,30] ���� [30,10]

 */

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		int left = 0;
		int right = nums.size() - 1;
		int sum = 0;
		while (left<right)
		{
			sum = nums[left] + nums[right];
			if (sum<target)
			{
				left++;
			}
			else if (sum>target)
			{
				right--;
			}
			else
				return vector<int>{nums[left], nums[right]};
		}
		return vector<int>{};
	}
};