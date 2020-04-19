#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ;
	cin >> n ;
	map<int,int> odd , even ;
	int x = 0 ;
	odd[0]++ ;
	int ans = 0 ;
	for(int i = 0 ; i < n ; i++){
		int ai ;
		cin >> ai ;
		x ^= ai ;
		if(i&1){
			ans += odd[x] ;
			odd[x]++ ;
		} else {
			ans += even[x] ;
			even[x]++ ;
		}
	}
	cout << ans ;
	return 0 ;
}

