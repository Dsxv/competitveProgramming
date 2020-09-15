#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int mod = 1e9 + 7 ;

int modexp(int a , int n){
	if(n == 0) return 1 ;
	if(n == 1) return a ;
	int x = modexp(a , n / 2) ;
	x = (x*x) % mod ;
	if(n&1) x = (x*a) % mod ;
	return x ;
}

int basis[30] ;
int sz = 0 ;
void insert(int x){
	for(int i = 0 ; i < 30 ; i++){
		if((x & 1 << i) == 0) continue ;
		if(basis[i] == 0){
			basis[i] = x ;
			sz++ ;
			return ;
		}
		x ^= basis[i] ;
	}
	return ;
}

bool ok(int x){
	for(int i = 0 ; i < 30 ; i++){
		if((x & 1 << i) == 0) continue ;
		if(basis[i] == 0){
			return false ;
		}
		x ^= basis[i] ;
	}
	return true ;
}

int32_t main(){
	int n; 
	cin >> n ;
	for(int i = 0 ; i < n ; i++) {
		int x ; 
		cin >> x ;
		insert(x) ;
	}
	int q ;
	cin >> q ;
	while(q--){
		int t ;
		cin >> t ;
		if(t == 1){
			int x ; cin >> x ;
			insert(x) ;
			n++ ;
		} else {
			int k ; cin >> k ;
			if(ok(k)){
				cout << modexp(2 , n - sz) - (k == 0) << '\n' ;
			} else {
				cout << 0 << '\n' ;
			}
		}
	}
	return 0 ;
}

