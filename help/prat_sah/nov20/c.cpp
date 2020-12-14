#include <bits/stdc++.h>
using namespace std ;

#define int long long

vector<string> deviceNamesSystem(vector<string> devicenames){
	map<string , int> mp ;
	vector<string> ans ;
	for(auto i : devicenames){
		if(mp.count(i)){
			ans.push_back(i + to_string(mp[i])) ;
		} else {
			ans.push_back(i) ;
		}
		mp[i]++ ;
	}
	return ans ;
}

int32_t main(){
	vector<string> v ;
	int n ;
	cin >> n ;
	v.resize(n) ;
	for(auto &i : v) cin >> i ;
	vector<string> ans =  deviceNamesSystem(v) ;
	for(auto i : ans) cout << i << '\n' ;
	return 0 ;
}

