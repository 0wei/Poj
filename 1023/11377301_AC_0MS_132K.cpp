#include<iostream>
using namespace std;

__int64 N,M;
char s[100],res[100]={'\0'};
int main()
{
    int T;scanf("%d",&T);
    int i,j;
     __int64 _max,_min;
    char ch;
    while(T--)
     {
         scanf("%I64d",&N);
         scanf("%s",s);
         _max=0;_min=0;
        for(i=0;i<N;i++)                         //找出能表示的范围； 
         {
            if(s[i]=='p') _max=(_max<<1)+1,_min<<=1;
            else _min=(_min<<1)-1,_max<<=1;
         }
        
         scanf("%I64d",&M);
        if((M<_min&&_min<=0)||(M>_max&&_max>=0)) puts("Impossible");   //注意防止64位数的溢出； 
        else
         {
             memset(res,'\0',sizeof(res));
            for(i=N-1;i>=0;i--)                   
             {
                int flag=0;
                if(M&1)                                   //这里不能是平常的%2； 判断最后一位是否为1
                 {
                     res[i]='1';
                    if(s[i]=='n') flag=1;
                 }
                else res[i]='0';
                 M>>=1;
                if(flag) M++;                //如果是n就需其高位加1； 2^3 - 2^2 == 2^4 - 2^ 2;
             }
             printf("%s\n",res);
         }
        
     }

    return 0;
} 