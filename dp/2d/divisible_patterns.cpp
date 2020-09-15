///https://cp-algorithms.com/string/z-function.html
#include <bits/stdc++.h>
using namespace std ;

#define int long long

vector<int> z_function(string& s){
	int n = s.size() ;
	vector<int> z(n) ;
	for(int i = 1 , l = 0 , r = 0 ; i < n ; i++){
		if(i <= r) {
			z[i] = min(z[i-l],r-i+1) ;
		}
		while(i + z[i] < n && s[z[i]] == s[i+z[i]]){
			z[i]++ ;
		}
		if(i + z[i] - 1 > r) 
			l = i , r = i + z[i] - 1 ;
	}
	return z ;
}

const int N = 1e4 + 10 , mod = 1e9 + 7;
int dp[N][1LL<<10] ;
int solve(vector<int>& v , int i = 0 , int mask = 0){
	if(i == v.size()){
		return mask == (1LL<<10) - 2 ;
	}
	if(~dp[i][mask]) return dp[i][mask] ;
	int x = 0 ;
	for(int j = 1 ; j <= 9 ; j++){
		if(v[i] % j == 0){
			x |= 1LL<< j; 
		}
	}
	bitset<10> a(mask) , b(x) ;
	if(a[3] && b[3]) x |= (1<<9) ;
	if((a[4] && b[2]) || (a[2] && b[4])) x |= (1<<8) ;
	if((a[3] && b[2]) || (a[2] && b[3])) x |= (1<<6) ;
	if(a[2] && b[2]) x |= (1<<4) ;
	return dp[i][mask] = ( solve(v , i + 1 , x | mask) + solve(v , i + 1 , mask) ) % mod ;
}

int32_t main(){
	memset(dp , -1 , sizeof(dp)) ;
	string s , p ;
	cin >> p >> s;
	s = p + '$' + s ;
	vector<int> z = z_function(s) ;
	vector<int> v ;
	for(int i = p.size() ; i < z.size() ; i++){
		if(z[i] == p.size()){
			v.push_back(i - p.size()) ;
		}
	}
	cout << solve(v) ;
	return 0 ;
}
