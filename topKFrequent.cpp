/*

����һ���������� nums ��һ������ k �����㷵�����г���Ƶ��ǰ k �ߵ�Ԫ�ء�����԰� ����˳�� ���ش𰸡�



ʾ�� 1:

����: nums = [1,1,1,2,2,3], k = 2
���: [1,2]
ʾ�� 2:

����: nums = [1], k = 1
���: [1]
*/

//��һ��   ��̫��  ֻ��ͨ����������
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


	//�ڶ���  ��ȷ��  ���ǵ�������     TOPK   һ���ÿ��Ż�Ͱ�š�
	static bool cmp(pair<int, int>&data1, pair<int, int>&data2)
	{
		return data1.second > data2.second;
	}

	//ǰ K ����ƵԪ��
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