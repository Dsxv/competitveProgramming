#include <bits/stdc++.h>
using namespace std ;

#define int long long

int solve(int x , vector<int>& v, int i = 0 , bool ok = 0){
	if(i == x){
		return 1 ;
	}
	if(ok){
		int ans = 0 ;
		int prev = 1 ;
		for(int j = i ; j < x ; j++){
			prev *= 5 ;
			ans += prev ;
		}
		return ans ;
	}
	int ans = 0 ;
	for(int j = (i + 1) % 2 ; j <= v[i] ; j += 2){
		ans += solve(x , v , i + 1 , 1 - (j == v[i])) ;
	}
	return ans ;
}


int getval(int r){
	if(r == 0) return 0 ;
	int x = log10(r) + 1 ;
	int ans = 0 ;
	int prev = 1 ;
	for(int i = 1 ; i < x ; i++){
		prev *= 5 ;
		ans += prev ;
	}
	vector<int> v ;
	int cur = r ;
	while(cur){
		v.push_back(cur % 10) ;
		cur /= 10 ;
	}
	reverse(v.begin() , v.end()) ;
	ans += solve(x , v) ;
	return ans ;
}

void gogogo(){
	int l , r ;
	cin >> l >> r ;
	cout << getval(r) - getval(l-1) << '\n' ;
}

int32_t main(){
	int t ;
	cin >> t ;
	for(int i = 1 ; i <= t ; i++){
		cout << "Case #" << i << ": ";
		gogogo() ;
	}
	return 0 ;
}


