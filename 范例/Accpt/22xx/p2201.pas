PROGRAM p2201;

VAR
        a,b     :integer;
        n       :integer;
        i       :integer;

BEGIN
readln(n);
for I:=1 to n do
        begin
        readln(a,b);
        if a<b then writeln('NO BRAINS') else writeln('MMM BRAINS');
        end;
END.