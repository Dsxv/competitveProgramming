#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ; cin >> n ;
		string s ;
		cin >> s ;
		vector<pair<char,int>> v ;
		v.push_back({s[0] , 1}) ;
		for(int i = 1 ; i < s.size() ; i++){
			if(v.back().first == s[i]){
				v.back().second++ ;
			} else {
				v.push_back({s[i],1}) ;
			}
		}
		string ans = "" ;
		if(v[0].first == '0'){
			ans += string(v[0].second,'0') ;
			v.erase(v.begin(),v.begin()+1) ;
		}
		if(v.size()){
			string temp = "" ;
			if(v.back().first == '1'){
				temp = string(v.back().second,'1') ;
				v.pop_back() ;
			}
			for(auto i : v){
				if(i.first == '0') {
					ans += '0' ;
					break ;
				}
			}
			ans += temp ;
		}
		cout << ans << '\n' ;
	}
				
	return 0 ;
}

