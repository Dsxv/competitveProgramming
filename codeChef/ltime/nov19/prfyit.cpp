#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		string s ;
		cin >> s ;
		vector<pair<char,int>> v ;
		v.push_back({s[0],1}) ;
		for(auto i : s){
			if(v.back().first == i) v.back().second++ ;
			else v.push_back({i,1}) ;
		}
		if(v.size() <= 3){
			cout << 0 << endl ;
			continue ;
		} else {
			int n = v.size() ;
			int a[n+1] = {0} , b[n+1] = {0};
			for(int i = 1 ; i <= n ; i++){
				a[i] = a[i-1] , b[i] = b[i-1] ;
				if(v[i-1].first == '1') a[i] += v[i-1].second ;
				else b[i] += v[i-1].second ;
			}
			int ans ;
			if(v[0].first == '1') ans = a[n] - a[1] ;
		  	else ans = b[n] - b[1] ;	
			for(int i = 2 ; i <= n ; i++){
				if(v[i-1].first == '1') {
					ans = min(ans,a[i-1] + a[n] - a[i]) ;
				} else {
					ans = min(ans,b[i-1] + b[n] - b[i]) ;
				}
			}
			cout << ans << endl ;
		}
	}
	return 0 ;
}

