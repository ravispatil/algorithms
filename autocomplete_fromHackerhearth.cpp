#pragma GCC optimize ("-Ofast")

#include <iostream>
using namespace std;

struct node
{
	node* child[26];
	bool isword;
	int weight;
};

node pool[2000];
int poolid;
node dict;

void insert(char *s,int w)
{
	int chId = 0;
	char ch;
	node *temp = &dict;
	while (ch = *s++) {
		chId = ch - 'a';
		if (!temp->child[chId])
			temp->child[chId] = &pool[poolid++];
		temp = temp->child[chId];
	}
	temp->isword = true;
	temp->weight = w;
}

void printAllWords(node *temp, char *tstr, int id, int len)
{
	if (temp->isword) {
		tstr[len] = 0;
		cout << tstr << endl;
	}
	for (int i = 0; i < 26; i++) {
		if (temp->child[i]) {
			tstr[len] = 'a' + i;
			printAllWords(temp->child[i], tstr, i, len + 1);
		}
	}
}

void printAllSuggestion(char *s)
{
	node *temp = &dict;
	char ch;
	int slen = 0;
	char tstr[100];
	while ((ch = *s++) && temp) {
		int chId = ch - 'a';
		temp = temp->child[chId];
		tstr[slen++]=ch;
	}
	if (ch == '\0' && temp) {
		printAllWords(temp,tstr,0, slen);
	}
	else {
		cout << "-1" << endl;
	}
}

char maxWtStr[100];
int maxWt = 0;
void mystrcpy(char *d, char *s)
{
	while (*d++ = *s++);
}
void printMaxWeightWord(node *temp, char *str, int slen)
{
	if (temp->isword) {
		if (temp->weight > maxWt) {
			maxWt = temp->weight;
			str[slen] = 0;
			mystrcpy(maxWtStr, str);
		}
	}
	for (int i = 0; i < 26; i++) {
		if (temp->child[i]) {
			str[slen] = 'a' + i;
			printMaxWeightWord(temp->child[i], str, slen + 1);
		}
	}
}
void printMaxWeightSuggestion(char *s)
{
	char ch;
	node *temp = &dict;
	char str[100];
	int slen = 0;
	while ((ch = *s++) && temp) {
		char chId = ch - 'a';
		temp = temp->child[chId];
		str[slen++] = ch;
	}
	if (ch == '\0' && temp) {
		printMaxWeightWord(temp,str,slen);
	}
	cout << maxWtStr << endl;
}

/*
4
ravis 3
ravisp 5
ravipatil 2
ravispatil 6
ravi

4
ravis 3
ravisp 5
ravipatil 2
ravispatil 6
ravis

6
ravis 7
ravisp 5
ravipatil 3
ravispatil 6
ravisp 4
ravispa 4
ravi
*/

int main()
{
	int N;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		char tmp[100];
		int w;
		cin >> tmp >> w;
		insert(tmp,w);
	}

	char input[100];
	cin >> input;
	cout << "=======Print all suggestion========" << endl;
	printAllSuggestion(input);
	cout << "=======Print max weight suggestion========" << endl;
	printMaxWeightSuggestion(input);
	return 0;
}