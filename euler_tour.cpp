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

vector<int> gr[N];
int tin[N],tout[N];
int timer=0;
//timer is left for now

//whether x is ancestor of y or not
bool is_ancestor(int x,int y)
{
    return tin[x]<=tin[y]&&tout[x]>=tout[y];
}




void euler_tour_1(int cur,int par)
{
    cout << cur << " ";
    //tin[cur]=timer++;
    for(auto x:gr[cur])
    {
        if(x!=par)
        {
            euler_tour_1(x,cur);
            cout << cur << " ";
        }
    }
    //tout[cur]=timer++;
    return;
}

void euler_tour_2(int cur,int par)
{
    cout << cur << " ";
    //tin[cur]=timer++;
    for(auto x:gr[cur])
    {
        if(x!=par)
        {
            euler_tour_2(x,cur);
        }
    }
    //tout[cur]=timer++;
    cout << cur << " ";
    return;
}

void euler_tour_3(int cur,int par)
{
    cout << cur << " ";
    //tin[cur]=timer++;
    for(auto x:gr[cur])
    {
        if(x!=par)
        {
            euler_tour_3(x,cur);
        }
    }
    //tout[cur]=timer;
    return;
}

main()
{
    int n;
    cin >> n;
    int m=n-1;
    while(m--)
    {
        int u,v;
        cin >> u >> v;
        gr[u].pb(v);
        gr[v].pb(u);
    }
    timer=0;
    //timer will start from 1 for first and second euler tour
    //euler_tour_1(1,0);cout << endl;
    //euler_tour_2(1,0);cout << endl;
    euler_tour_3(1,0);cout << endl;
}
