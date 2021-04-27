/*
给出两个有序的整数数组 和 ，请将数组 合并到数组 中，变成一个有序的数组
注意：
可以假设 数组有足够的空间存放 数组的元素， 和 中初始的元素数目分别为 和
关联企业
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
	while (i < lenA)        //这里是由于如果哪个数组比较长，没有赋值结束，把剩余的数赋值给新数组
	{
		strC[k++] = strA[i++];
	}
	while (j < lenB)        //同上，不过这两个只执行一个
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