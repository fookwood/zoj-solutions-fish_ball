PROGRAM p2109;

CONST
        max=1e10;
        small=1e-8;

TYPE
        Node=record
                a,b                     :Integer;
                order                   :Extended;
        end;

VAR
        ans                             :Extended;
        n,m                             :Integer;
        food                            :array[1..1000]of Node;

PROCEDURE Readin;
var
        i                               :Integer;
begin
for i:=1 to m do
        begin
        readln(food[i].a,food[i].b);
        if food[i].b=0 then food[i].order:=max else food[i].order:=food[i].a/food[i].b;
        end;
end;

FUNCTION Find(left,right:Integer;key:Extended):integer;
var
        temp                            :Node;
        i,j                             :Integer;
begin
i:=left-1;
j:=right+1;
repeat
        repeat dec(j) until food[j].order<key+small;
        repeat inc(i) until food[i].order>key-small;
        if (i<j) then
                begin
                temp:=food[i];
                food[i]:=food[j];
                food[j]:=temp;
                end else break;
until false;
find:=j;
end;

PROCEDURE Sort(left,right:Integer);
var
        mid                             :Integer;
begin
mid:=find(left,right,food[left].order);
if mid>left then Sort(left,mid);
if mid+1<right then Sort(mid+1,right);
end;

PROCEDURE Main;
var
        i                               :Integer;
begin
ans:=0;
i:=m;
while (i>=1)and((n>=food[i].b)or(n>0)) do
        begin
        if n>=food[i].b then
                begin
                ans:=ans+food[i].a;
                n:=n - food[i].b;
                end else
                begin
                ans:=ans + food[i].a * n / food[i].b;
                n:=0;
                end;
        dec(i);
        end;
writeln(round(ans*1000)/1000:0:3);
end;

BEGIN
//assign(input,'p.in');
//reset(input);
readln(n,m);
while (n>-1)and(m>-1) do
        begin
        Readin;
        if m>0 then sort(1,m);
        main;
        readln(n,m);
        end;
END.