program p1168;

{$APPTYPE CONSOLE}
var
        w       :array[1..20,1..20,1..20]of longint;
        a,b,c   :Longint;
        whether :array[1..20,1..20,1..20]of boolean;

FUNCTION want(a,b,c:Longint):longint;
begin
if (a<=0)or(b<=0)or(c<=0) then
        begin
        want:=1;
        exit;
        end;
if (a>20)or(b>20)or(c>20) then want:=want(20,20,20)
        else
        begin
        if whether[a,b,c] then
                begin
                want:=w[a,b,c];
                end else
                begin
                if (a<b)and(b<c) then
                        begin
                        w[a,b,c]:=want(a, b, c-1)+want(a, b-1, c-1)-want(a, b-1, c);
                        whether[a,b,c]:=true;
                        want:=w[a,b,c];
                        end else
                        begin
                        w[a,b,c]:=want(a-1, b, c)+want(a-1, b-1, c)+want(a-1, b, c-1)-want(a-1, b-1, c-1);
                        whether[a,b,c]:=true;
                        want:=w[a,b,c];
                        end;
                end;
        end;
end;


begin
fillchar(whether,sizeof(whether),false);
readln(a,b,c);
while (a<>-1)or(b<>-1)or(c<>-1) do
        begin
        writeln('w(',a,', ',b,', ',c,') = ',want(a,b,c));
        readln(a,b,c);
        end;
end.
