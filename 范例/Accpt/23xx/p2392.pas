PROGRAM p2392;

TYPE
        AnsType =array[0..9]of Qword;

VAR
        order,part                      :array[0..10]of Longint;

PROCEDURE Print(var t:AnsType);
var
        i                               :Integer;
begin
for i:=0 to 9 do
        begin
        write(t[i]);
        if I<9 then write(' ');
        end;
writeln;
end;

FUNCTION Long(n:Longint):Integer;
begin
long:=trunc(ln(n)/ln(10))+1;
end;

PROCEDURE Add(var a,b:AnsType);
var
        i                               :Integer;
begin
for i:=0 to 9 do a[i]:=a[i] + b[i];
end;

FUNCTION f(n:Longint):AnsType;
var
        l,p,first,i                     :Integer;
        fa,a,b                          :AnsType;
begin
if n=0 then
        begin
        fillchar(fa,sizeof(fa),0);
        f:=fa;
        exit;
        end;      //arim

l:=long(n);
first:=n div order[l];

a:=f(order[l]-1);
fa:=a;

p:=l-1;
while (p>0)and(n div order[p] mod 10=0) do dec(p);

if (p<>0) then
        begin
        fa[0]:=fa[0]+(n mod order[p+1]) * (l-p-1);
        fa[first]:=fa[first]+(n mod order[p+1]);
        b:=f(n mod order[p+1]);
        Add(fa,b);
        fa[0]:=fa[0]+part[p];
        end;

a[0]:=a[0]+part[l-1];

for i:=1 to first-1 do
        fa[i]:=fa[i]+order[l];
fa[first]:=fa[first]+1;
fa[0]:=fa[0]+(l-1)*first;
for i:=1 to first-1 do add(fa,a);
f:=fa;
end;

PROCEDURE MakeOrderAndPart;
var
        i                               :Integer;
begin
order[0]:=1;
part[0]:=0;
order[1]:=1;
part[1]:=0;
for i:=2 to 10 do
        begin
        order[i]:=order[i-1]*10;
        part[i]:=part[i-1] + order[i]-1;
        end;
end;

PROCEDURE main;
var
        temp1,temp2                     :AnsType;
        a,b,i,temp                      :Longint;
begin
while true do
        begin
        readln(a,b);
        if (a=0)and(b=0) then break;
        if a>b then
                begin
                temp:=a;
                a:=b;
                b:=temp;
                end;
        temp1:=f(a-1);
        temp2:=f(b);
        for i:=0 to 9 do temp2[i]:=temp2[i]-temp1[i];
        print(temp2);
        end;
end;

BEGIN
//assign(input,'p.in');
//reset(input);
MakeOrderAndPart;
main;
END.
