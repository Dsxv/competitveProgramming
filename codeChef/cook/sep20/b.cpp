#include <bits/stdc++.h>
using namespace std ;

#define int long long

int solve(vector<pair<char ,int>>& z , int l , int r , int k){
	vector<int> v ;
	for(int i = l ; i <= r ; i++){
		if(z[i].first == '0') v.push_back(z[i].second) ;
	}
	sort(v.begin() , v.end() , greater<int>()) ;
	int ans = 0 ;
	for(int i = 0 ; i < (k / 2) ; i++){
		ans += v[i] ;
	}
	return accumulate(v.begin() , v.end() , 0LL) - ans ;
}


int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int t ;
	cin >> t ;
	while(t--){
		int n  , k;
		cin >> n >> k ;
		string s ;
		cin >> s ;
		if(count(s.begin() , s.end() , '1') == s.size()){
			cout << 0 << '\n' ;
			continue ;
		}
		if(count(s.begin() , s.end() , '0') == s.size()){
			cout << 0 << '\n' ;
			continue ;
		}
		vector<pair<char, int>> v ;
		v.push_back({s[0] , 1}) ;
		for(int i = 1 ; i < s.size() ; i++){
			if(s[i] == v.back().first){
				v.back().second++ ;
			} else {
				v.push_back({s[i] , 1}) ;
			}
		}
		int ans = INT_MAX ;
		for(int i = 0 ; i < 4 ; i++){
			int curk = k , curz = 0 ;
			int l = 0 , r = v.size() - 1 ;
			if(i&1){
				if(v[0].first == '0'){
					curk-- ;
					l++ ;
				}
				if(i&2){
					if(v.back().first == '0'){
						curk-- ;
						r-- ;
					}
					curz += solve(v , l , r , curk) ;
				} else {
					if(v.back().first == '0'){
						curz += v.back().second ;
						r-- ;
					}
					curz += solve(v , l , r , curk) ;
				}
			} else {
				if(v[0].first == '0'){
					curz += v[0].second ;
					l++ ;
				}
				if(i&2){
					if(v.back().first == '0'){
						curk-- ;
						r-- ;
					}
					curz += solve(v , l , r , curk) ;
				} else {
					if(v.back().first == '0'){
						curz += v.back().second ;
						r-- ;
					}
					curz += solve(v , l , r , curk) ;
				}
			}
			ans = min(ans , curz) ;
		}
		cout << ans << '\n';
	}
	return 0 ;
}

