PROGRAM p1347;

VAR
        d,i                                   :Integer;
        n,p,m,r,s                             :Extended;
        ans                                   :Longint;

BEGIN
readln(d);
for i:=1 to d do
        begin
        readln(n,p,m,r,s);
        ans:=round((p *n - p*m + (s +0.01 ) * m)/(p * m * 2));
        writeln('price = ',ans * p + p - 0.01:0:2);
        writeln('audiences = ',n - m * ans :0:0);
        writeln('revenue = ',(ans *  p + p - 0.01 -s) * (n-m*ans) - r:0:2);
        if i<d then writeln;
        end;
END.
