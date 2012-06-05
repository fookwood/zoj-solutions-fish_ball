PROGRAM p2185;

VAR
        n       :longInt;
        p       :longint;
        a,b     :longint;
        leave   :extended;
        c       :longint;
BEGIN
while not eof do
        begin
        readln(n);
        if trunc(sqrt(8*n+1))=sqrt(8*n+1)   then
                begin
                if trunc((sqrt(8*n+1)-1)/2) mod 2=0 then
                        begin
                        a:=trunc((sqrt(8*n+1)-1)/2);
                        b:=1;
                        end else
                        begin
                        a:=1;
                        b:=trunc((sqrt(8*n+1)-1)/2);
                        end;
                end else
                begin
                p:=trunc((sqrt(8*n+1)-1)/2);
                leave:=n-1.0*p*(p+1)/2;
                c:=trunc(leave);
                if p mod 2=1 then
                        begin
                        a:=c;
                        b:=p+2-c;
                        end else
                        begin
                        a:=p+2-c;
                        b:=c;
                        end;
                end;
        writeln('TERM ',n,' IS ',a,'/',b);
        end;
END.