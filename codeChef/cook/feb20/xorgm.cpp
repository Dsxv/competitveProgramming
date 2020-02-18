#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t;
	while(t--){
		int n ;
		cin >> n ;
		int a[n] ;
		int xr = 0 ;
		for(int i = 0 ; i < n ; i++){
			cin >> a[i] ;
			xr ^= a[i] ;
		}
		map<int,int> mp;
		bool found = true ;
		for(int i = 0 ; i < n ; i++){
			int x ; cin >> x ;
			mp[x]++ ;
			xr ^= x ;
		}
		int b[n] ;
		for(int i = 0 ; i < n ; i++){
			if(mp.count(xr^a[i])){
				mp[xr^a[i]]-- ;
				if(mp[xr^a[i]] == 0){
					mp.erase(xr^a[i]) ;
				}
				b[i] = xr^a[i] ;
			} else {
				found = false ;
				break ;
			}
		}
		if(!found){
			cout << -1 << '\n' ;
		} else {
			for(int i = 0 ; i < n ; i++) cout << b[i] << " " ;
			cout << '\n' ;
		}
	}
	return 0 ;
}

