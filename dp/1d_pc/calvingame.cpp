#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n , k ;
	cin >> n >> k ;
	k--;
	int a[n] ;	
	pair<int,int> dpl[n] = {{0,0}} , dpr[n] = {{0,0}} ;
	for(int i = 0 ; i < n ; i++) {
		cin >> a[i] ;
		dpl[i].first = ( dpr[i].first = a[i] );
	}
	if(n == 1) {
		cout << 0 ;
		return 0 ;
	}
	if(a[n-1] > 0){
		dpr[n-2].first += a[n-1] ;
		dpr[n-2].second = 1 ;
	}
	for(int i = n - 3 ; i >= 0 ; i--){
		if(max(dpr[i+1].first , dpr[i+2].first) <= 0) continue ;
		if(dpr[i+1].first > dpr[i+2].first){
			dpr[i].first += dpr[i+1].first ;
			dpr[i].second = 1 ;
		}else{
			dpr[i].first += dpr[i+2].first ;
			dpr[i].second = 2 ;
		}
	}
	dpl[1].first += dpl[0].first ;
	for(int i = 2 ; i < n ; i++){
		dpl[i].first += max(dpl[i-1].first,dpl[i-2].first) ;
	}
	int final_point = k ;
	int sum = 0 ;
	for(int i = k ; i < n ;){
		final_point = i + dpr[i].second ;
		if(final_point == i) break ;
		sum += a[final_point] ;
		i = final_point ;
	}
	int x = final_point ;

	sum += max(a[x]+max((x+1<n?a[x+1]:INT_MIN) ,(x+2<n?a[x+2]:INT_MIN)),0LL) ;
	//for(int i = 0 ; i < n ; i++) cout << dpr[i].second <<" " ; cout << endl;
	//for(int i = 0 ; i < n ; i++) cout << dpl[i].first << " " ; cout << endl ;
    int ans = dpl[final_point].first - a[final_point] ;
	int fk = dpl[k].first - a[k] ;
	//cout << sum << " " << ans <<" "<<fk << endl ;
	cout << max(sum+ans,fk) ;	
	return 0 ;
}

