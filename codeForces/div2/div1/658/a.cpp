#include <bits/stdc++.h>
using namespace std ;

#define int long long

vector<int> solve(string& s){
	vector<int> ans ;
	char prev = s[0] ;
	for(int i = 1 ; i < s.size() ; i++){
		if(s[i] == prev) continue ;
		prev = s[i] ;
		ans.push_back(i) ;
	}
	if(s.back() == '1'){
		ans.push_back(s.size()) ;
	}
	return ans ;
}

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		string a , b ;
		cin >> a >> b ;
		auto v = solve(a) ;
		auto s = solve(b) ;
		reverse(s.begin() , s.end()) ;
		cout << v.size() + s.size() << " " ;
		for(auto i : v) cout << i << " " ;
		for(auto i : s) cout << i << " " ;
		cout << '\n' ;
	}
	return 0 ;
}

