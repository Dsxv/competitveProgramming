#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t; 
	while(t--){
		int n ;
		cin >> n;
		vector<set<pair<int,int>>> v(n) ;
		int count = 1 ;
		int ans[n] = {} ;
		v[n-1].insert({0,n-1}) ;
		int f = n -1  ;
		while(f >= 0){
			if(v[f].size() == 0) {
				f-- ;
				continue ;
			}
			int l = v[f].begin()->first , r = v[f].begin()->second ;
			v[f].erase(v[f].begin()) ;
			if(r == l){
				ans[r] = count++ ;
				continue ;
			}
			if(r == l+1){
				ans[l] = count++ ;
				v[1].insert({r,r}) ;
				continue ;
			}
			int mid = (l+r-1 + ((r-l+1)&1)) / 2 ; 
			v[mid-l].insert({l,mid-1}) ;
			v[r-mid].insert({mid+1,r}) ;
			ans[mid] = count++ ;
		}
		for(auto i : ans) cout << i << " " ;
		cout << '\n' ;
	}
	return 0 ;
}

