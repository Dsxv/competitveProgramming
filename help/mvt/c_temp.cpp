#include <bits/stdc++.h>
using namespace std ;

#define int long long

int len(string &t){
	int ans = 0 ;
	for(int i = 0 ; i < t.size() ; i++){
		int cnt = 1 ;
		while(i < t.size() - 1 && t[i] == t[i+1]) {
			cnt++ ; i++ ;
		}
		if(cnt == 1) ans++ ;
		else ans += ceil(log10(cnt)) + 1 ;
	}
	return ans ;
}

int solution(string &s , int k){
	int ans = INT_MAX ;
	int n = s.size() ;
	for(int i = 0 ; i <= n - k ; i++){
		string t = s.substr(0 , i) + s.substr(i + k , n - i - k) ;
		ans = min(ans , len(t)) ;
	}
	return ans ;
}

int32_t main(){
	string s ;
	int k ;
	cin >> s >> k ;
	cout << solution(s , k) ;
	return 0 ;
}

