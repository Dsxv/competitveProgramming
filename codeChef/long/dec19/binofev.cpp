#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int mod = 998244353 ;

int modexp(int a , int n ){
	if(n == 0) return 1 ;
	if(n == 1) return a ;
	int x = modexp(a,n/2) ;
	x = (x*x)%mod ;
	if(n&1) x = (a*x)%mod ;
	return x ;
}

int solve(int r , int n){
	int k = (modexp(r,n)-1)%mod ;	
	return (k*modexp(r-1,mod-2))%mod ;
}

int32_t main(){
	int t;
	cin >> t ;
	while(t--){
		int n , p , r ;
		cin >> n >> p >> r ;
		//p = mod - 1 ;
		//cout << ( (p*p) - 1 + mod) % mod ;
		if(r == 2){
			int temp = (solve((p*p)%mod,n) - solve(p,n) + mod)%mod ;
			//cout << temp << endl ;
			temp = (temp*modexp(2,mod-2))%mod ;
			cout << temp << '\n' ;
		} else {
			cout << -1 << '\n' ;
		}
	}
	return 0 ;
}

