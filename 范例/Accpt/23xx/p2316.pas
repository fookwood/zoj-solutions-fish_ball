PROGRAM p2316;

VAR
        part,p                          :Integer;
        n,m,i,a,b                       :Longint;
        ans                             :Longint;
        d                               :array[1..10000]of Longint;

PROCEDURE Main;
var
        i                               :Integer;
begin
ans:=0;
for i:=1 to n do
        inc(ans,(d[i]-1) * d[i]);
inc(ans,m*2);
end;

BEGIN
readln(part);
for p:=1 to part do
        begin
        readln;
        fillchar(d,sizeof(d),0);
        readln(n,m);
        for i:=1 to m do
                begin
                readln(a,b);
                inc(d[a]);
                inc(d[b]);
                end;
        Main;
        writeln(ans);
        if P<part then writeln;
        end;
END.