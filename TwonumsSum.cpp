/*
给出一个整数数组，请在数组中找出两个加起来等于目标值的数，
你给出的函数twoSum 需要返回这两个数字的下标（index1，index2），需要满足 index1 小于index2.。注意：下标是从1开始的
假设给出的数组中只存在唯一解
例如：
给出的数组为 {20, 70, 110, 150},目标值为90
输出 index1=1, index2=2


示例1
输入
复制
[3,2,4],6
返回值
复制
[2,3]
*/

//这是两数之和加强版  数组不排序。
class Solution {
public:
	/**
	*
	* @param numbers int整型vector
	* @param target int整型
	* @return int整型vector
	*/
	vector<int> twoSum(vector<int>& numbers, int target)
	{
		int  left = 0;
		int  right = numbers.size();
		vector<int> st;
		if (numbers.size() == 1)
			return st;
		for (int i = 0; i < right; i++)
		{
			for (int j = i + 1; j < right; j++)
			{
				if (numbers[i] + numbers[j] == target)
				{
					st.push_back(i + 1);
					st.push_back(j + 1);
				}
			}
		}
		return st;
	}
};


//  第二种方法
class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		vector<int>res;//保存结果
		map<int, int>mp;//定义一个哈希表存储numbers[i]和对应的下标
		for (int i = 0; i < numbers.size(); i++) {//进行标记
			mp[numbers[i]] = i;
		}
		for (int i = 0; i < numbers.size(); i++) {
			//每遍历一个numbers[i]就去对应的mp里找有没有target - numbers[i]
				//如果有就返回结果
				//如果没有就找下一个
			if (mp.find(target - numbers[i]) != mp.end() && i != mp[target - numbers[i]]){
				res.push_back(i + 1);
				res.push_back(mp[target - numbers[i]] + 1);
				return res;
			}
		}
		return res;
	}
};
	