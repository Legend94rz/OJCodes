#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
char ln[255];
int f[200][200];
string state[200][200];

string get_match(char c)
{
	if (c == '(' || c==')')
		return "()";
	else
		return "[]";
}

int main()
{
	cin.getline(ln, 200);
	string s(ln);
	
	memset(f, 0x3f, sizeof(f));
	for (int i = 0;i < s.length();i++)
	{
		f[i][0] = 0;state[i][0] = "";
		f[i][1] = 1;state[i][1] = get_match(s[i]);
	}
	for (int k = 2; k <= s.length();k++)
	{
		for (int i = 0; i <= s.length()-k; i++)
		{
			int J = i + k - 1;
			if (s[i] == '(' && s[J] == ')' || s[i] == '[' && s[J] == ']')
			{
				if (f[i + 1][k - 2] < f[i][k])
				{
					f[i][k] = f[i + 1][k - 2];
					state[i][k] = s[i] + state[i + 1][k - 2] + s[J];
				}
			}
			for (int j = 1; j < k; j++)
			{
				if (f[i][j] + f[i + j][k - j] < f[i][k])
				{
					f[i][k] = f[i][j] + f[i + j][k - j];
					state[i][k] = state[i][j] + state[i + j][k - j];
				}
			}
		}
	}
	//cout << f[0][s.length()] << endl;
	cout << state[0][s.length()] << endl;
}
