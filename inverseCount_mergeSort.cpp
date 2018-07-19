#include<iostream>
using namespace std;

int inv_count = 0;
void mergesort(int *a, int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;
		mergesort(a, left, mid);
		mergesort(a, mid + 1, right);
		int i = left, j = mid + 1, k = 0;
		int *out = new int[right - left + 1];
		while (i <= mid && j <= right) {
			if (a[i] < a[j]) {
				out[k++] = a[i++];
			}
			else {
				out[k++] = a[j++];
				inv_count = inv_count+ (mid - i+1);
			}
		}
		while (i <= mid) {
			out[k++] = a[i++];
		}
		while (j <= right) {
			out[k++] = a[j++];
		}
		int m = 0;
		for (int i = left; i <= right; i++)
			a[i] = out[m++];
	}
}



int main()
{

	int a[] = { 22,1,4,3,6,5,8,7,10,9 };
	inv_count = 0;
	mergesort(a, 0, 9);
	cout << inv_count << endl;
	return 0;
}
