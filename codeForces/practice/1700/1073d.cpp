#include <bits/stdc++.h>
using namespace std ;

#define int long long

int cnt = 0 , sum = 0 ;

void solve(int* a , int n , int t){
	cnt = 0 , sum = 0 ;
	for(int i = 0 ; i < n ; i++){
		if(a[i] <= t){
			t -= a[i] ;
			cnt++ ;
			sum += a[i] ;
		}
	}
	t += sum ;
}

int32_t main(){
	int n , t ;
	cin >> n >> t ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i] ;
	}
	int mn = *min_element(a,a+n) ;
	int ans = 0 ;
	while(t >= mn){
		solve(a,n,t) ;
		ans += (t/sum)*cnt ;
		t = t%sum ;
	}
	cout << ans ;
	return 0 ;
}

