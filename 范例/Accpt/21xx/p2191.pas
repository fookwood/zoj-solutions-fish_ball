PROGRAM p2191;

VAR
        a,b,c                           :Real;
        n1,n2,n3                  :Longint;

BEGIN
while not eof do
        begin
        readln(n1,n2,n3);
        c:=n1;
        a:=(n3+n1)/2-n2;
        b:=n2-n1-a;
        writeln(trunc(9*a+3*b+c),' ',trunc(16*a+4*b+c),' ',trunc(25*a+5*b+c));
        end;
END.