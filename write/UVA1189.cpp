#include<algorithm>
#include<iostream>
using namespace std;
int n,k;
void dfs(long long ans,int n,int index){
    if(k == 0)return;
    if(index == 20)return;
    if(ans % n == 0){
        printf("%lld\n",ans);
        k = 0;
        return;
    }
    dfs(ans * 10,n,index + 1);
    dfs(ans * 10 + 1,n,index + 1);
}
int main(){
    while(scanf("%d",&n) && n!=0){
        k = 1;
        dfs(1,n,1);
    }
    system("pause");
    return 0;
}