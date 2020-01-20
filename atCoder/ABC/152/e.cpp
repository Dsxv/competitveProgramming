#include <bits/stdc++.h> 
#define F first 
#define S second 
#define MAX 1000003 
using namespace std; 
#define int long long
typedef long long ll; 
const int mod = 1000000007; 

int prime[MAX]; 
unordered_map<int, int> max_map; 

int power(int a, int n) 
{ 
	if (n == 0) 
		return 1; 
	int p = power(a, n / 2) % mod; 
	p = (p * p) % mod; 
	if (n & 1) 
		p = (p * a) % mod; 
	return p; 
} 

void sieve() 
{ 
	prime[0] = prime[1] = 1; 
	for (int i = 2; i < MAX; i++) { 
		if (prime[i] == 0) { 
			for (int j = i * 2; j < MAX; j += i) { 
				if (prime[j] == 0) { 
					prime[j] = i; 
				} 
			} 
			prime[i] = i; 
		} 
	} 
} 

ll lcmModuloM(const int* ar, int n) 
{ 

	for (int i = 0; i < n; i++) { 
		int num = ar[i]; 
		unordered_map<int, int> temp; 
		while (num > 1) { 
			int factor = prime[num]; 
			temp[factor]++; 
			num /= factor; 
		} 

		for (auto it : temp) { 
			max_map[it.first] = max(max_map[it.first], it.second); 
		} 
	} 

	ll ans = 1; 

	for (auto it : max_map) { 

		ans = (ans * power(it.F, it.S)) % mod; 
	} 

	return ans; 
} 

int32_t main() 
{ 
	sieve(); 
	int n ; cin >> n ;
	int a[n] ; 
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	int s =  lcmModuloM(a, n);
	int sum = 0 ;
	for(int i = 0 ; i < n ; i++){
		sum = (sum + (s*power(a[i],mod-2)) % mod ) % mod ;
	}
	cout << sum ;
	return 0; 
} 

