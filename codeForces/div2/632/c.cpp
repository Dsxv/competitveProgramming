#include <bits/stdc++.>
using namespace std ;

#define int long long

int32_t main(){
	int n ;
	cin >> n ;
	int a[n] ;
	int sum = 0 ;
	int count = 0 ;
	map<int,int> mp ;
	int max_d = 0;
	mp[0] = -1 ;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i] ;
		sum += a[i] ;
		if(mp.count(sum)){
			max_d = max(max_d , mp[sum] + 2) ;
		}
		count += max(0LL ,i-max_d) + (a[i] != 0) ;
		mp[sum] = i ;
	}
	cout << count ;
	return 0 ;
}

