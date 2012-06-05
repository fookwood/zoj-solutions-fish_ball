PROGRAM p1900;

VAR
        p,t                             :Integer;
        whether                         :array[1..100,1..100]of Boolean;

PROCEDURE readin;
var
        a,b                             :Integer;
begin
readln(p,t);
fillchar(whether,sizeof(whether),0);
while not eoln do
        begin
        readln(a,b);
        whether[a][b]:=true;
        end;
end;

PROCEDURE Main;
var
        i,j,total                       :Integer;

        Function Equal:Boolean;
        var
                k                       :Integer;
        begin
        Equal:=false;
        for k:=1 to p do
                if whether[i][k]<>whether[j][k] then exit;
        Equal:=true;
        end;

begin
total:=1;
for i:=2 to p do
        begin
        inc(total);
        for j:=1 to i-1 do
                if equal then
                        begin
                        dec(total);
                        break;
                        end;
        end;
writeln(total);
end;

BEGIN
//assign(input,'p.in');
//reset(input);
while not eof do
        begin
        Readin;
        Main;
        while not eof and eoln do readln;
        end;
END.