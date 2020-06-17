#include <bits/stdc++.h>
using namespace std ;

const int N = 1e7 + 10 ;
int prime[N] ;
int lp[N] ;
int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	for(int i = 2 ; i < N ; i++) prime[i] = 1 ;
	for(int i = 2 ; i < N ; i++){
		if(prime[i]){
			for(long long j = (long long)i*i ; j < N ; j += i){
				if(lp[j]) continue ;
				else lp[j] = i ;
			}
		}
	}
	int n ;
	cin >> n ;
	vector<pair<int,int>> ans ;
	for(int i = 0 ; i < n ; i++){
		int x ; 
		cin >> x ;
		int a = lp[x] , b = -1 ;
		while(x > 1 && a > 1){
			x /= a ;
			if(__gcd(x,a) == 1) { b = x ; break ;}
		}
		if(b <= 1){
			ans.push_back({-1,-1}) ;
		} else {
			ans.push_back({a,b}) ;
		}
	}
	for(auto i : ans) cout << i.first << " " ;
	cout << '\n' ;
	for(auto i : ans) cout << i.second << " " ;
	return 0 ;
}

