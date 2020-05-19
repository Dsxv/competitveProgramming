#include <bits/stdc++.h>
using namespace std ;

#define int long long

struct env{
	int first , second , i ;
	env(){
		first = second = i = INT_MAX ;
	}
} ;

int32_t main(){
	int n , w , h ;
	cin >> n >> w >> h ;
	env p[n] ;
	for(int i = 0 ; i < n ; i++) {
		cin >> p[i].first >> p[i].second;
		p[i].i = i ;
	}
	sort(p,p+n,[](env a , env b){
			return a.first*a.second < b.first*b.second ;
		}) ;
	int dp[n] = {} ;
	for(int i = 0 ; i < n ; i++){
		if(p[i].first > w && p[i].second > h) dp[i] = 1 ;
		else continue ;
		for(int j = i-1 ; j >= 0 ; j--){
			if(p[i].first > p[j].first && p[i].second > p[j].second){
				dp[i] = max(dp[i] , dp[j] + 1) ;
			}
		}
	}
	int mx = *max_element(dp,dp+n) ;
	vector<int> v ;
	env prev ;
	for(int i = n - 1 ; i >= 0 ; i--){
		if(dp[i] == mx && p[i].first < prev.first && p[i].second < prev.second && p[i].first > w && p[i].second > h){
			mx-- ;
			v.push_back(p[i].i+1) ;
			prev = p[i] ;
		}
	}
	reverse(v.begin(),v.end()) ;
	cout << v.size() << '\n' ;
	for(auto i : v) cout << i << " " ;
	return 0 ;
}

