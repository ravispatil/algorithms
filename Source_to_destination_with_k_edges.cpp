#include <iostream>
using namespace std;

#define MAX 100

int visited[MAX];
struct node
{
	node *next;
	int id;
};
node pool[MAX];
int poolid = 0;

node lst[MAX];
int src_id, dest_id, k;
int ans;
void calcpaths(int id, int count)
{
	if (count > k)
		return;

	if (id == dest_id && count == k) {
		ans++;
		return;
	}
	node *next = lst[id].next;
	while (next) {
		visited[next->id] = 1;
		calcpaths(next->id,count+1);
		visited[next->id] = 0;
		next = next->next;
	}

}


int main()
{
	/* Let us create the graph shown in above diagram*/
	int graph[4][4] = { { 0, 1, 1, 1 },
						{ 0, 0, 0, 1 },
						{ 0, 0, 0, 1 },
						{ 0, 0, 0, 0 }
						};
	src_id = 1, dest_id = 4, k = 2;
	poolid = 0;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (graph[i][j] == 1) {
				int s = i + 1, t = j + 1;
				node *temp = &pool[poolid++];
				temp->id = t;
				temp->next = 0;
				if (!lst[s].next) {
					lst[s].next = temp;
				}
				else {
					temp->next = lst[s].next;
					lst[s].next = temp;
				}
			}
		}
	}
	
	calcpaths(1, 0);
	cout << ans << endl;
		return 0;
}
