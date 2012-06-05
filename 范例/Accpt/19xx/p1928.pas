PROGRAM p1928;

VAR
        a,b,c,d         :integer;
        ans             :longint;


BEGIN
readln(a,b,c,d);
while (a<>0)or(b<>0)or(c<>0)or(d<>0) do
        begin
        ans:=40*3;
        ans:=ans+(a-b+40)mod 40;
        ans:=ans+(c-b+40)mod 40;
        ans:=ans+(c-d+40)mod 40;
        writeln(ans*9);
        readln(a,b,c,d);
        end;
END.