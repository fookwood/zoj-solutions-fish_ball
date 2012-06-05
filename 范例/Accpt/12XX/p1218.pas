PROGRAM p1218;

VAR
        a,b,i,t                         :Longint;
        min                             :Extended;

FUNCTION Back(x:Longint):Longint;
var
        t                               :Extended;
begin
t:=x*a/b;
Back:=round(t);
if round(t)=0 then Back:=1;
end;


BEGIN
while not eof do
        begin
        readln(a,b);
        i:=2;
        t:=Back(1);
        min:=abs(a/b-t);
        writeln(t,'/',1);
        while (i<=b) do
                begin
                t:=Back(i);
                if abs(a/b-t/i)<min then
                        begin
                        writeln(t,'/',i);
                        min:=abs(a/b-t/i);
                        end;
                inc(i);
                end;
        if not eof then writeln;
        end;
END.