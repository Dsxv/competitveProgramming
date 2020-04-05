#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n;
	cin >> n ;
	map<string , int> mp ;
	pair<string,int> p[n] ;
	for(int i = 0 ; i < n ; i++){
		string s ; 
		int x ;
		cin >> s >> x ;
		p[i] = {s,x} ;
		mp[s] += x ;
	}
	int mx = 0 ;
	for(auto i : mp){
		mx = max(i.second , mx) ;
	}
	map<string,int> temp ;
	for(int i = 0 ; i < n ; i++){
		temp[p[i].first] += p[i].second ;
		if(mp[p[i].first] == mx && temp[p[i].first] >= mx){
			cout << p[i].first ;
			return 0 ;
		}
	}
	return 0 ;
}

