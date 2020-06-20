#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n;
	cin >> n ;
	map<int , int> mp ;
	for(int i = 0 ; i < n ; i++){
		int a , b , c ;
		cin >> a >> b >> c ;
		int val = sqrt(a*a + b*b) / c ;
		mp[val]++ ;
	}
	int ans = 0 ;
	for(auto i : mp){
		ans += i.second*(i.second-1) / 2 ;
	}
	cout << ans << '\n' ;
	return 0 ;
}

