#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n; 
	cin >> n ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	int l = 0 , r = n - 1 ;
	int maxl = 0 , maxr = 0 ;
	int sum = 0 ;
	while(l < r){
		if(a[l] < a[r]){
			sum += max(0LL,maxl-a[l]) ;
			maxl = max(maxl,a[l++]) ;
			//moving towards right from current point ensures us that
			//right is higher and will not pose threat while considering
			//the height of water stored in left side.
			//i.e, minimum height for water is present on left side.
		}else{
			sum += max(maxr-a[r],0LL) ;	
			maxr = max(maxr,a[r--]) ;

		}
	}
	cout << sum ;
	return 0 ;
}

