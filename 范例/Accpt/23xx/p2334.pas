PROGRAM p2334;

CONST
        maxn=1000000;

TYPE
        Point= Longint;
        pointtype=record
                father,leftchild,rightsub,setfather     :Point;
                degree,power                            :Longint;
        end;

VAR
        step                            :Integer;
        n,m                             :Longint;
        data                            :array[1..maxn]of Pointtype;

PROCEDURE MakeNull;
var
        i                               :Longint;
begin
readln(n);
for i:=1 to n do
        with data[i] do
                begin
                father:=0;
                leftchild:=0;
                rightsub:=0;
                setfather:=0;
                degree:=0;
                readln(power);
                end;
end;

FUNCTION maxmember(a:point):Point;
var
        max                             :Longint;
        p                               :Point;
begin
max:=-maxn;
repeat
        if data[a].power>max then
                begin
                max:=data[a].power;
                p:=a;
                end;
        if data[a].rightsub<>0 then a:=data[a].rightsub else break;
until false;
maxmember:=p;
end;

FUNCTION Find(p:point):point;
var
        d,temp                          :Point;
begin
d:=p;
while (data[p].setfather<>0) do p:=data[p].Setfather;
while (d<>p) do
        begin
        temp:=data[d].Setfather;
        data[d].Setfather:=p;
        d:=temp;
        end;
Find:=p;
end;

PROCEDURE Link(p,q:Point);
begin
data[p].father:=q;
data[p].rightsub:=data[q].leftchild;
data[q].leftchild:=p;
data[q].degree:=data[p].degree+1;
end;

FUNCTION Merge(a,b:Point):point;
var
        p                               :Point;
begin
if data[a].degree>=data[b].degree then
        begin
        p:=b;
        b:=data[b].rightsub;
        end else
        begin
        p:=a;
        a:=data[a].rightsub;
        end;

Merge:=p;

while (a<>0)and(b<>0) do
        begin
        if data[a].degree>=data[b].degree then
                begin
                data[p].rightsub:=b;
                p:=b;
                b:=data[b].rightsub;
                end else
                begin
                data[p].rightsub:=a;
                p:=a;
                a:=data[a].rightsub;
                end;
        end;
if a<>0 then data[p].rightsub:=a;
if b<>0 then data[p].rightsub:=b;
end;

FUNCTION Union(a,b:Point):Point;
var
        h,p,prev,next                   :Point;
begin
h:=Merge(a,b);
p:=h;
prev:=0;
next:=data[p].rightsub;
while next<>0 do
        begin
        if (data[p].degree<>data[next].degree) or
                ((data[next].rightsub<>0)and(data[data[next].rightsub].degree=data[p].degree)) then
                        begin
                        prev:=p;
                        p:=next;
                        end
                else if data[p].power>=data[next].power then
                        begin
                        data[p].rightsub:=data[next].rightsub;
                        link(next,p);
                        end
                else
                        begin
                        if prev=0 then h:=next
                                else data[prev].rightsub:=next;
                        link(p,next);
                        p:=next;
                        end;
        next:=data[p].rightsub;
        end;
Union:=h;
data[a].setfather:=h;
data[b].setfather:=h;
data[h].setfather:=0;
end;

PROCEDURE Make(p:Point);
var
        temp                            :Longint;
        max,q,tp                        :Point;
begin
if p=0 then exit;
max:=-maxn;
tp:=data[p].leftchild;
q:=0;
while tp<>0 do
        begin
        if data[tp].power>max then
                begin
                max:=data[tp].power;
                q:=tp;
                end;
        tp:=data[tp].rightsub;
        end;
if (q<>0) and (data[p].power<data[q].power) then
        begin
        temp:=data[p].power;
        data[p].power:=data[q].power;
        data[q].power:=temp;
        Make(q);
        end;
end;

PROCEDURE Main;
var
        i,a,b,p,q,fa,fb,j              :Longint;
begin
readln(m);
for i:=1 to m do
        begin
        readln(a,b);
        fa:=find(a);
        fb:=find(b);
        if fa<>fb then
                begin
                p:=maxmember(fa);
                q:=maxmember(fb);
                data[p].power:=data[p].power div 2;
                data[q].power:=data[q].power div 2;
                make(p);
                make(q);
                writeln(data[maxmember(Union(fa,fb))].power);
                end else writeln(-1);
        end;
end;

BEGIN
//assign(input,'p.in');
//reset(input);
step:=0;
while not eof do
        begin
        inc(step);
        MakeNull;
        Main;
        end;
END.