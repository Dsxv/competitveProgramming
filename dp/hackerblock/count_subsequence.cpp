#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int mod = 1e9 + 7 ;

int solve(int* dp , int* prevv , string& s , int i){
	if(i == (int)s.size()){
		return 1 ;
	}
	if(i > (int)s.size()) return 0 ;
	if(dp[i] != -1) return dp[i] ;
	if(prevv[i] == -1){
		return dp[i] = (2*solve(dp,prevv,s,i+1)) % mod ;
	} else {
		int ind = prevv[i] ;
		return dp[i] = 
			(2*solve(dp,prevv,s,i+1) 
			 - solve(dp,prevv,s,ind+1) + mod) % mod ;
	}
}

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		string s ;
		cin >> s ;
		int n = s.size() ;
		int dp[n+2] , prevv[n+2];
		memset(dp, -1 , sizeof(dp)) ;
		memset(prevv,-1,sizeof(prevv)) ;
		map<char,int> mp ;
		for(int i = n-1 ; i >= 0 ; i--){
			if(mp.count(s[i])) {
				prevv[i] = mp[s[i]] ;
				mp[s[i]] = i ;
			} else {
				mp[s[i]] = i ;
			}
		}
		cout << solve(dp,prevv,s,0) << endl ;	
	}
	return 0 ;
}

