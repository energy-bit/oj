/*
����һ���������飬�����������ҳ���������������Ŀ��ֵ������
������ĺ���twoSum ��Ҫ�������������ֵ��±꣨index1��index2������Ҫ���� index1 С��index2.��ע�⣺�±��Ǵ�1��ʼ��
���������������ֻ����Ψһ��
���磺
����������Ϊ {20, 70, 110, 150},Ŀ��ֵΪ90
��� index1=1, index2=2


ʾ��1
����
����
[3,2,4],6
����ֵ
����
[2,3]
*/

//��������֮�ͼ�ǿ��  ���鲻����
class Solution {
public:
	/**
	*
	* @param numbers int����vector
	* @param target int����
	* @return int����vector
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


//  �ڶ��ַ���
class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		vector<int>res;//������
		map<int, int>mp;//����һ����ϣ��洢numbers[i]�Ͷ�Ӧ���±�
		for (int i = 0; i < numbers.size(); i++) {//���б��
			mp[numbers[i]] = i;
		}
		for (int i = 0; i < numbers.size(); i++) {
			//ÿ����һ��numbers[i]��ȥ��Ӧ��mp������û��target - numbers[i]
				//����оͷ��ؽ��
				//���û�о�����һ��
			if (mp.find(target - numbers[i]) != mp.end() && i != mp[target - numbers[i]]){
				res.push_back(i + 1);
				res.push_back(mp[target - numbers[i]] + 1);
				return res;
			}
		}
		return res;
	}
};
	