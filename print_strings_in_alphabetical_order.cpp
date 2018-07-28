#pragma GCC optimize ("-Ofast")
#include <iostream>
using namespace std;

#define MAX 2000

struct node
{
	node *child[26];
	bool isWord;
};

node dict;
node pool[MAX];
int poolid;
char tstr[100];

void insert(char *str)
{
	char ch;
	node *temp = &dict;
	while (ch = *str++) {
		int charId = ch - 'a';
		if (!temp->child[charId]) {
			temp->child[charId] = &pool[poolid++];
			for (int i = 0; i < 26; i++)
				temp->child[charId]->child[i] = 0;
		}
		temp = temp->child[charId];
	}
	temp->isWord = true;
}

//print pre-order manner
void printAlphabetically(node *next, int id,int len)
{
	if (!next)
		return;
	tstr[len] = 'a' + id ;

	if (next->isWord) {
		tstr[len + 1] = 0;
		cout << tstr << endl;
	}
	for (int i = 0; i < 26; i++) {
		printAlphabetically(next->child[i], i,len + 1);
	}
}

/*
input:
5
abc
aaa
abb
bab
bba

*/
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		char s[100];
		cin >> s;
		insert(s);
	}
	cout << "printing" << endl;
	for (int i = 0; i < 26;i++)
		printAlphabetically(dict.child[i],i, 0);
	return 0;
}