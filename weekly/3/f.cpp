#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 1e5 + 20 ;

bool check(pair<int,int> a , pair<int,int> b){
	return a.second < b.second ;
}

int bs(int x , vector<pair<int,int>>& a, int hi){
	int ans = -1 ;
	int lo = 0;
	while(lo <= hi){
		int mid = (lo + hi) / 2 ;
		if(a[mid].second <= x){
			ans = mid ;
			lo = mid + 1 ;
		} else {
			hi = mid - 1 ;
		}
	}
	return ans ;
}

pair<int,int> solve(vector<pair<int,int>>& coins , int c){
	int n = coins.size() ;	
	pair<int,int> ans = {0,0} ;
	if(n == 0) return ans ;
	sort(coins.begin(),coins.end(),check) ;
	vector<int> v(n) ;
	v[0] = coins[0].first ;
	for(int i = 1 ; i < n ; i++) {
		v[i] = max(v[i-1],coins[i].first) ;
	}

	for(int i = n-1 ; i >= 1 ; i--){
		if(c > coins[i].second){
			int ind =  bs(c-coins[i].second,coins,i-1) ;
			if(ind == -1) continue ;
			int p = coins[i].first , q = v[ind] ;
			if((ans.first + ans.second) < p + q) ans = {p,q} ;
		}
	}
	return ans ;
}


int32_t main(){
	int n , c , d ;
	cin >> n >> c >> d ;
	vector<pair<int,int>> coin , diam ;
	while(n--){
		int x , y ; char ch ;
		cin >> x >> y >> ch ;
		if(ch == 'C') coin.push_back({x,y}) ;
		else diam.push_back({x,y}) ;
	}
	sort(coin.begin(),coin.end(),greater<pair<int,int>>()) ;
	sort(diam.begin(),diam.end(),greater<pair<int,int>>()) ;
	pair<int,int> ab = {0,0} ;
	for(int i = 0 ; i <	(int)coin.size() ; i++){
		if(coin[i].second <= c){
			ab.first = coin[i].first ; break ;
		}
	}
	for(int i = 0 ; i < (int)diam.size() ; i++){
		if(diam[i].second <= d){
			ab.second = diam[i].first ; break ;
		}
	}
	if(ab.second == 0 || ab.first == 0) ab = {0,0} ;
	pair<int,int> t1 = solve(coin,c) ;
	pair<int,int> t2 = solve(diam,d) ;
	cout << max({t1.first + t1.second , t2.first + t2.second , 
			ab.first + ab.second}) ;
	return 0 ;
}

