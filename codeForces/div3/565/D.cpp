#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	const int N = 3e7 ;
	vector<int> temp ;
	int* sieve = new int[N] ;
	for(int i = 2 ; i < N ; i++){
		if(!sieve[i]){
			temp.push_back(i) ;
			for(int j = 2*i ; j < N ; j+=i){
				if(!sieve[j]) sieve[j] = j/i ;
			}
		}
	}
	map<int,int> primes ;
	for(int i = 0 ; i < temp.size() ; i++) primes[temp[i]] = i+1 ;
	int n ;
	cin >> n ;
	int b[2*n] ;
	unordered_map<int,int> mp ;
	vector<int> v ;
	for(int i = 0 ; i < 2*n ; i++){
		cin >> b[i];
		mp[b[i]]++ ;
	}
	sort(b,b+2*n) ;
	for(int i = 2*n - 1 ; i >= 0 ; i--){
		if(!mp[b[i]]) continue ;
		if(!sieve[b[i]]){
			// cout <<"prime" << b[i] << " "<<primes[b[i]] << endl ;
			mp[primes[b[i]]]-- ;
			v.push_back(primes[b[i]]) ;
		}else{
			// cout << "nprime" << b[i] <<" "<<sieve[b[i]] << endl ;
			mp[sieve[b[i]]]-- ;
			v.push_back(b[i]) ;
		}
		mp[b[i]]-- ;
		
	}
	for(auto i : v ) cout << i << " " ;
	return 0 ;		
}

