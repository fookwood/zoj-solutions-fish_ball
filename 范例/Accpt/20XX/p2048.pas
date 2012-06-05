PROGRAM p2048;

TYPE
        position=record
                x,y                     :Integer;
                end;

VAR
        part,p                                  :Integer;
        total,n,m                               :Integer;
        whether,ans                             :array[1..750,1..750]of Boolean;
        data                                    :array[1..750]of Position;
        SetNum                                  :array[1..750]of Integer;
        dis                                     :array[1..750,1..750]of Real;
        left,right                              :array[1..750,1..750]of Integer;

PROCEDURE Readin;
var
        i,a,b                                   :Integer;
begin
readln(n);
for I:=1 to n do readln(data[i].x,data[i].y);
readln(m);
fillchar(whether,sizeof(whether),0);
for I:=1 to m do
        begin
        readln(a,b);
        whether[a,b]:=true;
        whether[b,a]:=true;
        end;
end;

PROCEDURE Main;
var
        i,j                                     :Integer;
        d                                       :Real;

        Procedure Search(p:Integer);
        var
                i                               :Integer;
        begin
        SetNum[p]:=Total;
        for i:=1 to n do
                if (SetNum[i]=0) and whether[p,i] then Search(i);
        end;

        Procedure Prim;
        var
                i,j,p                           :Integer;
                c                               :array[1..750]of Real;
                closet                          :array[1..750]of Integer;
                min                             :Real;
        begin
        for i:=2 to Total do
                begin
                c[i]:=dis[1,i];
                closet[i]:=1;
                end;
        c[1]:=-1;
        closet[1]:=0;
        for i:=2 to Total do
                begin
                min:=999999999;
                for j:=2 to Total do
                        if (c[j]>0)and(c[j]<min) then
                                begin
                                p:=j;
                                min:=c[j];
                                end;
                Ans[Left[closet[p],p],Right[closet[p],p]]:=true;
                Ans[Right[closet[p],p],Left[closet[p],p]]:=true;
                c[p]:=-1;
                for j:=2 to Total do
                        if (c[j]>0)and(dis[p,j]<c[j]) then
                                begin
                                c[j]:=dis[p,j];
                                closet[j]:=p;
                                end;
                end;
        end;

begin
Total:=0;
fillchar(SetNum,sizeof(SetNum),0);
fillchar(ans,sizeof(ans),0);
for i:=1 to n do
        if SetNum[i]=0 then
                begin
                inc(Total);
                Search(i);
                end;
for i:=1 to n do for j:=1 to n do Dis[i,j]:=999999999;
for i:=1 to n do
        for j:=1 to n do
        if SetNum[i]<>SetNum[j] then
                begin
                d:=Sqrt(Sqr(data[i].x-data[j].x)+Sqr(data[i].y-data[j].y));
                if d<dis[SetNum[i],SetNum[j]] then
                        begin
                        dis[SetNum[i],SetNum[j]]:=d;
                        dis[SetNum[j],SetNum[i]]:=d;
                        Left[SetNum[i],SetNum[j]]:=i;
                        Left[SetNUm[j],SetNum[i]]:=i;
                        Right[SetNum[i],SetNum[j]]:=j;
                        Right[SetNum[j],SetNum[i]]:=j;
                        end;
                end;

Prim;
for i:=1 to n-1 do
        for j:=i+1 to n do
        if Ans[i,j] then writeln(i,' ',j);
end;

BEGIN
readln(part);
for p:=1 to part do
        begin
        readln;
        readin;
        main;
        if p<part then writeln;
        end;
END.
