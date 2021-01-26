/*给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。

 

示例：

输入："Let's take LeetCode contest"
输出："s'teL ekat edoCteeL tsetnoc"

*/
class Solution {
public:
	void reverse(string&s, int start, int end)
	{
		while (start<end)
		{
			char tmp = s[start];
			s[start] = s[end];
			s[end] = tmp;
			start++;
			end--;
		}
	}
	string reverseWords(string s)
	{
		size_t start = 0;
		size_t end = 0;
		while (start<s.size())
		{
			end = s.find(' ', start);
			if (end == string::npos)
				break;
			reverse(s, start, end - 1);
			start = end + 1;
		}
		reverse(s, start, s.size() - 1);
		return s;
	}
};