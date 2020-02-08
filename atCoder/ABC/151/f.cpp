#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int  n;
	cin >> n ;
	pair<int,int> p[n] ;
	for(int i = 0 ; i < n ; i++){
		int x , y ;
		cin >> x >> y ;
		p[i] = {x,y} ;
	}
	double d = 0.0 ;
	for(int i = 0 ; i < n ; i++){
		for(int j = i + 1 ; j < n ; j++){
			double xt = (p[i].first - p[j].first) ;
			double yt = (p[i].second - p[j].second) ;
			double ans = sqrt(xt*xt + yt*yt) ;
			d = max(ans,d) ;
		}
	}
	cout << fixed << setprecision(18) << d/2 ;
	return 0 ;
}

