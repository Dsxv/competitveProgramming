#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t; 
	while(t--){
		int n , k ;
		cin >> n >> k ;
		string s ;
		cin >> s ;
		if(count(s.begin() , s.end() , '0') == n){
			cout << (n+k)/(k+1) << '\n' ; 
			continue ;
		}
		vector<pair<int,int>> v ;
		v.push_back({s[0] , 1}) ;
		for(int i = 1 ; i < n ; i++){
			if(v.back().first == s[i]){
				v.back().second++ ;
			} else {
				v.push_back({s[i] , 1}) ;
			}
		}
		int ans = 0 ;
		if(v.front().first == '0') {
			ans += v.front().second / (k + 1) ;
		}
		if(v.back().first == '0') {
			ans += v.back().second / (k + 1) ;
		}
		for(int i = 1 ; i < v.size() - 1 ; i++){
			if(v[i].first == '1') continue ;
			ans += (v[i].second - k) / (k + 1) ;
		}
		cout << ans <<'\n' ;
	}
	return 0 ;
}

