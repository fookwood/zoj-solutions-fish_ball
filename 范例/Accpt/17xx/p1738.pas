PROGRAM p1738;

CONST
        max=32768;

VAR
        n                       :Longint;
        sum                     :array[0..32768]of Longint;

PROCEDURE MakeAns;
var
        i,j,k,p,d,l            :Longint;
begin
fillchar(sum,sizeof(sum),0);
d:=trunc(sqrt(max));
for I:=0 to d do
        for j:=i to d do
                begin
                p:=sqr(i)+sqr(j);
                if p>max then break;
                for k:=j to d do
                        begin
                        p:=p+sqr(k);
                        if p>max then
                                begin
                                p:=p-sqr(k);
                                break;
                                end;
                        for l:=k to d do
                                begin
                                p:=p+sqr(l);
                                if p>max then
                                        begin
                                        p:=p-sqr(l);
                                        break;
                                        end;
                                inc(sum[p]);
                                p:=p-sqr(l);
                                end;
                        p:=p-sqr(k);
                        end;
                end;
end;

BEGIN
MakeAns;
readln(n);
while n<>0 do
        begin
        writeln(sum[n]);
        readln(n);
        end;
END.