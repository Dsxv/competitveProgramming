#include <bits/stdc++.h>
using namespace std ;

const int N = 1<<19 , mod = 1e9 + 7;
int dpt[71][2] ;
int pos[71][2] ;
int dp[71][N] ;
int maskval[71] ;
map<int,int> mp ;

int rmask(int n){
	vector<int> cnt(20) ;
	int p = n ;
	int l = sqrt(n) ;
	for(int i = 2 ; i <= l ; i++){
		while(n%i == 0){
			n /= i ;
			cnt[mp[i]]++ ;
			cnt[mp[i]] %= 2 ;
		}
	}
	if(n >= 2){
		cnt[mp[n]] = (cnt[mp[n]] + 1) % 2 ;
	}
	int ans = 0 ;
	for(int i = 0 ; i < 19 ; i++) {
		if(cnt[i]) {
			ans |= 1 << i ;
		}
	}
	return ans ;
}

int solve(int i , int mask = 0){
	if(i == 71){
		return mask == 0 ;
	}
	if(~dp[i][mask]) return dp[i][mask] ;
	long long a = solve(i+1 , mask^maskval[i]) ;
	long long b = solve(i+1 , mask) ;
	return dp[i][mask] = ( (a*pos[i][1]) % mod + (b*pos[i][0])%mod ) % mod ;
}

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int n ;
	cin >> n ;
	memset(dp , -1 , sizeof(dp)) ;
	vector<int> v ;
	for(int i = 2 ; i < 71 ; i++){
		bool found = true ;
		for(int j = 2 ; j < i ; j++) {
			if(i%j == 0) {
				found = false ; break ;
			}
		}
		if(found) {
			mp[i] = v.size() ;
			v.push_back(i) ;
		}
	}
	vector<int> cnt(71) ;
	int a[n] ;
	for(int i = 0 ; i < 71 ; i++) pos[i][0] = 1 ;
	for(int i = 0 ; i  < n ; i++){	
		cin >> a[i] ;
		pos[a[i]][0] = pos[a[i]][1] = (pos[a[i]][0] + pos[a[i]][1]) % mod ;
		cnt[a[i]]++ ;
	}
	for(int i = 1 ; i < 71 ; i++){
		if(i - 1) maskval[i] = rmask(i) ;
	}
	memset(dpt , -1 , sizeof(dpt)) ;
	long long ans = solve(2) ;
	long long a1 = (pos[1][0] + pos[1][1]) % mod ;
	cout << ((ans*a1) % mod - 1 + mod) % mod ;
	return 0 ;
}



