#include <bits/stdc++.h>
using namespace std ;

const int N = 1e6 + 5 ;
vector<int> g[N] ;
pair<int,int> p(-1,-1) ;
int tsum ;
int a[N] ;

int dfs(int start , int parent = -1){
	int sum = a[start] ;
	for(auto i : g[start]){
		if(i == parent) continue ;
		sum += dfs(i,start) ;
	}
	if(sum == tsum){
		if(p.first == -1){
			p.first = start ;
			return 0 ;
		} else if(p.second == -1){
			p.second = start ;
			return 0 ;
		}
	}
	return sum ;
}

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int n ;
	cin >> n ;
	int start = 0 ;
	for(int i = 0 ; i < n ; i++){
		int f , s ;
		f = i ;
		cin >> s >> a[i] ;
		s-- ;
		if(~s){
			g[f].push_back(s) ;
			g[s].push_back(f) ;
		} else {
			start = i ;
		}
	}
	tsum = accumulate(a,a+n,0LL) ;
	if(tsum%3) {
		cout << -1 ;
		return 0 ;
	}
	tsum /= 3 ;
	dfs(start) ;
	if(~p.first && ~p.second && p.first != start && p.second != start){
		cout << p.first + 1 << " " << p.second + 1;
	} else {
		cout << -1 ;
	}
	return 0 ;
}

