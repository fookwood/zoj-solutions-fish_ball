PROGRAM p2256;

VAR
        n       :longint;

        money   :real;

BEGIN
readln(n);
while n<>0 do
        begin
        money:=0;
        while (n>=13) do
                                begin
                                money:=money+18;
                                n:=n-8;
                                end;

        if n<=4 then writeln(10) else
                begin
                n:=n-4;
                money:=money+10;
                if n<=4 then writeln(money+2*n:0:0)
                else
                        begin
                        n:=n-4;
                        money:=money+8;
                        money:=money+2.4*n;
                        if trunc(money)=money then writeln(money:0:0) else writeln(money:0:1);
                        end;
                end;
        readln(n);
        end;
END.

