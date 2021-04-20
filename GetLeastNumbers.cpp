/*
给定一个数组，找出其中最小的K个数。例如数组元素是4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4。如果K>数组的长度，那么返回一个空的数组
示例1
输入
复制
[4,5,1,6,2,7,3,8],4
返回值
复制
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