/*
编写一个函数，不用临时变量，直接交换numbers = [a, b]中a与b的值。

示例：

输入: numbers = [1,2]
输出: [2,1]
*/
class Solution {
public:
	vector<int> swapNumbers(vector<int>& numbers)
	{
		int i = 0;
		numbers[i] = numbers[i] ^ numbers[i + 1];
		numbers[i + 1] = numbers[i + 1] ^ numbers[i];
		numbers[i] = numbers[i] ^ numbers[i + 1];
		return numbers;
	}
};
// 第二种方法
class Solution {
public:
	vector<int> swapNumbers(vector<int>& numbers)
	{
		if (numbers[0] == numbers[1])
			return numbers;
		numbers[0] -= numbers[1];
		numbers[1] += numbers[0];
		numbers[0] = abs(numbers[1] - numbers[0]);
		return numbers;
	}
};

