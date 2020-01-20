#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int mod = 1e9 + 7 ;

int modexp(int a , int n){
	if(n == 0) return 1;
	if(n == 1) return a ;
	int x = modexp(a,n/2) ;
	x = (x*x) % mod ;
	if(n&1) x = (x*a) % mod ;
	return x;
}

int32_t main(){
 	int n , m ;
	cin >> n >> m ;
	int num = 1 ;
	for(int i = n + 2*m - 1 ; i >= n ; i--){
		num = (num*i) % mod ;
	}
	for(int j = 1 ; j <= 2*m ; j++){
		num = (num*modexp(j,mod-2))%mod ;
	}
	cout << num ;
	return 0 ;
}

