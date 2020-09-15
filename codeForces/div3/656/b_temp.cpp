#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n; 
		cin >> n ;
		int vis[n] = {} ;
		for(int i = 0 ; i < 2*n ; i++){
			int x ; cin >> x ; x-- ;
			if(!vis[x]){
				vis[x] = 1 ;
				cout << x+1 << " " ;
			}
		}
		cout << endl ;
	}
	return 0 ;
}

