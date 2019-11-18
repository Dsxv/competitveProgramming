#include <bits/stdc++.h>
using namespace std ;

#define int long long

bool check(string& s , string& t , int n){
	vector<pair<char,char>> v ;
	for(int i = 0 ; i < n ; i++){
		if(s[i] != t[i]) v.push_back({s[i],t[i]}) ;
	}
	int l = v.size() ;
	if(l == 0) return true ;
	if(l!=2){
		return false ;
	}
	return v[0].first == v[1].first && v[0].second == v[1].second ;
}

int32_t main(){
	int t ; cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		string s , t ;
		cin >> s >> t ;
		if(check(s,t,n)) cout << "Yes\n" ;
		else cout << "No\n" ;

	}
	return 0 ;
}

