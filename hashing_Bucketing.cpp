#include<iostream>
using namespace std;

#define MAX 1000
struct node {
	char str[10];
	struct node *next;
};

struct hashNode
{
	struct node *head;
	struct node *cur;
	int hashval;
};

hashNode ht[MAX] = { 0, };

int getHash(char *str)
{
	unsigned long long hash = 5381;
	char ch;
	while (ch = *str++) {
		hash = (hash << 5) + hash + ch;
	}
	return hash%MAX;
}

void mystrcpy(char *d, char *s)
{
	while (*d++ = *s++);
}
void addToHashTable(char *str)
{
	int hval = getHash(str);

	node *temp = new node;
	mystrcpy(temp->str, str);
	temp->next = nullptr;

	if (!ht[hval].head) {
		ht[hval].head = temp;
		ht[hval].cur = temp;
	}
	else {
		ht[hval].cur->next = temp;
		ht[hval].cur = temp;
	}
}

int main()
{
	addToHashTable("ravi");
	addToHashTable("ravi");
	return 0;
}
