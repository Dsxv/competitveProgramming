#include <bits/stdc++.h>
using namespace std ;

#define int long long

int lis(int* a , int n){
	vector<int> v ;
	int ans = 1 ;
	for(int i = 0 ; i < n ; i++){
		auto x = upper_bound(v.begin(),v.end(),a[i]) ;
		if(x == v.end()) {
			v.push_back(a[i]) ;
		} else {
			*x = a[i] ;
		}
		ans = max(ans,(int)v.size()) ;
	}
	return ans ;
}

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ; cin >> n ;
		pair<int,int> p[n] ;
		for(int i = 0 ; i < n ; i++) cin >> p[i].first ;
		for(int i = 0 ; i < n ; i++) cin >> p[i].second ;
		sort(p,p+n,[](pair<int,int> a , pair<int,int> b){
				if(a.first != b.first) return a.first < b.first ;
				else return a.second < b.second ;
				}
			) ;
		int a[n] ;
		for(int i = 0 ; i < n; i++) {
			a[i] = p[i].second ;
		}
		cout << lis(a,n) << endl ;
	}
	return 0 ;
}

