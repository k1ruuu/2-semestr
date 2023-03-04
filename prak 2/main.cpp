#include <iostream>
using namespace std;

void *memcpy(void* dst, const void* src, size_t n) {
	int i, m;
	unsigned long* wdst = (unsigned long*)dst;  // ������� ������� � ������ ����������
	unsigned long* wsrc = (unsigned long*)src;  // ������� ������� � ���������
	unsigned char* cdst, * csrc;

	for (i = 0, m = n / sizeof(long); i < m; i++)  // �������� ���
		*(wdst++) = *(wsrc++);                     // (� ����������� �� ���������)������ ����� ������� �� 4 ��� 8 ���

	cdst = (unsigned char*)wdst;
	csrc = (unsigned char*)wsrc;

	for (i = 0, m = n % sizeof(long); i < m; i++)             // ������� �������� ��������
		*(cdst++) = *(csrc++);
	return dst;
}

int  main()
{
	const int size = 10;
	int arr1[size] = { 53, 35, 23, 345, 123, 654, 234, 543, 123, 10 };
	int arr2[size] = { 0 };
	memcpy(arr2, arr1, sizeof(arr2));
	for (int i = 0; i < size; i++) {
		cout << arr2[i] << " ";
	}
}
