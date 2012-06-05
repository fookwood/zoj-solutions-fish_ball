PROGRAM p2136;

VAR
        n,i                             :Integer;
        part,p                          :Integer;
        num,long,c                      :array[0..1000]of Integer;

FUNCTION find(l,r,goal:Integer):Integer;
var
        mid                             :Integer;
begin
while l<r do
        begin
        mid:=(l+r) div 2;
        if mid=l then break;
        if c[mid]<goal then l:=mid else r:=mid-1;
        end;
if c[l+1]>=goal then
find:=l else find:=l+1;
end;

PROCEDURE Main;
var
        i,p                             :Integer;
        max                             :Integer;
begin
fillchar(long,sizeof(long),0);
for i:=1 to n do c[i]:=maxint;
max:=0;
c[0]:=-1;
for i:=1 to n do
        begin
        p:=find(0,n,num[i]);
        long[i]:=p+1;
        if c[p+1]>num[i] then c[p+1]:=num[i];
        if long[i]>max then max:=long[i];
        end;
writeln(max);
end;

BEGIN
readln(part);
for p:=1 to part do
        begin
        readln;
        readln(n);
        for i:=1 to n do read(num[i]);readln;
        Main;
        if p<part then writeln;
        end;
END.