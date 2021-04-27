/*
��������������������� �� ���뽫���� �ϲ������� �У����һ�����������
ע�⣺
���Լ��� �������㹻�Ŀռ��� �����Ԫ�أ� �� �г�ʼ��Ԫ����Ŀ�ֱ�Ϊ ��
������ҵ
*/

class Solution {
public:
	void merge(int A[], int m, int B[], int n)
	{
		int i = 0;
		while (i<n)
		{
			A[m++] = B[i++];
		}
		sort(A, A + m);
	}
};
///////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using namespace std;

int *strC(int *strA, int lenA, int *strB, int lenB)
{
	int *strC = new int[lenA + lenB];
	int i = 0, j = 0, k = 0;
	while (i< lenA && j < lenB)
	{
		if (strA[i] < strB[j])
			strC[k++] = strA[i++];
		else
			strC[k++] = strB[j++];
	}
	while (i < lenA)        //��������������ĸ�����Ƚϳ���û�и�ֵ��������ʣ�������ֵ��������
	{
		strC[k++] = strA[i++];
	}
	while (j < lenB)        //ͬ�ϣ�����������ִֻ��һ��
	{
		strC[k++] = strB[j++];
	}
	return strC;
}

int main()
{
	int a[] = { 1, 3, 5, 7, 9, 11 };
	int b[] = { 2, 4, 6, 8, 10, 12, 14, 16, 18 };
	int lenA = sizeof(a) / sizeof(int);
	int lenB = sizeof(b) / sizeof(int);
	int *strc = new int[lenA + lenB];
	strc = strC(a, lenA, b, lenB);
	for (int i = 0; i < (lenA + lenB); i++)
		cout << strc[i] << " ";
	return 0;
}