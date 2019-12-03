#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ;
	cin >> n ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	pair<int,int> v[5] ;
	for(int i = 0 ; i < 5 ; i++) cin >> v[i].first ;
	int sum = 0 ;
	for(int i = 0 ; i < n ; i++){
		sum += a[i] ;
		for(int j = 4 ; j >= 0 ; j--){
			int k = sum/v[j].first ;
			sum -= v[j].first*k ;
			v[j].second += k ;
		}
	}
	for(int i = 0 ; i < 5 ; i++) cout << v[i].second << " ";
	cout << endl ;
	cout << sum ;
	return 0 ;
}

