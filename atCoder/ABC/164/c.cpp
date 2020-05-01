#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	map<string , int> mp ;
	int n ;
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		string s ;
		cin >> s ;
		mp[s] = 1 ;
	}
	cout << mp.size() ;
	return 0 ;
}

