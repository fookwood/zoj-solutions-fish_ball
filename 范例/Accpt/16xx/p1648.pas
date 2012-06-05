PROGRAM p1648;


TYPE
        node=record
                x1,y1,x2,y2             :Real;
        end;

VAR
        flag                    :Boolean;
        n,i,j                   :Integer;
        map                     :array[1..2000]of Node;



FUNCTION mul(x1,y1,x2,y2:Real):Integer;
begin
if x1*y2-x2*y1>0 then mul:=1 else
if x1*y2-x2*y1=0 then mul:=0 else
mul:=-1;
end;

FUNCTION Cross(var p,q:Node):Boolean;
var
        fu                      :Integer;
begin
cross:=true;
fu:=mul(p.x1-q.x1,p.y1-q.y1,p.x2-q.x1,p.y2-q.y1);
fu:=mul(p.x1-q.x2,p.y1-q.y2,p.x2-q.x2,p.y2-q.y2) * fu;
if fu>=0 then
        begin
        cross:=false;
        exit;
        end;
fu:=mul(q.x1-p.x1,q.y1-p.y1,q.x2-p.x1,q.y2-p.y1);
fu:=mul(q.x1-p.x2,q.y1-p.y2,q.x2-p.x2,q.y2-p.y2) * fu;
if fu>=0 then
        begin
        cross:=false;
        exit;
        end;
end;


BEGIN
while not eof do
        begin
        readln(n);
        flag:=true;
        for i:=1 to n do
                begin
                with map[i] do readln(x1,y1,x2,y2);
                if flag then
                        for j:=1 to i-1 do
                                if cross(map[i],map[j]) then
                                        begin
                                        flag:=false;
                                        break;
                                        end;
                end;
        if flag then writeln('ok!') else writeln('burned!');
        if not eof  then readln;
        end;
END.