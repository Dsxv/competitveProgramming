#include <bits/stdc++.h>
using namespace std ;

#define int long long

struct box{
	int l , b , h ;
	box(int x , int y , int z){
		l = x , b = y , h = z ;
	}
} ;

bool check(box a , box b){
	return a.l * a.b < b.l * b.b ;
}

int32_t main(){
	int t;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		vector<box> v ;
		for(int i = 0 ; i < n ; i++){
			int a[3] ;
			cin >> a[0] >> a[1] >> a[2] ;
			sort(a,a+3) ;
			v.push_back(box(a[2],a[1],a[0])) ;
			v.push_back(box(a[2],a[0],a[1])) ;
			v.push_back(box(a[1],a[0],a[2])) ;
		}
		sort(v.begin(),v.end(),check) ;
		n = v.size() ;
		int dp[n] = {0} ;
		for(int i = 0 ; i < n ; i++){
			dp[i] = v[i].h ;
			for(int j = i-1 ; j >= 0 ; j--){
				if(v[j].l < v[i].l && v[j].b < v[i].b){
					dp[i] = max(dp[i],v[i].h + dp[j]) ;
				}
			}
		}
		cout << *max_element(dp,dp+n) << '\n';
	}
	return 0 ;
}

