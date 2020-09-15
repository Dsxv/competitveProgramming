#include <bits/stdc++.h>
using namespace std ;

#define int long long

int solve(vector<int>& a){
	int n = a.size() ;
	if(n == 0) return 0 ;
	vector<int> v ;
	vector<int> ans(n) ;
	for(int i = 0 ; i < n ; i++){
		auto id = lower_bound(v.begin() , v.end() , a[i]) ;
		if(id == v.end()){
			v.push_back(a[i]) ;	
		} else {
			*id = a[i] ;
		}
		ans[i] = v.size() ;
	}
	return *max_element(ans.begin() , ans.end());
}

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n , m ;
		cin >> n >> m ;
		int a[n] ;
		map<int,int> mp ;
		for(int i = 0 ; i < n ; i++) {
			cin >> a[i] ;
			mp[a[i]] = i ;
		}
		vector<int> b ;
		for(int j = 0 ; j < m ; j++) {
			int x ; cin >> x ;
			if(mp.count(x)) b.push_back(mp[x]) ;
		}
		cout << n - solve(b) << '\n' ;
	}
	return 0 ;
}

