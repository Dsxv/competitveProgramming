#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ;
	string s ;
	cin >> n >> s ;
	map<char,int> mp ;
	for(auto i : s) mp[i]++ ;
	string ans = "" ;
	for(auto i : mp){
		ans += string(i.second,i.first) ;
	}
	cout << ans ;
	return 0 ;
}

