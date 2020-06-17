#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n , m , k ;
	cin >> n >> m >> k ;
	vector<int> fact ;
	int l = sqrt(k) ;
	for(int i = 1 ; i <= l ; i++){
		if(k%i) continue ;
		if((i*i) == k){
			fact.push_back(i) ;
		} else {
			fact.push_back(k/i) ;
			fact.push_back(i) ;
		}
	}
	map<int,int> mp1 , mp2 ;
	int a[n] , b[m] ;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i] ;
	}
	for(int i = 0 ; i < m ; i++){
		cin >> b[i] ;
	}
	int sum = 0 ;
	for(int i = 0 ; i < n ; i++){
		sum += a[i] ;
		if(a[i] == 0){
			for(int i = 1; i <= sum ; i++){
				mp1[i] += (sum-i+1) ;
			}
			sum = 0 ;
		}
	}
	if(sum){
		for(int i = 1 ; i <= sum ; i++){
			mp1[i] += sum - i + 1 ;
		}
	}
	sum = 0 ;
	for(int i = 0 ; i < m ; i++){
		sum += b[i] ;
		if(b[i] == 0){
			for(int i = 1 ; i <= sum ; i++){
				mp2[i] += sum - i + 1 ;
			}
			sum = 0 ;
		}
	}
	if(sum){
		for(int i = 1 ; i <= sum ; i++){
			mp2[i] += sum - i + 1 ;
		}
	}
	int ans = 0 ;
	for(auto i : fact){
		ans += mp1[i]*mp2[k/i] ;
	}
	cout << ans ;
	return 0 ;
}

