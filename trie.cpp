#include <iostream>
using namespace std;

#define MAX 2000

struct node
{
	node *ch[26];
	bool isWord;
};
node pool[MAX];
int poolid;
node head;

void insert(char *str)
{
	char ch;
	node *temp = &head;
	while (ch=*str++)
	{
		int charId = ch - 'a';
		if (!temp->ch[charId]) {
			temp->ch[charId] = &pool[poolid++];
			for (int i = 0; i < 26; i++) 
				temp->ch[charId]->ch[i] = 0;
			temp->ch[charId]->isWord = false;
		}
		temp = temp->ch[charId];
	}
	temp->isWord = true;
}

bool search(char *str)
{
	node *temp = &head;
	char ch;
	while ((ch = *str++) && temp) {
		int charId = ch - 'a';
		temp = temp->ch[charId];
	}
	if (ch =='\0' && temp && temp->isWord)
		return true;
}

int main()
{
	insert("aab");
	insert("aaab");
	insert("aabb");
	insert("aabc");
	insert("aabdd");
	cout << search("aab") << endl;
	cout << search("ab") << endl;
	return 0;
}