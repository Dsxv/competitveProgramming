#include <bits/stdc++.h>
using namespace std ;

#define int long long

int _lcm(int a , int b){
	return a*b / __gcd(a,b) ;
}

int32_t main(){
	int a , b ;
	cin >> a >> b ;
	if(a == b){
		cout << 0 ;
		return 0 ;
	}
	if(a > b) swap(a,b) ;
	int x = (b-a) ;
	if(a%x == 0) {
		cout << 0 ;
		return 0 ;
	} else {
		if(x > a){
			vector<int> fact ;
			int l = sqrt(x) ;
			for(int i = 1 ; i <= l ; i++){
				if(x%i) continue ;
				if(i*i == x){
					if(i >= a) fact.push_back(i) ;
				} else {
					if(i >= a) fact.push_back(i) ;
					if((x / i) >= a) fact.push_back(x/i) ;
				}
			}
			sort(fact.begin() , fact.end()) ;
			pair<int,int> ans = {fact[0] , _lcm(fact[0] , x)} ;
			for(int i = 1 ; i < fact.size() ; i++){
				int cur = _lcm(fact[i] , x) ;
				if(ans.second > x) {
					ans = {fact[i], cur} ;
				}
			}
			cout << ans.first - a ;
		} else {
			cout << (a/x)*x + x - a  ;
		}
	}
	return 0 ;
}

