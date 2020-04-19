#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		pair<int,int> a[n] ;
		for(int i = 0 ; i < n ; i++){
			cin >> a[i].first >> a[i].second ;
		}
		int x[n] ;
		int sum = 0 ;
		for(int i = 0 ; i < n ; i++){
			x[i] = max(0LL,a[i].first - a[(i-1+n)%n].second) ;
			sum += x[i] ;
		}
		for(int i = 0 ; i < n ; i++) a[i].second = x[i] ;
		sort(a,a+n,[](pair<int,int> a , pair<int,int> b){
				return a.first - a.second < b.first - b.second ;
			}) ;
		cout << sum + a[0].first - a[0].second << '\n' ;
	}
	return 0 ;
}

