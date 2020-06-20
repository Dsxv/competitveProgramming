#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n , x ;
	cin >> n >> x ;
	pair<int,int> a[n] ;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i].first ;
		a[i].second = i ;
	}
	sort(a,a+n) ;
	for(int i = 0 ; i < n ; i++){
		int t = x - a[i].first ;
		if(t <= 0) continue ;
		int f = 0 , s = n - 1 ;
		while(f < s){
			if(f == i){
				f++ ;
				continue ;
			}
			if(s == i){
				s-- ;
				continue ;
			}
			if(a[f].first + a[s].first == t){
				cout << a[i].second + 1 << " " << a[f].second + 1 << " " << a[s].second + 1  ;
				return 0 ;
			}
			if(a[f].first + a[s].first < t){
				f++ ;
				continue ;
			} else {
				s-- ;
				continue ;
			}
		}
	}
	cout << "IMPOSSIBLE" ;
	return 0 ;
}

