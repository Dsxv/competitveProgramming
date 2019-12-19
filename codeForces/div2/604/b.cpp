#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n; 
		cin >> n ;
		pair<int,int> p[n] , a[n] ;
		for(int i = 0 ; i < n ; i++) {
			cin >> a[i].first ; a[i].second = i ;
		}
		sort(a,a+n) ;
		int ans[n] ;
		ans[0] = 1 ;
		p[0].first = p[0].second =  a[0].second ;
		for(int i = 1 ;  i < n ; i++){
			int ci = a[i].second ;
			int c1 = abs(ci - p[i-1].first) ;
			int c2 = abs(ci - p[i-1].second) ;
			int c3 = abs(p[i-1].first - p[i-1].second) ;
			if(max({c1,c2,c3}) <= i){
				ans[i] = 1 ;
			} else {
				ans[i] = 0 ;
			}
			p[i] = {min(ci,p[i-1].first),
					max(ci,p[i-1].second)} ;
		}
		for(auto i : ans) cout << i ;
		cout << endl ;
	}
	return 0 ;
}

