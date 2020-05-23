#include <bits/stdc++.h>
using namespace std ;

#define int long long 

const int mod = 998244353 ;

int modexp(int a , int n){
	if(n == 0){
		return 1 ;
	}
	if(n == 1) return a; 
	int x = modexp(a,n/2) ;
	x = (x*x) % mod ;
	if(n&1) x = (x*a) % mod ;
	return x ;
}

typedef struct data
{
	data* bit[2];
	int cnt = 0;
}trie;

trie* head;

void insert(int x)
{
	trie* cur = head;
	for(int i=30;i>=0;i--)
	{
		int b = (x>>i) & 1;
		if(!cur->bit[b])
			cur->bit[b] = new trie();
		cur = cur->bit[b];
		cur->cnt++;
	}
}

void remove(int x)
{
	trie* cur = head;
	for(int i=30;i>=0;i--)
	{
		int b = (x>>i) & 1;
		cur = cur->bit[b];
		cur->cnt--;
	}
}

int maxor(int x, trie* cur = head, int i = 30)
{	
	if(i == -1) {
		return cur->cnt ;
	}
	return ans;
}

int32_t main(){
	int n , m ;
	cin >> n >> m ;
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	for(int i = 0 ; i < n ; i++){
		int x ; cin >> x ;
		insert(x) ;
	}
	while(m--){
		int x ;
		cin >> x ;
		int ans = maxor(x) ;
		cout << (ans*modexp(n,mod-2)) % mod << '\n' ;
	}
}
