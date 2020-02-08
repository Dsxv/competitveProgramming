#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n;
		map<int,int> x , y ;
		pair<int,int> p[n] ;
		for(int i = 0 ; i < n ; i++){
			int x1 , y1 ;
			cin >> x1 >> y1 ;
			p[i] = {x1,y1} ;
			x[x1]++ ;
			y[y1]++ ;
		}
		int ans = 0 ;
		for(int i = 0 ; i < n ; i++){
			ans += (n - x[p[i].first] - y[p[i].second] + 1) ;
		}
		cout << ans/2 << endl ;
	}
	return 0 ;
}

