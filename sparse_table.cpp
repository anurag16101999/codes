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

//min_value
struct sparse_table{
    vector<vector<int>>mat;
    int n,m;
    vector<int> p2;
    void init(int _n,int _m){
        n=_n;
        m=_m;
        mat.resize(n);
        p2.resize(n+1);
        for(int i=0;i<n;i++)mat[i].resize(m);
        for(int i=1;i<=n;i++)p2[i]=p2[i/2]+1;
    }

    void build(int a[]){
        for(int i=0;i<n;i++)
        {
            mat[i][0]=a[i];
        }
        for(int j=1;j<m;j++){
            for(int i=0;i+(1<<j)<=n;i++)
            {
                mat[i][j]=min(mat[i][j-1],mat[i+(1<<(j-1))][j-1]);
            }
        }
    }

    int query(int l,int r)
    {
        int pw=p2[r-l];
        return min(mat[l][pw],mat[r-(1<<pw)+1][pw]);
    }
}



main()
{

}
