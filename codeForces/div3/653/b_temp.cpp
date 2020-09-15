#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ll long long
#define hii cout << "hii" << endl
#define int ll
#define endl '\n'
#define all(s) s.begin(), s.end()
 
template <class T> ostream& operator << (ostream &os, const vector<T> &v) { for (T i : v) os << i << ' '; return os; }
template <class T> ostream& operator << (ostream &os, const set<T> &v) { for (T i : v) os << i << ' '; return os; }
template <class T, class S> ostream& operator << (ostream &os, const pair<T, S> &v) { os << v.first << ' ' << v.second; return os; }
template <class T, class S> ostream& operator << (ostream &os, const unordered_map<T, S> &v) { for (auto i : v) os << '(' << i.first << "=>" << i.second << ')' << ' '; return os; }
 
 
#ifndef ONLINE_JUDGE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <class Arg1> void __f(const char* name, Arg1&& arg1) { cerr << name << " : " << arg1 << endl; }
    template <class Arg1, class... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args) {
        const char* sep = strchr(names + 1, ',');
        cerr.write(names, sep - names) << " : " << arg1 << "  ";
        __f(sep + 1, args...);
    }
#else
#define trace(...) 0
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define _CRT_SECURE_NO_WARNINGS
#endif // ifndef ONLINE_JUDGE

const int N = 1e5 + 5;
const int MAX = 250000 + 5;
const int M = 3e5;
const int mod = 998244353;
const int MOD = 998244353;
const int INF = 1e18;
const int LG = 21;


// Try not to use map 

int arr[N];
int n;

void solve()
{
	int n;
	cin >> n;
	map<int, int> mp;
	int t = n;
	while(n % 2 == 0)
	{
		mp[2]++;
		n /= 2;
	}
	n = t;
	while(n % 3 == 0)
	{
		mp[3]++;
		n /= 3;
	}
	if((n & (n - 1)) != 0 or mp[2] > mp[3])
	{
		cout << -1 << endl;
		return;
	}
	
	mp[3] -= mp[2];
	int ret = mp[2] + 2 * mp[3];
	cout << ret << endl;
}
 
int32_t main() 
{	
     ios_base:: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	    int t = 1;
	    cin >> t;
	while(t--)solve();
	return 0;
}

