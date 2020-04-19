#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	string s ;
	cin >> s ;
	vector<char> v; 
	for(auto i : s){
		if(v.size() && v.back() == i){
			v.pop_back() ;
		} else {
			v.push_back(i) ;
		}
	}
	for(auto i : v) cout << i ;
	return 0 ;
}

