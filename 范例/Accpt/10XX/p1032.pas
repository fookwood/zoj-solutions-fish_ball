PROGRAM p1032;

TYPE
        NodeType=record
        x,y                             :Longint;
        end;

VAR
        n,part,p                        :Longint;
        ans                             :Longint;
        data                            :array[0..102]of NodeType;

FUNCTION Gcd(a,b:Longint):Longint;
var
        i,temp                          :Longint;
begin
if a>b then
        begin
        temp:=a;
        a:=b;
        b:=temp;
        end;
temp:=1;
for i:=1 to a-1 do
        if (b*i) mod a=0 then inc(temp);
gcd:=temp;
end;

FUNCTION Many_of_gcd(g:Longint):Longint;
var
        i,t,p,j                         :Longint;
begin
t:=1;
p:=2;
while (p<=g) do
        if g mod p=0 then
                begin
                j:=1;
                while (g mod p=0) do
                        begin
                        inc(j);
                        g:=g div p;
                        end;
                t:=t*j;
                inc(p);
                end else inc(p);
Many_of_gcd:=t;
end;


PROCEDURE Readin;
var
        i,a,b,g                         :Longint;
begin
readln(n);
ans:=0;
data[0].x:=0;
data[0].y:=0;
for i:=1 to n do
        begin
        readln(a,b);
        data[i].x:=data[i-1].x+a;
        data[i].y:=data[i-1].y+b;

        if (a=0) then
                begin
                inc(ans,abs(b));
                continue;
                end;
        if (b=0) then
                begin
                inc(ans,abs(a));
                continue;
                end;

        g:=gcd(abs(a),abs(b));
        inc(ans,g);
        end;
end;

PROCEDURE Main;
var
        i,ans_a                                 :Longint;
        area                                    :Extended;
begin
area:=0;
data[n+1]:=data[1];
for i:=1 to n do
        area:=area + data[i].x * data[i+1].y - data[i].y * data[i+1].x;

area:=abs(area) / 2;

ans_a:=trunc(area+1 - ans / 2);
if ans_a<>round(area+1-ans/2) then while true do ;

writeln('Scenario #',p,':');
writeln(ans_a,' ',ans,' ',area:0:1);
end;

BEGIN
assign(input,'p.in');
reset(input);
readln(part);
for p:=1 to part do
        begin
        Readin;
        main;
        writeln;
        end;
END.
