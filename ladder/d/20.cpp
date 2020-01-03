#include <bits/stdc++.h>
using namespace std ;

#define int long long
int n ;
const int N = 2e6 + 10 ;
int a[N] ;
int solve(vector<int>& v , int i){
	int x = v[i] ;
	int ans = 0 ;
	while(x < v.back()){
			int k = a[x+v[i]-1] ;
			if(k > x){
				ans = max(ans,k-x) ;
			}
			x += v[i] ;
	}
	return ans ;
}

int32_t main(){
	ios :: sync_with_stdio(0);
	cin.tie(0) ;
	cin >> n ;
	set<int> s ;
	for(int i = 0 ; i < n ; i++){
		int x ; cin >> x ;
		s.insert(x) ;
	}
	vector<int> v(s.begin(),s.end()) ;
	int ans = 0 ;
	n = v.size() ;
	for(int i = 0 ; i < n ; i++){
		a[v[i]] = v[i] ;
	}
	for(int i = 1 ; i < N ; i++){
		if(a[i]) continue ;
		else a[i] = a[i-1] ;
	}
	//for(int i = 0 ; i < 10 ; i++) cout << a[i] << " " ;
	for(int i = 0 ; i < n ; i++){
		ans = max(ans,solve(v,i)) ;
	}
	cout << ans ;
	return 0 ;
}

