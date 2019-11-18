#include <bits/stdc++.h>
using namespace std ;

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		string s ;
		cin >> s ;
		vector<pair<int,int>> v ;
		int n = s.size() ;
		for(int i = 0 ; i < s.size() ; i++){
			if(s[i] != '.') {
				v.push_back({max(0,i-(s[i]-'0')) , min(n-1,i+(s[i]-'0'))}) ;
			}
		}
		bool found = true ;
		for(int i = 1 ; i < v.size() ; i++){
			if(v[i-1].second < v[i].first) continue ;
			int cur_width = v[i].second - v[i].first + 1 ;
			int prev_width = v[i-1].second - v[i-1].first + 1;
			if(cur_width != prev_width) found = false ;
			if(v[i].first <= v[i-1].first) found = false ;
			if(v[i-1].second >= v[i].second) found = false ;
		}
		if(found) cout << "safe\n" ;
		else cout << "unsafe\n" ;
	}
	return 0 ;
}

