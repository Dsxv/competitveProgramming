#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int x , n;
	cin >> x >> n;
	map<int,int> mp ;
	for(int i = 0 ; i < n ; i++) {
		int f ; cin >> f ;
		mp[f]++ ;
	}
	int ans ;
	for(int i = 0 ; i < 105 ; i++){
		if(!mp.count(x-i)){
			ans = x - i ;
			break ;
		} 
		if(!mp.count(x+i)){
			ans = x + i ;
			break ;
		}
	}
	cout << ans ;
	return 0 ;
}

