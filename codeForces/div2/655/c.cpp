#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		int a[n+1] = {} ;
		for(int i = 1 ; i <= n ; i++){
			int x ; cin >> x ;
			a[x] = i != x ;
		}
		vector<pair<int,int>> v ;
		v.push_back({a[1] , 1}) ;
		for(int i = 2 ; i <= n ; i++){
			if(a[i] == v.back().first){
				v.back().second++ ;
			} else {
				v.push_back({a[i] , 1}) ;
			}
		}
		int cnt = 0 ;
		for(auto i : v) cnt += i.first ;
		cout << min(2LL , cnt) << '\n' ;
	}
	return 0 ;
}

