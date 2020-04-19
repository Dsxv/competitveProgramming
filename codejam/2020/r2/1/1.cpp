#include <bits/stdc++.h>
using namespace std ;

#define int long long

inline bool ok(string &a , string &b){
	//cout << b.substr(0,(int)a.size()) << " " << a << endl ;
	return b.substr(0,(int)a.size()) == a ;
}

void solve(int t){
	int n ;
	cin >> n ;
	string s[n] ;
	for(int i = 0 ; i < n ; i++){
		cin >> s[i] ;
	}
	map<int,set<string>> mp;
	vector<string> last ;
	for(int i = 0 ; i < n ; i++){
		int cnt = 0 ;
		string temp = "";
		for(int j = 0 ; j < s[i].size() ; j++){
			if(s[i][j] == '*'){
				mp[cnt++].insert(temp) ;
				temp = "";
			} else {
				temp += s[i][j] ;
			}
		}
		if(s[i].back() != '*') {
			reverse(temp.begin(),temp.end()) ;
			last.push_back(temp) ;
		}
	}
	string check = "" ;
	bool found = true ;
	for(auto j : mp[0]){
		if(j.size() > check.size()) {
			check = j ;
		}
		if(!ok(j,check)) found = false ;
	}
	for(auto j : mp[0]) if(!ok(j,check)) found = false ;
	string check2 = "";
	for(auto j : last){
		if(j.size() > check2.size()) {
			check2 = j ;
		}
	}
	for(auto j : last) if(!ok(j,check2)) found = false ;
	reverse(check2.begin(),check2.end()) ;
	string ans = "";
	if(found){
		for(auto i : mp){
			if(i.first) 
			for(auto j : i.second){
				ans += j ;
			}
		}
		ans = check + ans + check2 ;
	} else { 
		ans = "*";
	}
	cout << "Case #"<< t << ": " << ans << '\n' ;
}

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int t ;
	cin >> t ;
	for(int i = 1 ; i <= t ; i++){
		solve(i) ;
	}	
	return 0 ;
}


