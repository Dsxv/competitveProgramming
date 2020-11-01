#include <bits/stdc++.h>
using namespace std ;

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int n  , m ;
	cin >> n >> m; 
	int a[m] = {} ;
	for(int i = 0 ; i < n ; i++){
		int x ;
		cin >> x ;
		a[x%m]++ ;
	}
	if(a[0]){
		cout << "YES" ;
		return 0;
	}
	vector<int> v ;
	bitset<2005> b(0) ;
	for(int i = 1 ; i < m ; i++){
		while(a[i]--){
			b |= b << i ;
			b[i] = 1 ;
			b |= b >> m ;
		}
	}
	if(b[m]) cout << "YES" ;
	else cout << "NO" ;
	return 0 ;
}

