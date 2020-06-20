#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n; 
	cin >> n;
	pair<int,int> p[n] ;
	for(int i = 0 ; i < n ; i++){
		cin >> p[i].first >> p[i].second ;
	}
	sort(p,p+n , [&](pair<int,int> a , pair<int,int> b){
			if(a.first != b.first) return a.first < b.first ;
			else return a.second < b.second ;
			}) ;
	int t = 0 , ans = 0 ;
	for(int i = 0 ; i < n ; i++){
		t += p[i].first ;
		ans += (p[i].second - t) ;
	}
	cout << ans ;
	return 0 ;
}

