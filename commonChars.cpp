/*

��������Сд��ĸ��ɵ��ַ������� A�������б��е�ÿ���ַ����ж���ʾ��ȫ���ַ��������ظ��ַ�����ɵ��б����磬���һ���ַ���ÿ���ַ����г��� 3 �Σ������� 4 �Σ�����Ҫ�����մ��а������ַ� 3 �Ρ�

����԰�����˳�򷵻ش𰸡�

ʾ�� 1��

���룺["bella","label","roller"]
�����["e","l","l"]
ʾ�� 2��

���룺["cool","lock","cook"]
�����["c","o"]
*/

class Solution {
public:
	vector<string> commonChars(vector<string>& A)
	{
		vector<string> result;
		if (A.size() == 0) return result;
		int hash[26] = { 0 }; // ����ͳ�������ַ������ַ����ֵ���СƵ��
		for (int i = 0; i < A[0].size(); i++)
		{ // �õ�һ���ַ�����hash��ʼ��
			hash[A[0][i] - 'a']++;
		}
		int hashOtherStr[26] = { 0 }; // ͳ�Ƴ���һ���ַ������ַ��ĳ���Ƶ��
		for (int i = 1; i < A.size(); i++)
		{
			memset(hashOtherStr, 0, 26 * sizeof(int));
			for (int j = 0; j < A[i].size(); j++)
			{
				hashOtherStr[A[i][j] - 'a']++;
			}
			// ����hash����֤hash��ͳ��26���ַ��������ַ�������ֵ���С����
			for (int k = 0; k < 26; k++)
			{
				hash[k] = min(hash[k], hashOtherStr[k]);
			}
		}
		// ��hashͳ�Ƶ��ַ�������ת�������ʽ
		for (int i = 0; i < 26; i++)
		{
			while (hash[i] != 0)
			{ // ע��������while������ظ����ַ�
				string s(1, i + 'a'); // char -> string
				result.push_back(s);
				hash[i]--;
			}
		}
		return result;
	}
};