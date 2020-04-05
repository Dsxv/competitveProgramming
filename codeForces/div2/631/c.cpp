#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(int t){
	int n; 
	cin >> n; 
	pair<int,int> start[n] , end[n];
	for(int i = 0 ; i < n; i++){
		cin >> start[i].first ;
		start[i].second = i ;
		cin >> end[i].first ;
		end[i].second = i ;
	}
	sort(start,start+n) ;
	sort(end,end+n) ;
	int cam = -1 , jam = -1 ;
	int i = 0 , j = 0 ;
	string ans(n,'x') ;
	bool nope = false ;
	while(i < n && j < n){
		if(start[i].first < end[j].first){
			if(cam == -1){
				cam = start[i].second ;
				ans[start[i].second] = 'C' ;
			} else if(jam == -1){
				jam = start[i].second ;
				ans[start[i].second] = 'J' ;
			} else {
			 	nope = true ;
				break ;
			}
			i++ ;
		} else {
			if(end[j].second == cam){
				cam = -1 ;
			} else {
				jam = -1 ;
			}
			j++ ;
		}
	}
	cout << "Case #"<<t<<": ";
	if(nope){
		cout << "IMPOSSIBLE\n" ;
	} else {
		cout << ans << endl ;
	}
}

int32_t main(){
	int t ;
	cin >> t ;
	for(int i = 1 ; i <= t ; i++){
		solve(i) ;
	}	
	return 0 ;
}


