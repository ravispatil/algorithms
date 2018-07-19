#include <iostream>
using namespace std;

unsigned long long hashOfStr(char *str)
{
	unsigned long long hash = 5381;
	char ch = 0;
	while (ch = *str++) {
		hash = (hash << 5) + (hash + ch);
	}
	return hash;
}


int main()
{
	char *s = "ravi";
	cout << hashOfStr(s) << endl;
	return 0;
}

