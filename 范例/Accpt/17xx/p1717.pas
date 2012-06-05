PROGRAM p1717;

TYPE
        BigNum=array[0..500]of Byte;

VAR
        h,w                             :Integer;
        max                             :array[1..70,1..70]of BigNum;
        map                             :array[1..70,1..70]of Char;

PROCEDURE Readin;
var
        i,j                             :Integer;
begin
for i:=1 to w do
        begin
        for j:=1 to h do read(map[i][j]);
        readln;
        end;
end;

FUNCTION compare(var s,t:BigNum):Integer;
var
        i                               :Integer;
begin
if s[0]>t[0] then compare:=1 else
if s[0]<t[0] then compare:=-1
        else
        begin
        i:=1;
        while (i<s[0]) and (s[i]=t[i]) do inc(i);
        if s[i]>t[i] then compare:=1 else
        if s[i]=t[i] then compare:=0 else compare:=-1;
        if s[0]=0 then compare:=0;
        end;
end;

PROCEDURE print(var t:BigNum);
var
        i                               :Integer;
begin
if t[0]=0 then write(0) else
for i:=1 to t[0] do write(t[i]);
writeln;
end;

PROCEDURE Main;
var
        i,j                             :Integer;
        ans,zero                        :BigNum;

begin
ans[0]:=0;
zero[0]:=0;

for i:=1 to w do
        for j:=1 to h do
                if (map[i][j]>='0')and(map[i][j]<='9') then
                        begin
                        if map[i][j]='0' then
                                max[i][j][0]:=0
                                        else
                                begin
                                max[i][j][0]:=1;
                                max[i][j][1]:=ord(map[i][j]) - 48;
                                end;

                        if (i>1) and (compare(max[i-1][j],zero)>0) then
                                begin
                                inc(max[i-1][j][0]);
                                max[i-1][j][max[i-1][j][0]]:=ord(map[i][j])-48;
                                if compare(max[i-1][j],max[i][j])>0 then
                                        max[i][j]:=max[i-1][j];
                                dec(max[i-1][j][0]);
                                end;
                        if (j>1) and (compare(max[i][j-1],zero)>0) then
                                begin
                                inc(max[i][j-1][0]);
                                max[i][j-1][max[i][j-1][0]]:=ord(map[i][j])-48;
                                if compare(max[i][j-1],max[i][j])>0 then
                                        max[i][j]:=max[i][j-1];
                                dec(max[i][j-1][0]);
                                end;
                        if compare(max[i][j],ans)>0 then ans:=max[i][j];
                        end else max[i][j][0]:=0;


print(ans);
end;

BEGIN
//assign(input,'p.in');
//reset(input);
readln(h,w);
while (h<>0) do
        begin
        Readin;
        Main;
        readln(h,w);
        end;
END.
