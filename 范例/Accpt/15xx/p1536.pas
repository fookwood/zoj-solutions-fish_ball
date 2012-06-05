PROGRAM p1536;

CONST
        lp=10000;
        change  :array[1..4,1..2]of Integer=
        ((1,0),(0,1),(-1,0),(0,-1));

TYPE
        BigNum=array[0..100]of Longint;

VAR
        n,k                     :Integer;
        map                     :array[1..20,1..20]of Char;
        ans                     :array[0..1,1..20,1..20]of BigNum;

PROCEDURE Readin;
var
        i,j                     :Integer;
begin
readln(n,k);
for I:=1 to n do
        begin
        for J:=1 to n do read(map[i][j]);
        readln;
        end;
end;

PROCEDURE Add(var s,t:BigNum);
var
        i,temp                  :Longint;
begin
for i:=s[0]+1 to t[0] do s[i]:=0;
for I:=1 to t[0] do s[i]:=s[i] + t[i];
if t[0]>s[0] then s[0]:=t[0];
temp:=0;
for I:=1 to s[0] do
        begin
        temp:=temp + s[i];
        s[i]:=temp mod lp;
        temp:=temp div lp;
        end;
while (temp>0) do
        begin
        inc(s[0]);
        s[s[0]]:=temp mod lp;
        temp:=temp div lp;
        end;
end;

PROCEDURE print(var t:BigNum);
var
        i,j                     :Integer;
begin
write(t[t[0]]);
for i:=t[0]-1 downto 1 do
        begin
        for J:=1 to 4-(trunc(ln(t[i])/ln(10))+1) do write('0');
        write(t[i]);
        end;
writeln;
end;

PROCEDURE main;
var
        d,i,j,w                 :Integer;
        a,b,p,q                 :Integer;
begin
if (k<n + n -2) or odd(k) or (map[1][1]='1') or (map[n][n]='1') then
        begin
        writeln(0);
        exit;
        end;

a:=0;
b:=1;
fillchar(ans,sizeof(ans),0);

ans[a][1][1][1]:=1;
ans[a][1][1][0]:=1;
        // edge information

for d:=1 to k do
        begin
        for i:=1 to n do
                for J:=1 to n do
                        if map[i][j]='1' then
                                begin
                                ans[b][i][j][0]:=1;
                                ans[b][i][j][1]:=0;
                                end else
                                begin
                                ans[b][i][j][0]:=0;
                                ans[b][i][j][1]:=0;
                                for w:=1 to 4 do
                                        begin
                                        p:=i + change[w][1];
                                        q:=j + change[w][2];

                                        if (p<1)or(p>n)or(q<1)or(q>n) then continue;
                                        Add(ans[b][i][j],ans[a][p][q]);
                                        end;
                                end;
        a:=1-a;
        b:=1-b;
        end;

print(ans[a][n][n]);
end;

BEGIN
//assign(input,'p.in');
//reset(input);
while not eof do
        begin
        Readin;
        Main;
        end;
END.