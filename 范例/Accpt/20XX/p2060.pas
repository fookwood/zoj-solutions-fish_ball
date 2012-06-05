PROGRAM p2060;

VAR
        n       :longInt;

BEGIN
while not eof do
        begin
        readln(n);
        if n<1 then writeln('no') else
                begin
                if (n mod 8=2)or(n mod 8=6)then writeln('yes') else writeln('no');
                end;
        end;
END.
