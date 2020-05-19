#include <bits/stdc++.h>
using namespace std ;

#define int long long

bool check(string &s , string &t){
	if(s.size() == t.size()){
		return (s > t) ;
	}
	for(int i = 0 ; i < s.size() && i < t.size() ; i++){
		if(s[i] > t[i]) return true ;
		if(s[i] < t[i]) return false ;
	}
	return s.size() > t.size() ;
}

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n , k ;
		cin >> n >> k ;
		string s ;
		cin >> s ;
		sort(s.begin() , s.end()) ;
		string ans = string(1,s[0]) ;
		if(count(s.begin() , s.end() , s[0]) == n){
			cout << string((n+k-1)/k , s[0]) << '\n' ;
			continue ;
		}
		for(int i = k ; i < s.size() ; i++) ans += s[i] ;
		string val = ans ;
		bool ok = false ;
		for(int i = 1 ; i < k ; i++) if(ans[0] < s[i]) {
			ok = true ;
			val = s[i] ;
		}
		if(ok || count(ans.begin() , ans.end(), ans[0]) > 1){
			cout << val << '\n' ;
			continue ;
		}
		set<char> st(ans.begin(),ans.end()) ;
		if(st.size() == 2){
			char ch = *s.rbegin() ;
			int cnt = (count(ans.begin() , ans.end() , ch) + k - 1) / k ;
			cout << ans[0] ;
			for(int i = 0 ; i < cnt ; i++) cout << ch ;
			cout << '\n' ;
		} else {
			cout << ans << '\n' ;
		}
	}
	return 0 ;
}

