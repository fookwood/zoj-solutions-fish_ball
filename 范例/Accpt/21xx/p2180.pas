PROGRAM p2180;

CONST
        maxn=1000;

VAR
        map                             :array[1..maxn,1..maxn]of Boolean;
        up,down                         :array[1..maxn,1..maxn]of Integer;
        lup,ldown                       :Longint;
        ans,n,m,part,start              :Longint;

PROCEDURE Readin;
var
        ch                              :Char;
        i,j                             :Integer;
begin
readln(n,m);
for i:=1 to n do
        begin
        for j:=1 to m do
                begin
                if j>1 then read(ch);
                read(ch);
                if ch='F' then map[i][j]:=true
                        else map[i][j]:=false;
                end;
        readln;
        end;
end;

PROCEDURE Main;
var
        i,j                             :Integer;
begin
ans:=0;

for i:=1 to m do
        begin
        if map[1][i] then up[1][i]:=1 else up[1][i]:=0;
        if map[n][i] then down[n][i]:=1 else down[n][i]:=0;
        end;

for i:=2 to n do
        for j:=1 to m do
                begin
                if map[i][j] then up[i][j]:=up[i-1][j]+1
                        else up[i][j]:=0;
                if map[n-i+1][j] then down[n-i+1][j]:=down[n-i+2][j]+1
                        else down[n-i+1][j]:=0;
                end;

for i:=1 to n do
        begin
        lup:=0;
        ldown:=0;
        for j:=1 to m do
                begin
                if Lup=0 then
                        begin
                        Lup:=up[i][j];
                        Ldown:=down[i][j];
                        start:=j;
                        end else
                        begin
                        if up[i][j]<Lup then Lup:=up[i][j];
                        if down[i][j]<Ldown then Ldown:=down[i][j];
                        end;
                if (Lup+Ldown-1) * (j-start+1) >ans then
                        ans:=(Lup+Ldown-1) * (j-start+1);
                end;
        end;
writeln(ans*3);
end;

BEGIN
//assign(input,'p.in');
//reset(input);
readln(part);
for part:=part downto 1 do
        begin
        Readin;
        Main;
        end;
END.