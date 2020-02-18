#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int mod = 1e9 + 7 ;

int modexp(int a , int n){
	if(n == 0) return 1 ;
	if(n == 1) return a ;
	int x = modexp(a,n/2) ;
	x = (x*x) % mod ;
	if(n&1) x = (x*a) % mod ;
	return x ;
}

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		string s;
		cin >> s ;
		s = "*" + s ;
		int a[n+1] = {} ;
		for(int i = 1 ; i <= n ; i++){
			a[i] = a[i-1] ;
			if(s[i] == '(') a[i]++ ;
			if(s[i] == ')') a[i]-- ;
		}
		for(int i = 1 ; i <= n ; i++){
			a[i] += (n+2) ;
		}
		int dp[2*n + 100] = {};
		int count = 0 ;
		int prev = 0 ;
		for(int i = n ; i >= 1 ; i--){
			dp[a[i]] = dp[a[i]-2] ;
			if(s[i] == '*'){
				count = (count + prev) % mod ;
				continue ;
			}
			if(s[i] == ')') dp[a[i]] = (dp[a[i]] + n-i+1) % mod ;
			prev = dp[a[i]] ;
			count =  (count + dp[a[i]]) % mod ;
		}
		int vv = n*(n+1)/2 ;
		vv %= mod ;
		cout << (count*modexp(vv,mod-2)) % mod << '\n' ;
	}
	return 0 ;
}

