PROGRAM p1456;

VAR
        n,a,b,i                         :Integer;
        edge,mincost,last               :array[1..100,1..100]of Longint;
        point                           :array[1..100]of Longint;
        havedone                        :array[1..100]of Boolean;

PROCEDURE Readin;
var
        i,j                             :Integer;
begin
readln(n);
if n=0 then halt;
for i:=1 to n do
        begin
        for j:=1 to n do read(edge[i][j]);
        readln;
        end;
for I:=1 to n do read(point[i]);
readln;

fillchar(havedone,sizeof(havedone),0);

end;

PROCEDURE Kfs(p:Integer);
var
        min                                     :Longint;
        i,j,k                                   :Integer;
        team                                    :array[1..100]of Boolean;
begin
for i:=1 to n do
        begin
        mincost[p][i]:=maxlongint;
        last[p][i]:=p;
        end;
mincost[p][p]:=0;

fillchar(team,sizeof(team),0);

repeat
        min:=maxlongint;
        for i:=1 to n do
                if not team[i] and (mincost[p][i]<min) then
                        begin
                        min:=mincost[p][i];
                        k:=i;
                        end;

        if min<maxlongint then
                begin
                team[k]:=true;
                for i:=1 to n do
                        if not team[i] and (edge[k][i]>0) and (mincost[p][k] + point[k] + edge[k][i]<mincost[p][i]) then
                                begin
                                mincost[p][i]:=mincost[p][k] + point[k] + edge[k][i];
                                last[p][i]:=k;
                                end;
                end else break;
until false;
end;

PROCEDURE Print(a,b:Integer);
var
        i                       :Integer;
begin
if b=a then write(a) else
        begin
        for i:=1 to n do
                if (i<>a) and (point[a]+edge[a][i]+mincost[i][b]=mincost[a][b]) then
                        begin
                        write(a,'-->');
                        print(i,b);
                        exit;
                        end;
        end;
end;

BEGIN
//assign(input,'p.in');
//reset(input);
//assign(output,'p.out');
//rewrite(output);
while true do
        begin
        Readin;
        readln(a,b);
        for i:=1 to n do kfs(i);

        while (a<>-1)  do
                begin
                writeln('From ',a,' to ',b,' :');
                write('Path: ');
                print(a,b);
                writeln;
                write('Total cost : ');
                if mincost[a][b]<point[a] then writeln(0) else writeln(mincost[a][b]-point[a]);
                readln(a,b);
                writeln;
                end;
        end;
//close(output);
END.
