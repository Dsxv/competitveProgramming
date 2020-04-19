#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ;
	cin >> n ;
	string s[n] ;
	map<int,vector<int>> v[26]; 
	int visited[n] = {} ;
	for(int i = 0 ; i < n ; i++){
		cin >> s[i] ;
		char prev = 'a' ;
		int cnt = 0 ;
		for(auto j : s[i]){
			if(j == 'a' || j == 'e' || j == 'i' || j == 'o' || j == 'u')
				cnt++ , prev = j ;
		}
		v[prev-'a'][cnt].push_back(i) ;
	}
	vector<pair<int,int>> last ;
	for(int i = 0 ; i < 26 ; i++) {
		if(v[i].size()) 
		for(auto j : v[i]){
			for(int x = 0 ; x < (int)j.second.size()-1 ; x += 2){
				last.push_back({j.second[x] , j.second[x+1]}) ;
				visited[j.second[x]] = 1 ;
				visited[j.second[x+1]] = 1 ;
			}
		}
	}
	//cout << last.size() << endl ;
	//for(auto i : last) cout << i.first << " " << i.second << endl ;
	map<int,vector<int>> rem ;
	for(int i = 0 ; i < n ; i++){
		if(!visited[i]) {
			int cnt = 0 ;
			for(auto j : s[i]){
				if(j == 'a' || j == 'e' || j == 'i' || j == 'o' || j == 'u') {
					cnt++ ;
				}
			}
			rem[cnt].push_back(i) ;
		}
	}
	vector<pair<int,int>> ff ;
	for(auto i : rem){
		for(int j = 0 ; j < (int)i.second.size()-1 ; j+=2){
			ff.push_back({i.second[j] , i.second[j+1]}) ;
		}
	}
	vector<pair<int,int>> ans ;
	while(ff.size() && last.size()) {
		ans.push_back({ff.back().first,last.back().first}) ;
		ans.push_back({ff.back().second,last.back().second}) ;
		ff.pop_back() ;
		last.pop_back() ;
	}
	while(last.size() > 1){
		pair<int,int> a = last.back() ;
		last.pop_back() ;
		ans.push_back({a.first,last.back().first}) ;
		ans.push_back({a.second,last.back().second}) ;
		last.pop_back() ;
	}
	cout << (int)ans.size()/2 << endl ;
	for(auto i : ans){
		cout << s[i.first] << " " << s[i.second] << '\n' ;
	}
	return 0 ;
}

