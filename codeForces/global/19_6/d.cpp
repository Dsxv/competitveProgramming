#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n , m ;
	cin >> n >> m ;
	map<int,int> mp[n] ;
	for(int i = 0 ; i < m ; i++) {
		int f , s , v;
		cin >> f >> s >> v ;
		mp[f-1][s-1] += v;
	}
	for(int i = 0 ; i < n ; i++){
		for(auto& j : mp[i]){
			if(mp[j.first].size()){
				auto t = mp[j.first].begin() ;
				if(t->second > j.second){
					if(i != t->first) mp[i][t->first] += j.second ; 
					mp[j.first][t->first] -= j.second ;
					mp[i].erase(j.first) ;
				} else if(j.second > t->second){
					if(i != t->first) mp[i][t->first] += t->second ; 
					j.second -= t->second ;
					mp[j.first].erase(t->first) ;
				} else {
					if(i != t->first) mp[i][t->first] += t->second ; 
					mp[j.first].erase(t->first) ;
					mp[i].erase(j.first) ;	
				}
			}
		}
	}
	int count = 0 ;
	for(int i = 0 ; i < n ; i++) count += mp[i].size() ;
	cout << count << endl ;
	for(int i = 0 ; i < n ; i++) {
		for(auto j : mp[i])
			cout << i+1 <<" "<< j.first + 1 << " " << j.second << '\n' ;
	}
	return 0 ;
}

