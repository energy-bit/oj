/*
��ʵ�����ظ����ֵ���������Ķ��ֲ���
����һ�� Ԫ������ģ������������� nums ��һ��Ŀ��ֵ target  ��дһ���������� nums �е� target�����Ŀ��ֵ���ڷ����±꣬���򷵻� -1
ʾ��1
����
����
[1,2,4,4,5],4
����ֵ
����
2
˵��
�����ң����ҵ���1��Ϊ4�ģ��±�Ϊ2������2
ʾ��2
����
����
[1,2,4,4,5],3
����ֵ
����
-1
ʾ��3
����
����
[1,1,1,1,1],1
����ֵ
����
0
*/

class Solution {
public:
	/**
	* �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
	*
	* ���Ŀ��ֵ���ڷ����±꣬���򷵻� -1
	* @param nums int����vector
	* @param target int����
	* @return int����
	*/

	int search(vector<int>& nums, int target)
	{
		int left = 0;
		int right = nums.size() - 1;
		int mid = 0;
		while (left <= right)
		{
			int mid = left + (right - left) / 2;
			if (nums[mid] < target)
			{
				left = mid + 1;
			}
			else if (nums[mid] > target)
			{
				right = mid - 1;
			}
			else
			{
				//�ҵ�֮���������
				while (mid != 0 && nums[mid] == nums[mid - 1])
					mid--;
				return mid;
			}
		}
		return -1;
	}
};