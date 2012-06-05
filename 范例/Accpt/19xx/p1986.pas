PROGRAM p1986;

VAR
        n,p,part,i              :Word;
        data,c                  :array[0..40000]of Word;

FUNCTION Find(l,r,goal:Word):Word;
var
        mid                     :Word;
begin
while l<r do
        begin
        mid:=(l+r) div 2;
        if c[mid]<goal then l:=mid+1 else r:=mid-1;
        end;
if c[l]<goal then Find:=l else Find:=l-1;
end;

PROCEDURE Main;
var
        i,j                     :Word;
        max                     :Word;
begin
for i:=1 to n do c[i]:=65535;
c[0]:=0;
max:=0;
for i:=1 to n do
        begin
        j:=Find(0,n,data[i]);
        if c[j+1]>data[i] then c[j+1]:=data[i];
        if j+1>max then max:=j+1;
        end;
writeln(max);
end;

BEGIN
//assign(input,'p.in');
//reset(input);
readln(part);
for p:=1 to part  do
        begin
        readln(n);
        for i:=1 to n do readln(data[i]);
        Main;
        end;
END.