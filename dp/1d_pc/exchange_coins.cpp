#include <bits/stdc++.h>
using namespace std ;

#define int long long

map<int,int> mp ;

int solve(int n){
	if(n == 1) return 1 ;
	if(n <= 0) return 0 ;
	if(mp.count(n)) return mp[n] ;
	mp[n] = max(n/2,solve(n/2)) + max(n/3,solve(n/3)) 
			+ max(n/4, solve(n/4)) ;
	mp[n] = max(n,mp[n]) ;
	return mp[n] ;
}


int32_t main(){
	int n ;
	cin >> n ;
	cout <<	solve(n) ;
	return 0 ;
}

