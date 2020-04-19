#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ;
	cin >> n ;
	vector<pair<int,int>> v[2] ;
	int a[n] ;
	int sum = 0 ;
	bool ok = false ;
	for(int i = 0 ; i < n ; i++){
		int x , y ; 
		cin >> x >> y ;
		a[i] = x ;
		v[y-1].push_back({sum,i}) ;
		if(y == 2) ok = true ;
		sum += x ;
	}
	if(!ok){
		cout << "Infinity" ;
		return 0 ;
	}
	int mn1 = INT_MAX , mx2 = INT_MIN;
	if(v[0].size())
	for(auto i : v[0]) {
		mn1 = min(mn1 , i.first) ;
	}
	for(auto i : v[1]){
		mx2 = max(mx2 , i.first) ;
	}
	if(mx2 >= mn1){
		cout << "Impossible" ;
		return 0 ;
	}
	int id = -1 ;
	for(int i = 0 ; i < v[1].size() ; i++) {
		if(mx2 == v[1][i].first) id = v[1][i].second ;
	}
	cout << 1899 + accumulate(a+id,a+n,0LL) ; 
	return 0 ;
}

