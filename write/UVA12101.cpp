#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
#include<cmath>
#define re register
using namespace std;
const int maxn = 1e5 + 2;
int prim[maxn],def[maxn],step[maxn];
int s[5]={0,1,10,100,1000};
int store[5];
int n,m,t,a,ans,sum;
queue<int>q;

void clear(queue<int>& q) {
	queue<int> empty;
	swap(empty, q);
}

void Esieve(){
    for(re int i=2;i<10000;i++){
        if(prim[i]) continue;
        for(re int j=i*i;j<10000;j+=i)
            prim[j] = 1;
    }
}

void bfs(int x){
    memset(def,0,sizeof(def));
    memset(step,0,sizeof(step));
    q.push(x);
    def[x] = 1;
    while(!q.empty()){
        ans = q.front();
        q.pop();
        if(ans == m){
            sum = step[ans];
            break;
        }
        for(re int i=1;i<=4;i++){
            store[i] = (ans/s[i])%10;
            for(re int j=0;j<=9;j++){
                t = ans-store[i]*s[i]+j*s[i];
                if(prim[t]==0&&t>1000&&!def[t]&&t<10000){
                    def[t] = 1;
                    step[t] = step[ans]+1;
                    //cout<<t<<" "<<step[t]<<endl;
                    q.push(t);
                }
            }
        }
    }
}

int main(){
    scanf("%d",&a);
    Esieve();
    while(a--){
        scanf("%d%d",&n,&m);
        bfs(n);
        clear(q);
        printf("%d\n",sum);
    }
    system("pause");
    return 0;
}
