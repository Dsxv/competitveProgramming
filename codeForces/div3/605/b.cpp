#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t;
	while(t--){
		string s ;
		cin >> s ;
		vector<pair<char,int>> v ;
		v.push_back({s[0],1}) ;
		for(int i = 1 ; i< s.size() ; i++){
			if(v.back() != s[i]) 
				v.push_back({s[i],1}) ;
			else v.back().second++ ;
		}
	return 0 ;
}

