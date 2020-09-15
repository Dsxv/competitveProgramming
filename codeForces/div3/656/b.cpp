#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t; 
	while(t--){
		int n ;
		cin >> n; 
		pair<int,int> p[n+1] = {};
		for(int i = 1 ; i <= n ; i++) p[i].second = i ;
		for(int i = 1 ; i <= 2*n ; i++){
			int x ; cin >> x ;
			if(p[x].first) continue ;
			p[x].first = i ;
		}
		sort(p,p+n+1) ;
		for(int i = 1 ; i <= n ; i++) cout << p[i].second << " " ;
		cout << '\n' ;
	}
	return 0 ;
}

