#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <iostream>

using namespace std;

#define SZ(x) ((int)(x).size())
#define MP make_pair
#define PB push_back
#define ALL(x) (x).begin(), (x).end()
#define ZERO(a) memset(a, 0, sizeof(a))
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define FORE(i,a,b) for(int i = (a); i <= (b); ++i)
#define RFOR(i,b,a) for(int i = (b); i >= (a); --i)

typedef long long LL;

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;

stack<char> st;

int main()
{
	//freopen("in.txt", "r", stdin);
	//reopen("out.txt", "w", stdout);

	string s;
	cin >> s;
	int n = SZ(s);
	FOR(i, 0, n)
	{
		if (!st.empty() && s[i] == st.top()) st.pop();
		else st.push(s[i]);
	}
	string ret;
	while (!st.empty())
	{
		ret += st.top();
		st.pop();
	}
	reverse(ALL(ret));
	cout << ret << endl;

    return 0;
}   
