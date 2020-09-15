#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 1e5 + 10 , mod = 1e9 + 7 ;
vector<int> basis[N] ;

int modexp(int a , int n){
	if(n == 0) return 1 ;
	if(n == 1) return a ;
	int x = modexp(a , n / 2) ;
	x = (x*x) % mod ;
	if(n&1) x = (x*a) % mod ;
	return x ;
}

bool ok(int x , int id){
	for(int i = 0 ; i < 20 ; i++){
		if((x & 1 << i) == 0) continue ;
		if(basis[id][i] == 0) {
			return true ;
		}
		x ^= basis[id][i] ;
	}
	return false ;
}

void insert(int x , int id){
	for(int i = 0 ; i < 20 ; i++){
		if((x & 1 << i) == 0) continue ;
		if(basis[id][i] == 0) {
			basis[id][i] = x ;
			return ;
		}
		x ^= basis[id][i] ;
	}
}

int32_t main(){
	int n , q ;
	cin >> n >> q ;
	for(int i = 0 ; i < n ; i++){
		int x ;
		cin >> x ;
		if(i){
			basis[i] = basis[i-1] ;
		} else {
			basis[i] = vector<int>(20) ;
		}
		if(ok(x , i)){
			insert(x,i) ;
		}
	}
	while(q--){
		int l , x ;
		cin >> l >> x ;
		l-- ;
		if(!ok(x , l)){
			int cnt = 0 ;
			for(auto i : basis[l]) if(i) cnt++ ;
			cout << modexp(2 , l+1 - cnt) % mod << '\n' ;
		} else {
			cout << 0 << '\n' ;
		}
	}
	return 0 ;
}

