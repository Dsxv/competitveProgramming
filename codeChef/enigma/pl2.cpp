#include <bits/stdc++.h>
using namespace std ;

#define int long long

vector<pair<string,int>> v ;

bool check(pair<string,int> a , pair<string,int> b){
	return a.second < b.second ;
}

bool ok(string s){
	int c = 0 ;
	for(auto i : s) {
		if(i == '(') c++ ;
		if(i == ')') c-- ;
		if(c < 0) return false ;
	}
	return c == 0 ;
}

void solve(string s , string ans = ""){
	if(!(int)s.size()){
		if(ok(ans)){ 
			v.push_back({ans,ans.size()}) ;
		}
		return ;
	}
	solve(s.substr(1),ans) ;
	solve(s.substr(1),ans+s[0]) ;
}

int32_t main(){
	ios :: sync_with_stdio(0) ; 
	cin.tie(0) ;
	string s ;
	cin >> s ;
	solve(s) ;
	set<string> ans ;
	int x = max_element(v.begin(),v.end(),check)->second ;
	for(auto i : v) {
		if(i.second == x) ans.insert(i.first) ;
	}
	for(auto i : ans) cout << i << '\n' ;
	return 0 ;
}

