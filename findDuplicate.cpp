﻿/*
给定一个包含 n + 1 个整数的数组 nums ，其数字都在 1 到 n 之间（包括 1 和 n），可知至少存在一个重复的整数。

假设 nums 只有 一个重复的整数 ，找出 这个重复的数 。

你设计的解决方案必须不修改数组 nums 且只用常量级 O(1) 的额外空间。
 示例 1：

 输入：nums = [1,3,4,2,2]
 输出：2
 示例 2：

 输入：nums = [3,1,3,4,2]
 输出：3
 示例 3：

 输入：nums = [1,1]
 输出：1
 示例 4：

 输入：nums = [1,1,2]
 输出：1
*/
// 排序
 class Solution {
 public:
     int findDuplicate(vector<int>& nums) 
     {
        sort(nums.begin(),nums.end());
        int i=0;
        for(i=0;i<nums.size();i++)
        {
            if(nums[i]==nums[i+1])
            return nums[i];
        }
        return nums[i];
     }
 };

//快慢指针
class Solution {
public:
	int findDuplicate(vector<int>& nums)
	{
		int slow = 0, fast = 0;
		do {
			slow = nums[slow];
			fast = nums[nums[fast]];
		} while (slow != fast);
		slow = 0;
		while (slow != fast)
		{
			slow = nums[slow];
			fast = nums[fast];
		}
		return slow;
	}
};