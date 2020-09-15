#include <bits/stdc++.h>
using namespace std ;

#define int long long

bool check(int x , int* a , int n){
	int i = x , j = n - 1 ;
	vector<int> v ;
	while(i <= j){
		if(a[i] < a[j]) v.push_back(a[i++]) ;
		else v.push_back(a[j--]) ;
	}
	return is_sorted(v.begin() , v.end()) ;
}

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ; 
		cin >> n ;
		int a[n] ;
		for(int i = 0 ; i < n ; i++){
			cin >> a[i] ;
		}
		int lo = 0 , hi = n - 1 ;
		int ans = 0 ;
		while(lo <= hi){
			int mid = (lo + hi) / 2 ;
			if(check(mid , a , n)){
				ans = mid ;
				hi = mid - 1 ;
			} else {
				lo = mid + 1 ;
			}
		}
		cout << ans << '\n' ;
	}
	return 0 ;
}

