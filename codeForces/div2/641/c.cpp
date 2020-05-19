#include <bits/stdc++.h>
using namespace std ;

#define int long long

vector<int> solve(int x){
	int l = sqrt(x) ;
	vector<int> v ;
	if(x % 2 == 0){
		while(x % 2 == 0){
			x /= 2 ;
		}
		v.push_back(2) ;
	}
	for(int i = 3 ; i <= l ; i += 2){
		if(x % i == 0){
			while(x % i == 0){
				x /= i ;
			}
			v.push_back(i) ;
		}
	}
	if(x > 2) v.push_back(x) ;
	return v ;
}

int power(int a , int x){
	int ans = 1 ;
	for(int i = 0 ; i < x ; i++){
		ans *= a ;
	}
	return ans ;
}

int32_t main(){
	int n ;
	cin >> n ;
	int a[n] ;
	map<int,vector<int>> mp ;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i] ;
		vector<int> fact = solve(a[i]) ;
		for(auto j : fact){
			if(mp[j].size() == 0) mp[j].resize(32) ;
			int count = 1 ;
			while(a[i]%j == 0){
				mp[j][count]++ ;
				a[i] /= j ;
				count++ ;
			}
			mp[j][0]++ ;
		}
	}
	int ans = 1 ;
	for(auto i : mp){
		int y = 0 ;
		for(int j = 0 ; j < 32 ; j++){
			if(i.second[j] >= n - 1){
				y = j ;
			} else {
				break ;
			}
		}
		cout << y << " " ;
		y = power(i.first,y) ;
		ans *= y ;
	}
	cout << ans ;
	return 0 ;
}
