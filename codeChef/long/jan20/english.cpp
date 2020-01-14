#include <bits/stdc++.h>
using namespace std ;

#define int long long

int get_c(string& s , string& t){
	int x = 0 , y = 0 ;
	int l = s.size() , m = t.size() ;
	int mn = min(l,m) ;
	for(int i = 0 ; i < mn ; i++) {
		if(s[i] == t[i]) x++ ;
		else break ;
	}
	for(int i = 0 ; i < mn ; i++){
		if(s[l-i-1] == t[m-i-1]) y++ ;
		else break ;
	}
	return min(x,y) ;
}

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		map<string,int> mp ;
		for(int i = 0 ; i < n ; i++){
			string s ;
			cin >> s ;
			mp[s]++ ;
		}
		int ans = 0 ;
		vector<string> v ;
		for(auto i : mp){
			int l = i.first.size() ;
			if(i.second&1) v.push_back(i.first) ;
			ans += (i.second/2)*(l*l) ;
		}
		map<int,vector<pair<int,int>> , greater<int>> nmp ;
		for(int i = 0 ; i < v.size() ; i++){
			for(int j = i + 1 ; j < v.size() ; j++){
				int x = get_c(v[i],v[j]) ;
				x *= x ;
				nmp[x].push_back({i,j}) ;
			}
		}
		int visited[v.size()] = {0} ;
		for(auto i : nmp){
			for(auto j : i.second){
				int f = j.first , s = j.second ;
				if(!visited[f] && !visited[s]) {
					ans += i.first;
					visited[f] = visited[s] = 1 ;
				}
			}
		}
		cout << ans << '\n' ;
	}
	return 0 ;
}

