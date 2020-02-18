#include <bits/stdc++.h>
using namespace std ;

#define int long long

int solve(vector<int>& v){
	int n = v.size() ;
	if(n < 3) return 0 ;
	vector<int> temp(n-1,0) ;
	for(int i = n-2 ; i >= 0 ; i--){
		temp[i] = temp[i] + v[i+1] ;
	}
	for(int i = 0 ; i < n - 1 ; i++){
		temp[i] = v[i]*temp[i] ;
	}
	int ans = 0 ;
	vector<int> temp2(n-2,0) ;
	for(int i = n - 3 ; i >= 0 ; i--){
		temp2[i] = temp2[i] + temp[i+1] ;
	}
	for(int i = 0 ; i < n - 1 ; i++){
		ans += temp2[i]*v[i] ;
	}
	return ans ;
}

int32_t main(){
	int n;
	cin >> n ;
	vector<int> v(n) ;
	for(int i = 0 ; i < n ; i++){
		cin >> v[i] ;
	}
	cout << solve(v) << endl;
	return 0 ;
}

