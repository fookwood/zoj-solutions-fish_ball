#include <iostream>
#include <queue>
#include <string>
using namespace std;
int MAP[51][51];
int MAPWAY[51][51];
int VISIT[51][51][5];
// 1=north;2=east;3=south;0=west
struct node
{
    int x,y;
    int way;
    int step;
    /*string path;*/
};
//string tostring(int n)
//{
//    string t;
//    while(n>0)
//    {
//        t += n%10+'0';
//        n /= 10;
//    }
//    return t;
//}
int main()
{
    bool ff;
    int n,m,i,j,myway;
    node start,end,t,tt;
    queue<node> rer;
    string way;
    int fowardx,fowardy,tfx,tfy;
    while(cin >> n >> m)
    {
        if(n==0&&m==0)
            break;
        for(i=0;i<n;++i)
            for(j=0;j<m;++j)
                cin >> MAP[i][j];
        cin >> start.x >> start.y >> end.x >> end.y;
        cin >> way;
        memset(MAPWAY,0,sizeof(MAPWAY));
        memset(VISIT,250,sizeof(VISIT));
        for(i=0;i<n;++i)
            for(j=0;j<m;++j)
            {
                if(MAP[i][j]==1)
                {
                    MAPWAY[i][j] = 1;
                    if(i+1<=n)
                        MAPWAY[i+1][j] = 1;
                    if(j+1<=m)
                        MAPWAY[i][j+1] = 1;
                    if(i+1<=n&&j+1<=m)
                        MAPWAY[i+1][j+1] = 1;
                }
                VISIT[i][j][0] = VISIT[i][j][1] = VISIT[i][j][2] = VISIT[i][j][3] = 99999;
            }
        if(way=="north")
            myway = 1;
        else if(way=="east")
            myway = 2;
        else if(way=="south")
            myway = 3;
        else if(way=="west")
            myway = 0;
        start.way = myway;
        start.step = 0;
        ////
        //start.path = "begin\n";
        rer.push(start);
        ff = false;
        while(!rer.empty())
        {
            t = rer.front();
            rer.pop();
            if(t.x==end.x&&t.y==end.y)
            {
                ff = true;
                break;
            }
            if(t.step+1 < VISIT[t.x][t.y][(t.way+1)%4])
            {
                tt = t;
                tt.way = (tt.way+1)%4;
                tt.step++;
                /*tt.path += "turn a,foward:"+tostring(tt.way)+"\n";*/
                rer.push(tt);
                VISIT[tt.x][tt.y][tt.way] = tt.step;
            }
            if(t.step+1 < VISIT[t.x][t.y][(t.way+4-1)%4])
            {
                tt = t;
                tt.way = (tt.way+4-1)%4;
                tt.step++;
                /*tt.path += "turn b,foward:"+tostring(tt.way)+"\n";*/
                rer.push(tt);
                VISIT[tt.x][tt.y][tt.way] = tt.step;
            }
            if(t.way==0)
            {
                fowardx = 0;
                fowardy = -1;
            }
            else if(t.way==1)
            {
                fowardx = -1;
                fowardy = 0;
            }
            else if(t.way==2)
            {
                fowardx = 0;
                fowardy = 1;
            }
            else if(t.way==3)
            {
                fowardx = 1;
                fowardy = 0;
            }
            // foward 1
            tfx = t.x + fowardx;
            tfy = t.y + fowardy;
            if(MAPWAY[tfx][tfy]==1)
                continue;
            if(tfx>0&&tfx<n&&tfy>0&&tfy<m&&MAPWAY[tfx][tfy]==0&&t.step+1 < VISIT[tfx][tfy][t.way])
            {
                tt = t;
                tt.x = tfx;
                tt.y = tfy;
                tt.step++;
                /*tt.path += "foward 1(" + tostring(tt.x) + "," + tostring(tt.y) + ")\n";*/
                rer.push(tt);
                VISIT[tt.x][tt.y][tt.way] = tt.step;
            }
            // foward 2
            fowardx *= 2;
            fowardy *= 2;
            tfx = t.x + fowardx;
            tfy = t.y + fowardy;
            if(MAPWAY[tfx][tfy]==1)
                continue;
            if(tfx>0&&tfx<n&&tfy>0&&tfy<m&&MAPWAY[tfx][tfy]==0&&t.step+1 < VISIT[tfx][tfy][t.way])
            {
                tt = t;
                tt.x = tfx;
                tt.y = tfy;
                tt.step++;
                /*tt.path += "foward 2(" + tostring(tt.x) + "," + tostring(tt.y) + ")\n";*/
                rer.push(tt);
                VISIT[tt.x][tt.y][tt.way] = tt.step;
            }
            // foward 3
            fowardx = fowardx/2*3;
            fowardy = fowardy/2*3;
            tfx = t.x + fowardx;
            tfy = t.y + fowardy;
            if(MAPWAY[tfx][tfy]==1)
                continue;
            if(tfx>0&&tfx<n&&tfy>0&&tfy<m&&MAPWAY[tfx][tfy]==0&&t.step+1 < VISIT[tfx][tfy][t.way])
            {
                tt = t;
                tt.x = tfx;
                tt.y = tfy;
                tt.step++;
                /*tt.path += "foward 3(" + tostring(tt.x) + "," + tostring(tt.y) + ")\n";*/
                rer.push(tt);
                VISIT[tt.x][tt.y][tt.way] = tt.step;
            }
        }
        if(ff==true)
        {
            cout << t.step << endl;
            /*cout << t.path;*/
        }
        else
            cout << "-1" << endl;
        while(!rer.empty())
            rer.pop();
    }
    return 0;
}
