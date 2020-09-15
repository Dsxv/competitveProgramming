#include <bits/stdc++.h>
using namespace std ;

#define int long long

map<int,int> mp ;
const int mod = 1e9 + 7 ;
int solve(int n){
	int l = sqrt(n) ;
	if(mp.count(n)) return mp[n] ;
	int ans = 0 ;
	for(int i = 1 ; i <= l ; i++){
		if(n%i) continue ;
		if(i*i == n){
			ans += solve(i) ;
		} else {
			ans += solve(i) ;
			if(i-1) ans += solve(n/i) ;
		}
		ans %= mod ;
	}
	return mp[n] = ans ;
}

int32_t main(){
	int n ;
	cin >> n ;
	mp[1] = 1 ;
	cout << solve(n) ;
	return 0 ;
}

