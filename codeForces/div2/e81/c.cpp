#include <bits/stdc++.h>
using namespace std ;

#define int long long

bool ok(string& t , int* ch){
	for(auto i : t){
		if(ch[i-'a'] == 0) return false ;
	}
	return true ;
}

int32_t main(){
	int tc ;
	cin >> tc ;
	while(tc--){
		string s , t ;
		cin >> s >> t ;
		int ch[26] = {};
		set<int> st[26] ;
		for(int i = 0 ; i < (int)s.size() ; i++){
			ch[s[i]-'a']++ ;
			st[s[i]-'a'].insert(i) ;
		}
		if(ok(t,ch)) {
			int ans = 0 ;
			for(int i = 0 ; i < (int)t.size() ; i++){
				int j = i , id = -1 ;
				while(j < (int)t.size() && id < *(st[t[j]-'a'].rbegin()) ){
						 id = *(st[t[j]-'a'].upper_bound(id)) ;
						 j++ ;
				}
				i = j-1 ;
				ans++ ;
			}
			cout << ans << endl ;
		} else {
			cout << -1 << endl ;
		}
	}
	return 0 ;
}

