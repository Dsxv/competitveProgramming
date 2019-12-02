#include <bits/stdc++.h>
using namespace std ;

#define int long long

unordered_map<int,int> mp ;

int solve(int n){
	if(n == 0) return 0 ;
	if(n == 1) return 1 ;
	if(mp.count(n)) return mp[n] ;
	int a = max(n/2,solve(n/2)) ;
	int b = max(n/3,solve(n/3)) ;
	int c = max(n/4,solve(n/4)) ;
	return mp[n] = a + b + c ;
}

int32_t main(){
	int n; 
	cin >> n; 
	cout << solve(n) ;
	return 0 ;
}

