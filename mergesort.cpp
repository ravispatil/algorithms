#include <iostream>
using namespace std;

void mergesort(int *a, int left, int right)
{
	if (left < right)
	{
		//int mid = (right + left) / 2;
		
		int mid = left + (right - left) / 2;
		
		mergesort(a, left, mid);
		mergesort(a, mid+1, right);

		int *out = new int[right - left + 1];
		int i = left, j = mid+1;
		int k = 0;
		while (i <= mid && j <= right) {
			if (a[i] < a[j]) {
				out[k++] = a[i++];
			}
			else {
				out[k++] = a[j++];
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
		delete[] out;
	}

}


int main()
{
	int a[] = { 2,1,4,3,5,4,7,6,9,8 };
	mergesort(a, 0, 9);
	return 0;
}   