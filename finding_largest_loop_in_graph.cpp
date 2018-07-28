#pragma GCC optimize ("-Ofast")
#include <iostream>
using namespace std;


#define MAX 2000
struct node
{
	int id;
	node *next;
};
node pool[MAX];
int poolid;
int visited[MAX];
node v[MAX];

int ans;

void findloop(int src, int id, int count)
{
	if (src == id && count > ans) {
		ans = count;
		return;
	}
	node *next = v[id].next;
	while (next) {
		if (!visited[next->id]) {
			visited[next->id] = 1;
			findloop(src, next->id, count + 1);
			visited[next->id] = 0;
		}
		next = next->next;
	}
}

/*
input:
5 5
1 2
2 3
3 4
4 1
5 3

*/

int main()
{
	int N,M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		v[i].next = 0;

	for (int i = 1; i <= M; i++) {
		int s, t;
		cin >> s >> t;
		node *temp = &pool[poolid++];
		temp->next =  0;
		temp->id = t;
		if (!v[s].next) {
			v[s].next = temp;
		}
		else {
			temp->next = v[s].next;
			v[s].next = temp;
		}
	}
	ans = 0;
	for (int i = 1; i <= N; i++)
		findloop(i, i, 0);
	cout << ans << endl;
}

