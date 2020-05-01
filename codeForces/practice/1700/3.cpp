#include <bits/stdc++.h>
using namespace std ;

#define int long long

int type(string& s){
	int a = -1 , b = INT_MAX ;
	for(int i = 0 ; i < s.size() ; i++){
		if(isalpha(s[i])) {
			a = max(a,i) ;
		}
		if(isdigit(s[i])) {
			b = min(b,i) ;
		}
	}
	return a > b ;
}


vector<int> solve(int n ){
	vector<int> v ;
	while(n){
		n-- ;
		int r = (n)%26 ;
		v.push_back(1 + r) ;
		n -= r ;
		n /= 26 ;
	}
	reverse(v.begin(),v.end()) ;
	return v ;
}


int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		string s ;
		cin >> s ;
		if(type(s)){ // rxcy
			int id = 0 ;
			int row = 0 ;
			for(id = 1 ; s[id] != 'C' ; id++){
				row = row*10 + (s[id] - '0') ;
			}
			int col = 0 ;
			for(int i = id + 1 ; i < s.size() ; i++){
				col = col*10 + (s[i] - '0') ;
			}
			auto v = solve(col) ;
			string ans = "" ;
			for(auto i : v) ans += (char)('A' + i - 1) ;
			cout << ans << row << '\n';
		} else {
			int id = 0 ;
			while(isalpha(s[id])) id++ ;
			int col = 0 ;
			for(int i = 0 ; i < id ; i++){
				col = col*26 + (s[i] - 'A' + 1) ;
			}
			cout << "R" << s.substr(id) << "C" << col << '\n' ;
		}
	}
	return 0 ;
}

