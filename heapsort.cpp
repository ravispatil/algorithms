#pragma GCC optimize ("-Ofast")
#include <iostream>
using namespace std;

void heapify(int *a, int i, int N)
{
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	int largest = i;
	if (left < N && a[left] > a[i])
		largest = left;
	if (right < N && a[largest] < a[right])
		largest = right;
	if (i != largest) {
		int tmp = a[i];
		a[i] = a[largest];
		a[largest] = tmp;
		heapify(a, largest, N);
	}
}


/*
input:
5
2 1 4 3 5

10
2 8 9 1 4 3 10 5 7 6


*/
int main()
{
	int N;
	cin >> N;
	int a[200];
	for (int i = 0; i < N;i++) {
		cin >> a[i];
	}

	for (int i = ((N / 2) -1); i>= 0;i--) {
		heapify(a, i, N);
	}
	int tmp = a[0];
	a[0] = a[N - 1];
	a[N - 1] = tmp;
	
	int tmpN = N - 1;
	while(tmpN > 0){
		heapify(a, 0, tmpN);
		int tmp = a[0];
		a[0] = a[tmpN - 1];
		a[tmpN - 1] = tmp;
		tmpN--;
	}
	return 0;
}
