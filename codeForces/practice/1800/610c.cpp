#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int k ;
	cin >> k ;
	vector<string> v ;
	v.push_back("+") ;
	for(int i = 0 ; i < k ; i++){
		vector<string> temp ;
		for(auto j : v){
			temp.push_back(j + j) ;
		}
		for(auto j : v){
			string s = j ;
			for(auto &x : s) x ^= '*'^'+' ;
			temp.push_back(j+s) ;
		}
		v = temp ;
	}
	for(auto i : v) cout << i << '\n' ;
	return 0 ;
}

