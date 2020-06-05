#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int mod = 998244353;

int modexp(int a , int n){
	if(n == 0) return 1 ;
	if(n == 1) return a ;
	int x = modexp(a , n / 2 ) ;
	x = (x*x) % mod ;
	if(n&1) x = (x*a) % mod ;
	return x ;
}

int solve(int len , int n){
	int ans = (2*10*9*modexp(10,n-len-1)) % mod ;
	ans += ((n-len-1)*9*9*10*modexp(10,n-len-2)) % mod ;
	return ans%mod ;
}

int32_t main(){
	int n ;
	cin >> n ;
	int ans = 0 ;
	for(int i = 1 ; i < n ; i++){
		cout << solve(i,n) << " ";
	}
	cout << 10 ;
	return 0 ;
}

