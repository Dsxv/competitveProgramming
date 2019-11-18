#include<bits/stdc++.h>
using namespace std;

int main(){
	int n ; cin >> n ;
	 int a[n] ;
	 int ans[n] ;
	 int sum = 0 ;
	 for(int i = 0 ; i < n ; i++) {
		 cin >> a[i] ;
		 sum += a[i]/2 ;
		 ans[i] = a[i]/2 ;
	 }
	for(int i = 0 ; i < n && sum > 0 ; i++) {
		if((a[i]&1) && a[i] < 0) sum-- , ans[i]-- ;
	}
	for(int i = 0 ; i < n && sum < 0 ; i++) {
		if((a[i]&1) && a[i] > 0 ) sum++ , ans[i]++ ;
	}
	assert(sum == 0) ;
	for(int i = 0 ; i < n ; i++) cout << ans[i] <<"\n" ;
}	
