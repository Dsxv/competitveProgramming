//https://cp-algorithms.com/string/z-function.html
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

int32_t main(){
	string s ;
	cin >> s ;
	vector<int> z = z_function(s) ;
	int n = s.size() ;
	map<int,int> mp ;
	int a[n] = {0} ;
	for(int i = 0 ; i < n ; i++) a[z[i]]++ ;
	for(int i = n-2 ; i >= 0 ; i--) a[i] += a[i+1] ;
	int ans = 0 ;
	for(int i = 0 ; i < n ; i++){
		if(i + z[i] == n && a[z[i]] > 1){
			ans = max(ans,z[i]) ;
		}
	}
	cout << (ans ? s.substr(0,ans) : "Just a legend");
	return 0 ;
}


