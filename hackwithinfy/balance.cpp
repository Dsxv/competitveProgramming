#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int mod = 1e9 + 7 ;
vector<int> G[1005] ;
int fib[1005] ;
int ans ;

int solve(int start){
	int l = 0 , r = 0 ;
	if(G[start].size() == 0){
		return 0 ;
	}
	l = solve(G[start][0]) + 1 ;
	if(G[start].size() == 2){
		r = solve(G[start][1]) + 1 ;
	}
	int x = abs(l-r) ;
	if(x > 1){
		if(r){
			ans = (ans + fib[x+1]-2) % mod ;
		} else {
			ans = (ans + fib[x]-1) % mod ;
		}
	}
	return max(l,r) ;
}

int32_t main(){
	fib[0] = 1 ;
	fib[1] = 1 ;
	for(int i = 2 ; i < 1005 ; i++) fib[i] = (fib[i-1] + fib[i-2]) % mod ;
	int n ;
	cin >> n ;
	n++ ;
	for(int i = 1 ; i < n ; i++){
		int p ;
		cin >> p ;
		G[p].push_back(i) ;
	}
	solve(0) ;
	cout << ans ;
	return 0 ;
}

