#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		string s ;
		cin >> s ;
		int n = s.size() ;
		vector<pair<char,int>> v ;
		v.push_back({s[0],1}) ;
		for(int i = 1 ; i < n ; i++){
			if(s[i] == v.back().first) v.back().second++ ;
			else v.push_back({s[i],1}) ;
		}
		int o = 0 , z = 0 ;
		int mo = 0 , mz = 0 ;
		for(auto i : v){
			if(i.first == '1') {
				o += i.second ;
				mo = max(mo,i.second) ;
			} else{
				z += i.second ;
				mz = max(mz,i.second) ;
			}
		}
		int p = max(0LL,o-mo) , q = max(0LL,z-mz) ;
		int l = v.size() ;
		if(v.size()%2 && v.size() > 1){
			if(v[0].first == '1'){
				p = min(o - v[0].second - v.back().second , p) ;
			} else {
				q = min(z - v[0].second - v.back().second,q) ;
			}
		}
		cout << max(0LL, min(p,q)) << endl;
	}
	return 0 ;
}

