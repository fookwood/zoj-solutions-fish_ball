PROGRAM p1937;

VAR
        n                       :Integer;
        ans                     :array[1..100,0..100]of Integer;
        temp                    :array[1..100]of Integer;

PROCEDURE Search(long,point:Integer);
var
        i                       :Integer;
begin
if long<ans[point][0] then
        begin
        for i:=1 to long do ans[point][i]:=temp[i];
        ans[point][0]:=long;
        end;

if long=ans[point][0] then
        begin
        for i:=long downto 1 do
                begin
                temp[long+1]:=point+temp[i];
                if (temp[long+1]>100)or(long=100) then continue
                        else Search(long+1,temp[long+1]);
                end;
        end;
end;

PROCEDURE MakeAns;
var
        i,j                     :Integer;
begin
for i:=1 to 100 do
        begin
        ans[i][0]:=i;
        for j:=1 to i do ans[i][j]:=j;
        end;

temp[1]:=1;
Search(1,1);
end;

PROCEDURE Print;
var
        i                       :Integer;
begin
write(ans[n][1]);
for i:=2 to ans[n][0] do write(' ',ans[n][i]);
writeln;
end;

BEGIN
MakeAns;
readln(n);
while (n>0) do
        begin
        print;
        readln(n);
        end;
END.