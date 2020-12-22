#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	map<int , vector<string>> mp ;
	string s = "123456789" ;
	for(int i = 0 ; i < (1 << s.size()) ; i++){
		string cur = "" ; int val = 0 ;
		for(int j = 0 ; j < s.size() ; j++){
			if(i & (1 << j)){
				cur += s[j] ;
				val += s[j] - '0' ;
			}
		}
		mp[val].push_back(cur) ;
	}
	for(auto &i : mp){
		auto &v = i.second ;
		assert(v.size()) ;
		sort(v.begin() , v.end() , [&](string &a , string &b){
				if(a.size() != b.size()) return a.size() < b.size() ;
				for(int i = 0 ; i < a.size() ; i++) {
					if(a[i] != b[i]) return a[i] < b[i] ;
				}
				return  true;
			}) ;
	}
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n;
		if(mp.count(n)){
			cout << mp[n][0] << '\n' ;
		} else {
			cout << -1 << '\n' ;
		}
	}
	return 0 ;
}

