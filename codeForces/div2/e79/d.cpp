#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 1e6 + 10 ;
const int mod = 998244353 ;
int prob[N] ;
int cnt[N] ;

int modexp(int a , int n){
	if(n == 0) return 1 ;
	if(n == 1) return a ;
	int x = modexp(a,n/2) ;
	x = (x*x) % mod ;
	if(n&1) x = (x*a)%mod ;
	return x ;
}

int32_t main(){
	int n ;
	cin >> n ;
	for(int i = 0 ; i < n ; i++){
		int k ;
		cin >> k ;
		for(int j = 0 ; j < k ; j++){
			int x ;
			cin >> x ;
			cnt[x]++ ;
			prob[x] = ( prob[x] + modexp(k,mod-2) ) % mod ;
		}
	}
	int ans = 0 ;
	for(int i = 0 ; i < N ; i++){
		int temp = (cnt[i]*prob[i]) % mod ;
		ans =  (ans + (temp*modexp(n,mod-2)) % mod) % mod ;
	}
	ans = (ans*modexp(n,mod-2))%mod ;
	cout << ans ;
	return 0 ;
}

