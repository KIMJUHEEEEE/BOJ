#include <iostream>
#include <vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;


int main()
{
    int arr[101][101]={0,};
    bool cparr[101]={0,};
    int cp=0;
    cin>>cp;
    int n=0;
    cin>>n;
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++)
    {
        int f=0;
        int s=0;
        cin>>f>>s;
        arr[f][s]=1;
        arr[s][f]=1;

    }
    int cnt=0;
    cparr[1]=1;
        for(int j=1;j<=cp;j++)
        {
            if(arr[1][j]==1)
            {
                q.push(pair<int,int>(1,j));
                arr[1][j]=0;
                arr[j][1]=0;
                cparr[j]=1;
            }
        }
        while(q.size()!=0)
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=1;i<=cp;i++)
            {
                if(arr[y][i]==1)
                {
                    q.push(pair<int,int>(y,i));
                    arr[y][i]=0;
                    arr[i][y]=0;
                    cparr[y]=1;
                    cparr[i]=1;
                }
            }
        }
    for(int i=1;i<=cp;i++)
    {
        if(cparr[i]==1)
        {
            cnt++;
        }
    }
    cout<<cnt-1;
    return 0;
}