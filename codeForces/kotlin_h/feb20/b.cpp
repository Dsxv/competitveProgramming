#include <bits/stdc++.h>
using namespace std ;

#define int long long

bool check(int x , pair<int,int>* p , int n){
	int cnt = 0 ;
	for(int i = 0 ; i < n ; i++){
		cnt += (x >= p[i].first && x <= p[i].second) ;
	}
	return cnt == 1 ;
}

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >>  n;
		pair<int,int> p[n] ;
		for(int i = 0 ; i < n ; i++){
			cin >> p[i].first >> p[i].second ;
		}
		set<int> s ;
		for(int i = 0 ; i < n ; i++){
			s.insert(p[i].first+1) ;
			s.insert(p[i].first-1) ;
			s.insert(p[i].first) ;
			s.insert(p[i].second) ;
			s.insert(p[i].second+1) ;
			s.insert(p[i].second-1) ;
		}
		int ans = -1 ;
		for(auto i : s){
			if(check(i,p,n))  {ans = i ; break ;}
		}
		cout << ans << '\n' ;
	}
	return 0 ;
}

