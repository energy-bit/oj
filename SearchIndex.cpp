/*
请实现有重复数字的升序数组的二分查找
给定一个 元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1
示例1
输入
复制
[1,2,4,4,5],4
返回值
复制
2
说明
从左到右，查找到第1个为4的，下标为2，返回2
示例2
输入
复制
[1,2,4,4,5],3
返回值
复制
-1
示例3
输入
复制
[1,1,1,1,1],1
返回值
复制
0
*/

class Solution {
public:
	/**
	* 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	*
	* 如果目标值存在返回下标，否则返回 -1
	* @param nums int整型vector
	* @param target int整型
	* @return int整型
	*/

	int search(vector<int>& nums, int target)
	{
		int left = 0;
		int right = nums.size() - 1;
		int mid = 0;
		while (left <= right)
		{
			int mid = left + (right - left) / 2;
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
				//找到之后，往左边找
				while (mid != 0 && nums[mid] == nums[mid - 1])
					mid--;
				return mid;
			}
		}
		return -1;
	}
};