#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	string s ;
	cin >> s ;
	vector<pair<char,int>> v; 
	v.push_back({s[0] , 1}) ;
	for(int i = 1 ; i < s.size() ; i++){
		if(s[i] == v.back().first) v.back().second++ ;
		else v.push_back({s[i] , 1}) ;
	}
	if(v.size() % 2){
		int i = 0 , j = v.size() - 1 ;
		bool found = true ;
		while(i <= j){
			if(v[i].first != v[j].first || (v[i].second + v[j].second < 3)){
				found = false ;
				break ;
			}
			i++ , j-- ;
		}
		cout << found * (v[v.size() / 2].second + 1) ;
	} else {
		cout << 0 ;
	}
	return 0 ;
}

