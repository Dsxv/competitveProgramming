#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int mod = 998244353 ;

int modexp(int a , int n){
	if(n == 0) return 1 ;
	if(n == 1) return a ;
	int x = modexp(a , n / 2) ; 
	x = (x*x) % mod ;
	if(n&1) x = (x*a) % mod ;
	return x ;
}

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

bool is_pref(string& a , string& b){
	string s = a + "&" + b ;
	auto v = z_function(s) ;
	for(int i = 0 ; i < v.size() ; i++){
		if((i + v[i]) == v.size()) return true ;
	}
	return false ;
}

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int t ;
	cin >> t ;
	while(t--){
		string s ;
		cin >> s ;
		int val[26] ;
		for(int i = 0 ; i < 26 ; i++) cin >> val[i] ;
		int n = s.size() ;
		int ans = 0 ;
		for(int i = 0 ; i < n ; i++){
			string temp = "" ;
			int sum = 0 ;
			for(int j = i ; j < n ; j++){
				temp += s[j] ;
				sum += val[s[j]-'a'] ;
				cout << temp << " :: " ; 
				for(int k = j ; k < n ; k++){
					string x = s.substr(i , k - i + 1) ;
					cout << x << " : " ;
					if(is_pref(temp , x)){
						ans += sum ;
						cout << "y\n" ;
					} else {
						cout << endl ;
						break ;
					}
				}
			}	
		}
		ans %= mod ;
		int den = n*(n+1) / 2 ;
		den %= mod ;
		cout << ans << '\n' ;
		//cout << (ans*modexp(den , mod - 2)) % mod << '\n' ;
	}
	return 0 ;
}

