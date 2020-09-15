#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define double long double

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		double a[n] ;
		double ea[n] , eb[n] ;
		priority_queue<pair<int,int>> pqa , pqb ;
		for(int i = 0 ; i < n ; i++){
			cin >> a[i] >> ea[i] >> eb[i];
			ea[i] = 1/ea[i] ;
			eb[i] = 1/eb[i] ;
			pqa.push({ea[i],i}) ;
			pqb.push({eb[i],i}) ;
		}
		double ca = 0 , cb = 0 ;
		vector<double> vis(n,-1) ;
		double start = 0 ;
		double ansa = 0 , ansb = 0 ;
		while(pqa.size() || pqb.size()){
			if(ca <= cb){
				if(pqa.empty()) continue ;
				auto [x,ind] = pqa.top() ;
				pqa.pop() ;
				if(vis[ind] == -1){
					vis[ind] = ca ;	
					ca += (a[ind] / ea[ind]) ;
					ansa += a[ind] ;
				} else {
					// vis ind has an entry time
					double ft = ca - vis[ind] ; // time for b to eat gold at ind
					if((a[ind] / eb[ind]) <= ft) {
						continue ;
					} else {
						ansb -= a[ind] ; // nahi khaya pura
						ansb += ft*eb[ind] ; // free time jitna hi kha paya
						a[ind] -= ft*eb[ind] ;
						double val = a[ind] / (eb[ind] + ea[ind]) ;
						ansa += val*ea[ind] , ansb += val*eb[ind] ;
						ca = cb = (ca + val) ;
					}
				}
			} else {
				if(pqb.empty()) continue ;
				auto [x,ind] = pqb.top() ;
				pqb.pop() ;
				if(vis[ind] == -1){
					vis[ind] = cb ;
					cb += (a[ind] / eb[ind]) ;
					ansb += a[ind] ;
				} else {
					double ft = cb - vis[ind] ; // time for a to eat gold at ind
					if((a[ind] / ea[ind]) <= ft){
						continue ; // kha gya pura bc
					} else {
						// bacha hai abhi bhi
						ansa -= a[ind] ; // part remaining
						ansa += ft*ea[ind] ;
						a[ind] -= ft*ea[ind] ;
						double val = a[ind] / (ea[ind] + eb[ind]) ; // total time to eat rem
						ansa += val*ea[ind] ; ansb += val*eb[ind] ;
						ca = cb = (cb + val) ;
					}
				}
			}
		}
		cout <<setprecision(15) << fixed <<  ansa << " " << ansb << '\n' ;
	}
	return 0 ;
}

