program p1601;

{$APPTYPE CONSOLE}

const
        max=1e8;

var
        goal    :extended;
        l       :longint;
        p       :longint;
        i       :longint;
        up,down :longint;
        mis     :extended;


FUNCTION access(down:longint;left,right:real):real;
var
        mid     :real;
begin
if right-left<=0.05 then access:=left else
        begin
        mid:=(left+right)/2;
        if mid/down<goal then access:=access(down,mid,right)
                else access:=access(down,left,mid);
        end;
end;



begin
while not eof do
        begin
        readln(goal);
        readln(l);
        //readin


        mis:=max;up:=0;down:=0;
        for i:=1 to l do
                begin
                p:=trunc(access(i,1,max));
                if abs((p+1)/i-goal)<abs(p/i-goal) then p:=p+1;
                if p>l then p:=l;
                if abs(p/i-goal)<mis then
                        begin
                        mis:=abs(p/i-goal);
                        up:=p;
                        down:=i;
                        end;
                end;
        writeln(up,' ',down);
        end;
end.
