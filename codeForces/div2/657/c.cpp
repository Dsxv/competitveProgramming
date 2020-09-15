#include <bits/stdc++.h>
using namespace std ;

#define int long long

struct s{
	int x , tp , i ;
} ;

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ,m  ;
		cin >> n >> m ;
		s a[2*m] ;
		int p[m] ;
		for(int i = 0 ; i < m ; i++){
			int x = 2*i , y = 2*i + 1 ;
			cin >> a[x].x >> a[y].x ;
			a[x].tp = 0 , a[y].tp = 1 ;
			a[x].i = i ; a[y].i = i ;
			p[i] = a[x].x ;
		}
		int visited[m][2] = {} ; 
		sort(a,a+2*m,[&]( s a , s b){
				if(a.x != b.x) return a.x > b.x ;
				return a.tp < b.tp ;
				}) ;
		int mx = 0 ;
		pair<int,int> pre[2*m] = {} ;
		for(int i = 0 ; i < 2*m ; i++){
			if(i){
				pre[i] = pre[i-1] ;
			}
			if(a[i].tp == 0){
				pre[i].first += a[i].x ;
				pre[i].second++ ;
			} else {
				if(visited[a[i].i][0]){
					mx = max(mx , a[i].x*(n - pre[i].second) + pre[i].first) ; 
				} else {
					mx = max(mx , a[i].x*(n - pre[i].second - 1) + pre[i].first + p[a[i].i]) ;
				}
			}
			visited[a[i].i][a[i].tp]++ ;
			if(pre[i].second == n){
				mx = max(pre[i].first , mx) ;
				break ;
			}
		}
		cout << mx << '\n' ;
	}
	return 0 ;
}

