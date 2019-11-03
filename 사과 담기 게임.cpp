#include <iostream>
using namespace std;
int main(){int n,m,x1=1,x2,k,a,c=0;cin>>n>>m>>k;x2= m;for(int i=0;i<k;i++){cin>>a;if(x1>a){c+=x1-a;x2-=x1-a;x1=a;}if(x2<a){c+=a-x2;x1+=a-x2;x2=a;}}cout<<c;}