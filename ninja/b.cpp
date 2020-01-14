#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int k , m , n ;
	cin >> k >> m >> n ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i] ;
	}
	vector<vector<int>> ans ;
	vector<int> v(a,a+n) ;
	ans.push_back(v) ;
	for(int i = 0 ; i < 2000 ; i++){
		vector<int> prev = ans.back() ;
		cout << i+1 << " : " ;
		for(auto j : prev) cout << j << " " ;
		cout << endl ;
		set<int> s ;
		for(auto ia :v){
			for(auto j : prev){
			   s.insert((ia*j)%m) ;	
		}
		vector<int> x(s.begin(),s.end()) ;
		if(ans.back() == x){
			break ;
		}
		ans.push_back(x) ;
		}
	}
	int l = ans.size() ;
	if(k >= l){
		for(auto i : ans.back()) cout << i << " " ;
	} else {
		k-- ;
		for(auto i : ans[k]) cout << i << ' ' ;
	}
	return 0 ;
}

