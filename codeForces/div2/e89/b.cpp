#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n , m , x ;
		cin >> n >> x >> m ;
		int l = x , r = x ;
		while(m--){
			int a , b ; cin >> a >> b ;
			if(l >= a && l <= b) l = min(l , a) ;
			if(r >= a && r <= b) r = max(r , b) ;
		}
		cout << (r - l + 1) << '\n' ;
	}
	return 0 ;
}

