//https://cp-algorithms.com/string/z-function.html
#include <bits/stdc++.h>
using namespace std ;

#define int long long

vector<int> z_function(string s){
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
	string s , a ;
	cin >> s >> a ;
	int n = s.size() ;
	int k ;
	cin >> k ;
	int ans = 0 ;
	for(int i = 0 ; i < n ; i++){
		string temp = s.substr(0,i+1) ;
		reverse(temp.begin() , temp.end()) ;
		vector<int> v = z_function(temp) ;
		int mx = *max_element(v.begin(),v.end()) ;
		int count = 0 ;
		for(int j = 0 ; j < v.size() ; j++){
			count += !(a[temp[j]-'a']-'0') ;
			if(count > k) break ;
			ans += (j >= mx) ;
		}
	}
	cout << ans ;
	return 0 ;
}


