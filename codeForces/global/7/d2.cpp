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

string getval(string s){
	if((int)s.size() == 0) return s ;
	string rev = s , tp = s ;
	reverse(rev.begin(),rev.end()) ;
	s += "#" + rev ;
	vector<int> z = z_function(s) ;
	int mx = 1 , ind = 0 ; 
	int cnt = 0 ;
	for(int i = tp.size() + 1; i < z.size() ; i++){
		if((z[i] + i) == z.size()){
			mx = max(z[i],mx) ;
		}
	}
	string temp(tp.begin(),tp.begin()+mx) ;
	return temp;
}

string solve1(string s){
	string rev = s ;
	reverse(rev.begin(),rev.end()) ;
	int ind = 0 ;
	string ans = "" ;
	for(int i = 0; i < (int) s.size() / 2 ; i++){
		if(s[i] == rev[i]) ind = i+1;
		else break ;
	}
	string kp = s.substr(0,ind) ;
	string tp = kp ;
	reverse(tp.begin(),tp.end()) ;
	string temp(s.begin()+ind,s.end()-ind) ;
	string t2 = getval(temp) ;
	return kp + t2 + tp;
}

inline int gs(string& s){
	return s.size() ;
}

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		string s ;
		cin >> s ;
		vector<pair<int,string>> v ;
		string x = solve1(s) ;
		v.push_back({gs(x),x}) ;
		string y = getval(s) ;
		v.push_back({gs(y),y}) ;
		reverse(s.begin(),s.end()) ;
		x = solve1(s) ;
		v.push_back({gs(x),x}) ;
		y = getval(s) ;
		v.push_back({gs(y),y}) ;
		sort(v.begin(),v.end(),greater<pair<int,string>>()) ;
		cout << v.begin()->second << endl;
	}
	return 0 ;
}


