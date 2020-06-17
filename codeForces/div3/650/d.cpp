#include <bits/stdc++.h>
using namespace std ;

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int t ;
	cin >> t; 
	while(t--){
		string s ;
		cin >> s ;
		int m ;
		cin >> m ;
		pair<int,int> a[m] ;
		multiset<pair<int,int>> ms ;
		for(int i = 0 ; i < m ; i++){
			int x ; cin >> x ;
			ms.insert({x,i}) ;
		}
		string ans(m,'x') ;
		sort(s.begin() , s.end() , greater<char>()) ;
		int n = s.size() ; 
		int pre[n] ;
		pre[n-1] = 1 ;
		for(int i = n - 2 ; i >= 0 ; i--){
			if(s[i] == s[i+1]) pre[i] = pre[i+1] + 1 ;
			else pre[i] = 1 ;
		}
		int sz = 0 ; 
		while(ms.size()){
			int fr = ms.begin()->first ;
			int id = ms.begin()->second ;
			int cnt = 0 ;
			for(auto i : ms){
				cnt += (i.first == fr) ;
			}
			while(sz < n && pre[sz] != cnt) sz++ ;
			if(sz == n) break ;
			ms.erase(ms.begin()) ;
			ans[id] = s[sz++] ;
			vector<pair<int,int>> temp ;
			for(auto i : ms){
				temp.push_back({max(0 , i.first - abs(id - i.second)) , i.second}) ;
			}
			ms.clear() ;
			for(auto i : temp) ms.insert(i) ;
		}
		cout << ans << '\n' ;
	}
	return 0 ;
}

