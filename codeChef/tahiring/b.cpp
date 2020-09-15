#include <bits/stdc++.h>
using namespace std ;

#define int long long

int basis[20] ;

void insert(int mask){
	for(int i = 20 ; i >= 0 ; i--){
		if((mask & 1 << i) == 0) continue ;
		if(!basis[i]) {
			basis[i] = mask ;
			return ;
		}
		mask ^= basis[i] ;
	}
}

int32_t main(){
	int n ;
	cin >> n ;
	for(int i = 0 ; i < n ; i++){
		int x ; cin >> x ;
		insert(x) ;
	}
	int ans = 0 ;
	for(int i = 20 ; i >= 0 ; i--){
		if(!basis[i]) continue ;
		if(ans & 1 << i) continue ;
		ans ^= basis[i] ;
	}
	cout << ans ;
	return 0 ;
}

