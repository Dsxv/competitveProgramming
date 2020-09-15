#include <bits/stdc++.h>
using namespace std ;

#define int long long

vector<int> basis ;
int sz = 0 ;
void insert(int x){
	for(int i = 0 ; i < 30 ; i++){
		if((x & 1 << i) == 0) continue ;
		if(!basis[i]){
			basis[i] = x ;
			sz++ ;
			return ;
		}
		x ^= basis[i] ;
	}
}
int32_t main(){
	int t;
	cin >> t ;
	while(t--){
		basis.clear() ;
		basis.resize(30) ;
		sz = 0 ;
		int k , m ;
		cin >> k >> m  ;
		for(int i = 0 ; i < m ; i++){
			int x ;
			cin >> x ;
			insert(x) ;
		}
		cout << (1 << k) / (1 << sz) << '\n' ;
	}
	return 0 ;
}

