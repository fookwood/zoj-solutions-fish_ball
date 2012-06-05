PROGRAM p1196;

CONST
        maxlongint=999999;

VAR
        n,k,i,step                      :Integer;
        num                             :array[0..301]of Longint;
        min                             :array[0..31,0..301]of Longint;
        dis                             :array[0..301,0..301]of Longint;

PROCEDURE Main;
var
        i,j,p                           :Integer;
        sum,ans                         :Longint;
begin
num[0]:=-maxlongint;
num[n+1]:=maxlongint;
for i:=1 to n+1 do min[0,i]:=maxlongint;
min[0,0]:=0;
for i:=0 to n do
        for j:=i+1 to n+1 do
                begin
                dis[i,j]:=0;
                for p:=i+1 to j-1 do
                        if abs(num[p]-num[i])>abs(num[j]-num[p]) then inc(dis[i,j],abs(num[j]-num[p]))
                                else inc(dis[i,j],abs(num[p]-num[i]));
                end;

for i:=1 to k do
        for j:=1 to n+1 do
                begin
                if i=j then
                        begin
                        min[i,j]:=0;
                        continue;
                        end;
                min[i,j]:=maxlongint;
                for p:=j-1 downto 0 do
                        begin
                        sum:=0;
                        sum:=dis[p,j];
                        if min[i-1,p]+sum<min[i,j] then min[i,j]:=min[i-1,p]+sum;
                        end;
                end;

ans:=maxlongint;
for i:=n downto 1 do
        begin
        sum:=0;
        for j:=i+1 to n do inc(sum,abs(num[j]-num[i]));
        if sum+min[k,i]<ans then ans:=min[k,i]+sum;
        end;
writeln('Chain ',step);
write('Total distance sum = ');
writeln(ans);
writeln;
end;

BEGIN
step:=0;
while true do
        begin
        inc(step);
        readln(n,k);
        if (n=0)and(k=0) then break;
        for i:=1 to n do readln(num[i]);
        Main;
        end;
END.