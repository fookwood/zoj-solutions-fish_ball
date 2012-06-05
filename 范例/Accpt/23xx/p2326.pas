PROGRAM p2326;

CONST
        maxn=1000;
        max=1e10;
        small=1e-7;

VAR
        n,m                     :Integer;
        name                    :array[1..maxn]of String;
        have                    :Extended;
        dis                     :array[1..maxn,1..maxn]of Extended;
        edge                    :array[1..maxn,0..maxn]of Integer;

FUNCTION Find(s:String):Integer;
var
        i                       :Integer;
begin
for i:=1 to n do
        if name[i]=s then
                begin
                find:=i;
                exit;
                end;
end;

PROCEDURE Readin;
var
        s,t                     :String;
        i,code,a,b              :Integer;
begin
readln(have);
readln(n);
for i:=1 to n do
        begin
        edge[i][0]:=0;
        readln(name[i]);
        end;
readln(m);
for i:=1 to m do
        begin
        readln(s);
        t:=copy(s,1,pos(' ',s)-1);
        a:=find(t);
        delete(s,1,pos(' ',s));
        t:=copy(s,1,pos(' ',s)-1);
        b:=find(t);
        delete(s,1,pos(' ',s));
        val(s,dis[a][b],code);
        dis[b][a]:=dis[a][b];
        inc(edge[a][0]);
        edge[a][edge[a][0]]:=b;
        inc(edge[b][0]);
        edge[b][edge[b][0]]:=a;
        end;
end;

PROCEDURE prim;
var

        mincost                         :array[1..maxn]of Extended;
        closet                          :array[1..maxn]of Integer;
        team                            :array[1..maxn]of Boolean;
        i,k                             :Integer;
        min,ans                         :Extended;
begin

{for i:=1 to n do
        begin
        for k:=1 to edge[i][0] do
                writeln(i,' ',edge[i][k],' ',dis[i][edge[i][k]]:0:3);
        writeln;
        end; }
ans:=0;

for i:=1 to n do mincost[i]:=max;
for i:=1 to edge[1][0] do
        begin
        mincost[edge[1][i]]:=dis[1][edge[1][i]];
        closet[edge[1][i]]:=1;
        end;

fillchar(team,sizeof(team),0);
team[1]:=true;
mincost[1]:=0;

repeat
        min:=max;
        k:=0;
        for i:=2 to n do
                if not team[i] and (mincost[i]<min) then
                        begin
                        min:=mincost[i];
                        k:=i;
                        end;

        if k<>0 then
                begin
                ans:=ans+min;
                team[k]:=true;
                for i:=1 to edge[k][0] do
                        if not team[edge[k][i]] and (dis[k][edge[k][i]]<mincost[edge[k][i]]) then
                                begin
                                mincost[edge[k][i]]:=dis[k][edge[k][i]];
                                closet[edge[k][i]]:=k;
                                end;
                end else break;
until false;
if ans<have+small then writeln('Need ',ans:0:1,' miles of cable')
        else writeln('Not enough cable');
end;

BEGIN
//assign(input,'p.in');
//reset(input);
while not eof do
        begin
        Readin;
        Prim;
        end;
END.