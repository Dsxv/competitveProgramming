#include <bits/stdc++.h>
using namespace std ;

#define int long long

int solve(vector<int>& a , int b){
	sort(a.begin() , a.end()) ;
	int val = 0 ;
	const int x = 1e7 ;
	for(int i = 0 ; i < a.size() ; i++){
		for(int j = i + 1 ; j < a.size() ; j++){
			int xx = a[i] , yy = a[j] - a[i] , zz = 100 - a[j] ;
			val += (xx > b || yy > b || zz > b) ;
		}
	}
	double ans = (double)2*val/(a.size()*(a.size()-1)) ;
	return ans*x ;
}

int32_t main(){
	int b ;
	int n ;
	cin >> n ;
	vector<int> a(n) ;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i] ;
	}
	cin >> b ;
	cout << solve(a,b) ;
	return 0 ;
}

