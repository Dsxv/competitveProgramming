#include <bits/stdc++.h>
using namespace std ;
const long long N = 1e7 + 10 ;
int c[N] ;
bool sv[N] ;
int ans[N] ;
int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int n ;
	cin >> n ;
	for(int i = 0 ; i < n ; i++){
		int x ;
		cin >> x ;
		c[x]++ ;
	}
	for(int i = 2 ; i < N ; i++) sv[i] = 1 ;
	for(int i = 2 ; i < N ; i++){
		if(sv[i])
			for(long long j = (long long)i*i ; j < N ; j += i){
				sv[j] = false ;
			}
	}
	for(int i = 2 ; i < N ; i++){
		if(sv[i]){
			for(int j = i ; j < N ; j += i){
				ans[i] += c[j] ;
			}
		}
		ans[i] += ans[i-1] ;
	}
	int q ;
	cin >> q ;
	int t = N ;
	while(q--){
		int l , m ;
		cin >> l >> m ;
		l = min(l,t-1) ;
		m = min(m,t-1) ;
		cout << ans[m] - ans[l-1] << '\n' ;
	}
	return 0 ;
}

