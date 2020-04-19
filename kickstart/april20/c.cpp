#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int mod = 1e9 ;

pair<int,int> gans(string s){
	pair<int,int> p(0,0) ;
	for(int i = 0 ; i < s.size() ;){
		if(s[i] >= '2' && s[i] <= '9'){
			int count = 0 ;
			int id = i ;
			for(int j = i + 1 ; j < s.size() ; j++){
				if(s[j] == '(') count++ ;
				if(s[j] == ')') count-- ;
				if(count == 0){
					id = j ;
					break ;
				}
			}
			string t = s.substr(i+2,(id-(i+2))) ; // i + 2 to id - 1 
			auto x = gans(t) ;
			p.first = (p.first + x.first*(s[i]-'0') + mod) % mod ;
			p.second = (p.second + x.second*(s[i]-'0') + mod) % mod ;
			i = id + 1 ;
		} else {
			if(s[i] == 'E') p.first++ ;
			if(s[i] == 'W') p.first-- ;
			if(s[i] == 'N') p.second-- ;
			if(s[i] == 'S') p.second++ ;
			p.first = (p.first + mod) % mod ;
			p.second = (p.second + mod) % mod ;
			i++ ;
		}
	}
	return p ;
}

void solve(int t){
	string s ;
	cin >> s ;
	pair<int,int> p = gans(s) ;
	cout << "Case #"<<t<<": "<< p.first + 1 << " " << p.second + 1 << '\n';
}

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int t ;
	cin >> t ;
	for(int i = 1 ; i <= t ; i++){
		solve(i) ;
	}	
	return 0 ;
}


