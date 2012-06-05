program p1551;

{$APPTYPE CONSOLE}

type
        pos=record
                x,y             :longint;
        end;

var
        n,w,h           :integer;
        data            :array[1..200]of pos;
        i               :integer;



PROCEDURE small(d,e,a,b:longint;var c:longint);
var
        m               :longint;
begin
if a<b then m:=b else m:=a;
if m>d then m:=d;
if m>e then m:=e;
if m<c then c:=m;
end;

PROCEDURE main;
var
        i,j,k           :longint;
        px,py,ax,ay     :longint;
        ans,min         :longint;
begin
if n=0 then
        begin
        if h>w then writeln('0 0 ',w) else writeln('0 0 ',h);
        end
        else
        begin
        ans:=0;
        for i:=1 to n do
                for j:=1 to n do
                        begin
                        min:=maxlongint;
                        px:=data[i].x;
                        py:=data[j].y;
                        for k:=1 to n do
                                if (data[k].x>px)and(data[k].y>py) then
                                        begin
                                        small(w-px,h-py,data[k].x-px,data[k].y-py,min);
                                        end;
                        if (min>ans)and(min<maxlongint) then
                                begin
                                ans:=min;
                                ax:=px;
                                ay:=py;
                                end;
                        end;
        writeln(ax,' ',ay,' ',ans);
        end;
end;


BEGIN
while not eof do
        begin
        readln(n,w,h);
        for i:=1 to n do        readln(data[i].x,data[i].y);
        data[n+1].x:=0;data[n+1].y:=0;
        data[n+2].x:=w;data[n+2].y:=h;
        n:=n+2;
        main;
        end;
END.
