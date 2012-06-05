PROGRAM p1234;

VAR
        part,p,n,i,k                    :Integer;
        sum                             :Longint;
        num                             :array[0..5000]of Longint;
        min                             :array[0..1000,0..5000]of Longint;

PROCEDURE Main;
var
        i,j,p,d                             :Longint;
begin
fillchar(min,sizeof(min),0);
for i:=1 to k do
        for j:=n-3 * i+1 downto 1 do
                if (n-j-3*i+1>0) then
                        begin
                        min[i,j]:=min[i,j+1];
                        if min[i-1,j+2]+sqr(num[j+1]-num[j])<min[i,j] then
                        min[i,j]:=min[i-1,j+2]+sqr(num[j+1]-num[j]);
                        end else
                if (n-j-3*i+1=0) then
                        min[i,j]:=min[i-1][j+2]+sqr(num[j]-num[j+1]);
writeln(min[k,1]);
end;

BEGIN
readln(part);
for p:=1 to part do
        begin
        readln(k,n);
        inc(k,8);
        for i:=1 to n do read(num[i]);
        Main;
        end;
END.