/*
��дһ��������������ʱ������ֱ�ӽ���numbers = [a, b]��a��b��ֵ��

ʾ����

����: numbers = [1,2]
���: [2,1]
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
// �ڶ��ַ���
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

