#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ll long long
#define hii cout << "hii" << endl
#define int long long
#define endl '\n'
#define all(s) s.begin(), s.end()
template <class T> ostream& operator << (ostream &os, const vector<T> &v) { for (T i : v) os << i << ' '; return os; }
template <class T> ostream& operator << (ostream &os, const set<T> &v) { for (T i : v) os << i << ' '; return os; }
template <class T, class S> ostream& operator << (ostream &os, const pair<T, S> &v) { os << v.first << ' ' << v.second; return os; }
template <class T, class S> ostream& operator << (ostream &os, const unordered_map<T, S> &v) { for (auto i : v) os << '(' << i.first << "=>" << i.second << ')' << ' '; return os; }

 
#ifndef ONLINE_JUDGE
#define trace(...) _f(#__VA_ARGS_, _VA_ARGS_)
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
const int N = 5e5 + 5;
const int MAX = 250000 + 5;
const int M = 5e6 + 5;
const int mod = 998244353;
const int MOD = 998244353;
const int INF = 1e15;
const int LG = 21;

int arr[N];
int n, m;
vector<int> v[N];
int sz = 0;
int sub[N];
bool ok = 1;
int h[N];
void clean()
{
	ok = 1;
	for(int i = 0; i <= n; i++)
	{
		sub[i] = 0;
		v[i].clear();
	}
}
int dfs(int sv, int par)
{
	sub[sv] += arr[sv];
	for(int x : v[sv])
	{
		if(x != par) 
		{
			sub[sv] += dfs(x, sv);
		}
	}
	return sub[sv];
}
void dfs(int sv, int par, int good, int bad)
{
	if(good - bad != h[sv])
	{
		ok = 0;
		return;
	}
	if(bad < arr[sv]) 
	{
		good -= (arr[sv] - bad);
		bad = 0;
	}
	else
	{
		bad -= arr[sv];
	}
	if(good < 0)
	{
		ok = 0;
		return;
	}
	for(int x : v[sv])
	{
		if(x != par)
		{
			if(abs(h[x]) > sub[x])
			{
				ok = 0;
				return;
			}
			int reqdgood = (sub[x] + h[x])/ 2;
			int reqdbad = sub[x] - (sub[x] + h[x]) / 2;
			trace(good, bad);
			if(reqdbad > bad)
			{
				good -= (reqdbad - bad);
				bad = 0;
			}
			else
			{
				bad -= reqdbad;
			}
			if(good < 0)
			{
				ok = 0;
				return;
			}
			if(reqdgood > good)
			{
				ok = 0;
				return;
			}
			else
			{
				good -= reqdgood;
			}
			dfs(x, sv, reqdgood, reqdbad);
		}
	}
}
void solve()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> arr[i + 1];
	for(int i = 0; i < n; i++) cin >> h[i + 1];
	for(int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1, 0);
	if(abs(h[1]) > m or (sub[1] + h[1]) % 2 != 0)
	{
		cout << "NO" << endl;
		clean();
		return;
	}
	dfs(1, 0, (sub[1] + h[1]) / 2, sub[1] - (sub[1] + h[1]) / 2);
	if(ok)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
	clean();
}
int32_t main() 
{	
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	    int t = 1;
	    cin >> t;
	while(t--)solve();
	return 0;
}

