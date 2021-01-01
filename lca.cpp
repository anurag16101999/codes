#include<bits/stdc++.h>
#define MOD     1000000007
#define int     long long int
#define fastIO  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define PI      3.1415926535897932384626
#define pb      push_back
#define clr(x)  memset(x, 0, sizeof(x))
#define MP      make_pair
const int N=1e5+1;
using namespace std;
int gcd(int a,int b){if(a==0)return b;return gcd(b%a,a);}
int lcm(int a,int b){return (max(a,b)/gcd(a,b))*min(a,b);}
int powermodm(int x,int n,int M){int result=1;while(n>0){if(n % 2 ==1)result=(result * x)%M;x=(x*x)%M;n=n/2;}return result;}
int gcdExtended(int a, int b, int *x, int *y){if (a == 0){*x = 0, *y = 1;return b;}int x1, y1;int gcd = gcdExtended(b % a, a, &x1, &y1);*x = y1 - (b / a) * x1;*y = x1;return gcd;}
int modInverse(int a, int m){int x, y;int g = gcdExtended(a, m, &x, &y);if (g != 1)return -1;else{int res = (x % m + m) % m;return res;}}
bool isPrime(int a){if(a==1) return false;if(a==2) return true;if(a%2==0) return false;int root=sqrt(a);for(int i=3;i<=(int)root;i+=2){if(a%i==0)return false;}return true;}

vector<int> g[N];
int Par[N];
int dep[N];

void dfs(int cur,int par)
{
    Par[cur]=par;
    for(auto x:g[cur])
    {
        if(x!=par)
        {
            dep[x]=dep[cur]+1;
            dfs(x,cur);
        }
    }
    return;
}

//O(n) time
int lca_brute(int u,int v)
{
    if(u==v)
        return u;
    //take x to be at more depth
    if(dep[u]<dep[v]) swap(u,v);

    while(dep[u]>dep[v])
    {
        u=Par[u];
    }

    //they are at same level
    while(u!=v)
    {
        u=Par[u];
        v=Par[v];
    }
    return u;
}

main()
{
    int n;
    cin >> n;
    int m=n-1;
    while(m--)
    {
        int x,y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    dfs(1,0);
    cout << lca_brute(18,16);
}


/*
19
1 2
1 3
2 4
2 5
5 6
6 7
6 8
6 9
3 10
3 11
10 17
17 18
17 19
11 12
12 13
12 14
12 15
15 16
*/
