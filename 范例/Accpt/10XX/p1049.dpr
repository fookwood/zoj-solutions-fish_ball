program P1049;

{$APPTYPE CONSOLE}


var
        team    :longint;
        i       :longint;
        x,y     :real;
        r       :real;
        area    :real;
        ans     :longint;

begin
readln(team);
for i:=1 to team do
        begin
        readln(x,y);
        r:=sqr(x)+sqr(y);
        area:=3.1415926*r/2;
        ans:=trunc(area/50)+1;
        writeln('Property ',i,': This property will begin eroding in year ',ans,'.') 
        end;
writeln('END OF OUTPUT.');
end.
 