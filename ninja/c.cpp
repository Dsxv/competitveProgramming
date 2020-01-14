#include <bits/stdc++.h>
using namespace std;
#define int long long

const int M = 1014 ;

int permutations[M], permutations2[M];
char s[M];
char temp[M];
int N, X;

bool visited[M];


int go(int x) {
	int ret = 0;
	while(!visited[x]) {
		++ret;
		visited[x] = 1;
		x = permutations[x];
	}
	return ret;
}


int32_t main() {
   cin >> X >> s ; 
	N = strlen(s) ;
	if(N <= 2) { 
		cout << s << endl ;
		return 0;
	}

	for(int i = 0; i < N; ++i) permutations2[i] = i;
	for(int i = 0; i < N / 2; ++i) {
		permutations[2 * i] = permutations2[i];
		permutations[2 * i + 1] = permutations2[N - i - 1];
	}
	if(N % 2) permutations[N - 1] = permutations2[N / 2];


	int temp_ans = 1;
	for(int i = 0; i < N; ++i) {
		if(visited[i]) continue;
		int t = go(i);
		temp_ans = temp_ans * t / __gcd(temp_ans, t);
	}

	X %= temp_ans;
	X = temp_ans - X;

	for(int i = 0; i < X; ++i) {
		for(int j = 0; j < N / 2; ++j) {
			temp[2 * j] = s[j];
			temp[2 * j + 1] = s[N - j - 1];
		}
		if(N & 1) temp[N - 1] = s[N / 2];
		memcpy(s, temp, sizeof s);
	}

	cout << s << endl ;

	return 0;

}
