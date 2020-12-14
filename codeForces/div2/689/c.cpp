#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n , m ; 
		cin >> n >> m ;
		int a[n] ;
		vector<double> p(n , 1) ;
		for(int i = 0 ; i < n ; i++) cin >> a[i] ;
		while(m--){
			int x ;
			double y ;
			cin >> x >> y ;
			p[x-1] *= (1 - y) ;
		}
		int id = n ;
		for(int i = n - 1 ; i >= 0 ; i--){
			if(a[i] == (i + 1)) continue ;
			id = i ;
			break ;
		}
		double ans = 1 ;
		for(int i = id ; i < n ; i++) ans *= p[i] ;
		if(id == n) ans = 0 ;
		cout << fixed << setprecision(10) << 1 - ans << '\n' ;
	}
	return 0 ;
}

