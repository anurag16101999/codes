
#include<bits/stdc++.h>
#define MOD     1000000007
#define int     long long int
#define fastIO  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define PI      3.1415926535897932384626
#define pb      push_back
#define clr(x)  memset(x, 0, sizeof(x))
#define MP      make_pair
const int N=131073;
using namespace std;
int gcd(int a,int b){if(a==0)return b;return gcd(b%a,a);}
int lcm(int a,int b){return (max(a,b)/gcd(a,b))*min(a,b);}
int powermodm(int x,int n,int M){int result=1;while(n>0){if(n % 2 ==1)result=(result * x)%M;x=(x*x)%M;n=n/2;}return result;}
int gcdExtended(int a, int b, int *x, int *y){if (a == 0){*x = 0, *y = 1;return b;}int x1, y1;int gcd = gcdExtended(b % a, a, &x1, &y1);*x = y1 - (b / a) * x1;*y = x1;return gcd;}
int modInverse(int a, int m){int x, y;int g = gcdExtended(a, m, &x, &y);if (g != 1)return -1;else{int res = (x % m + m) % m;return res;}}
bool isPrime(int a){if(a==1) return false;if(a==2) return true;if(a%2==0) return false;int root=sqrt(a);for(int i=3;i<=(int)root;i+=2){if(a%i==0)return false;}return true;}

//buildtree for storing minimum for a range
//leafnode will contain array element
void buildTree(int *a,int s,int e,int *tree,int index)
{
    if(s==e){
        tree[index]=a[s];
        return;
    }

    //recursive case
    int mid=(s+e)/2;
    buildTree(a,s,mid,tree,2*index);
    buildTree(a,mid+1,e,tree,2*index+1);

    tree[index]=min(tree[2*index],tree[2*index+1]);
    return;
}

int query(int *tree,int ss,int se,int qs,int qe,int index)
{
    //complete overlap
    if(ss>=qs&&se<=qe)
        return tree[index];

    //No Overlap
    if(qe<ss||qs>se)
        return INT_MAX;

    //Partial Overlap
    int mid=(ss+se)/2;
    int left=query(tree,ss,mid,qs,qe,2*index);
    int right=query(tree,mid+1,se,qs,qe,2*index+1);
    return min(left,right);
}

void updateNode(int *tree,int ss,int se,int i,int increment,int index)
{
    //Case where I is out of bounds
    if(i>se||i<ss)
        return;
    if(ss==se)
    {
        tree[index]+=increment;
        return;
    }
    //otherwise
    int mid=(ss+se)/2;
    updateNode(tree,ss,mid,i,increment,2*index);
    updateNode(tree,mid+1,se,i,increment,2*index+1);
    tree[index]=min(tree[2*index],tree[2*index+1]);
}

void updateRange(int *tree,int ss,int se,int l,int r,int inc,int index)
{
    //out of bounds
    if(l>se||r<ss)
        return;

    //leaf node
    if(ss==se)
    {
        tree[index]+=inc;
        return;
    }

    //recursive case
    int mid=(ss+se)/2;
    updateRange(tree,ss,mid,l,r,inc,2*index);
    updateRange(tree,mid+1,se,l,r,inc,2*index+1);
    tree[index]=min(tree[2*index],tree[2*index+1]);
    return;
}


main()
{
    fastIO;
    int a[]={1,3,2,-5,6,4};
    int n=sizeof(a)/sizeof(int);
    int *tree=new int[4*n+1];
    //int tree[4*n+1];
    buildTree(a,0,n-1,tree,1);

    //updateNode(tree,0,n-1,3,10,1);
    updateRange(tree,0,n-1,3,5,10,1);
    int q;
    cin >> q;
    while(q--)
    {
        int l,r;
        cin >> l >> r;
        cout << query(tree,0,n-1,l,r,1) << endl;
    }

}
