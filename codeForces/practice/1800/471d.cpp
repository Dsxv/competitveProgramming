//https://cp-algorithms.com/string/z-function.html
#include <bits/stdc++.h>
using namespace std ;

#define int long long

vector<int> z_function(vector<int>& s){
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
	int n , w ;
	cin >> n >> w ;
	int a[n] , b[w] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	for(int i = 0 ; i < w ; i++) cin >> b[i] ;
	if(w==1){
		cout << n ;
		return 0 ;
	}
	vector<int> v ;
	for(int i = 0 ; i < w - 1 ; i++){
		v.push_back(b[i] - b[i+1]) ;
	}
	v.push_back(1e9 + 10) ;
	for(int i = 0 ; i < n - 1 ; i++){
		v.push_back(a[i] - a[i+1]) ;
	}
	auto ans = z_function(v) ;
	int count = 0 ;
	for(int i = w ; i < ans.size() ; i++){
		if(ans[i] == w-1) count++ ;
	}
	cout << count ;
	return 0 ;
}


