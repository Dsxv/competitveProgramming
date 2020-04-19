#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(set<int>& s , int a){
	int l = sqrt(a) ;
	if(a%2 == 0){
		s.insert(2) ;
		while(a%2 == 0) a/= 2 ;
	}
	for(int i = 3 ; i <= l ; i += 2){
		if(a % i == 0){
			s.insert(i) ;
			while(a % i == 0) a /= i ;
		}
	}
	if(a > 2) s.insert(a) ;
}

int32_t main(){
	int n ;
	cin >> n ;
	pair<int,int> p[n] ;
	for(int i = 0 ; i < n ; i++){
		cin >> p[i].first >> p[i].second ;
	}
	set<int> primes ;
	solve(primes,p[0].first) ;
	solve(primes,p[0].second) ;
	// created
	map<int,int> mp ;
	for(int i = 0 ; i < n ; i++){
		for(auto j : primes){
			if(p[i].first % j == 0 || p[i].second % j == 0){
				mp[j]++ ;
			}
		}
	}
	for(auto i : mp){
		if(i.second == n){
			cout << i.first ;
			return 0 ;
		}
	}
	cout << -1 ;
	return 0 ;
}

