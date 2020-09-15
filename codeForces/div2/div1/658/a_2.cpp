#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n , m ;
		cin >> n >> m;
		int a[1001] = {} ;
		for(int i = 0 ; i < n ; i++){
			int x ; cin >> x ;
			a[x]++ ;
		}
		bool ok = false ;
		for(int i = 0 ; i < m ; i++){
			int x ; cin >> x ;
			if(a[x] && !ok){
				ok = true ;
				cout << "YES\n1 " << x << '\n' ; 
			}
		}
		if(!ok) cout << "NO\n" ;
	}
	return 0 ;
}
