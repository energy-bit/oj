/*

给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。



示例 1:

输入: nums = [1,1,1,2,2,3], k = 2
输出: [1,2]
示例 2:

输入: nums = [1], k = 1
输出: [1]
*/

//第一种   不太对  只能通过正整数的
class Solution {
public:
	//     vector<int> topKFrequent(vector<int>& nums, int k) 
	//     {
	//         vector<int> result;
	//         if(nums.size()==0)
	//         return result;
	//         int a[100000]={0};
	//         for(int i=0;i<nums.size();i++)
	//         {
	//             a[nums[i]]++;
	//         }

	//         int n=sizeof(a)/sizeof(a[0]);
	//         for(int i=0;i<k;i++)
	//         {
	//             int max = *max_element(a,a+n); 
	//             int index=find(a, a+n,max)-a;
	//             result.push_back(index);
	//             a[index]=0;
	//         }
	//         return result;
	//     }
	// };
	/////////////////////////////////////////////////////////////////////////////


	//第二种  正确的  考虑到负数的     TOPK   一般用快排或桶排。
	static bool cmp(pair<int, int>&data1, pair<int, int>&data2)
	{
		return data1.second > data2.second;
	}

	//前 K 个高频元素
	vector<int>topKFrequent(vector<int>& nums, int k) {
		vector<int>result;
		unordered_map<int, int>HM;
		for (int i : nums)
		{
			HM[i]++;
		}
		vector<pair<int, int>>data;
		for (auto j : HM)
		{
			data.emplace_back(j);
		}
		sort(data.begin(), data.end(), cmp);
		for (int i = 0; i < k; i++)
		{
			result.emplace_back(data[i].first);
		}

		return result;
	}
};