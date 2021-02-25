/*
统计一个数字在排序数组中出现的次数。

 

 示例 1:

 输入: nums = [5,7,7,8,8,10], target = 8
 输出: 2
 示例 2:

 输入: nums = [5,7,7,8,8,10], target = 6
 输出: 0

*/
class Solution {
public:
	int search(vector<int>& nums, int target) {
		if (nums.size() == 0)
		{
			return 0;
		}
		int left = 0;
		int right = nums.size() - 1;
		while (nums[left] != nums[right])
		{
			int mid = (left + right) / 2;
			if (nums[mid] < target)
			{
				left = mid + 1;
			}
			else if (nums[mid] > target)
			{
				right = mid - 1;
			}
			else
			{
				if (nums[right] == target)
				{
					++left;
				}
				else
				{
					--right;
				}
			}
		}
		if (nums[left] == target)
		{
			return right - left + 1;
		}
		return 0;
	}
};