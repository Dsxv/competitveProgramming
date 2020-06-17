#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ;
	cin >> n ;
	pair<int,int> p[n] ;
	for(int i = 0 ; i < n ; i++){
		cin >> p[i].first >> p[i].second ;
	}
	sort(p , p + n , [&](pair<int,int> a , pair<int,int> b){
			return a.second < b.second ;
			}) ;
	int cx = 0 ;
	int ans = 0 ;
	for(int i = 0 ; i < n ; i++){
		if(p[i].first >= cx){
			cx = p[i].second ;
			ans++ ;
		} else {
			continue ;
		}
	}
	cout << ans ;
	return 0 ;
}

