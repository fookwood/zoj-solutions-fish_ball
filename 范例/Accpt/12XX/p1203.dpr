program p1203;

{$APPTYPE CONSOLE}

var
        x,y     :array[1..100]of real;
        dis     :array[1..100,1..100]of real;
        team    :array[1..100]of boolean;
        n       :integer;
        i       :Integer;
        step    :Integer;
        ans     :real;


        
PROCEDURE makedis;
var
        i,j     :Integer;
begin
for I:=1 to n do
        for j:=1 to n do
        dis[i,j]:=sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j]));
end;

PROCEDURE prim;
var
        i,j,k   :integer;
        min     :real;
        point   :integer;
        gout    :integer;
begin
fillchar(team,sizeof(team),false);
team[1]:=true;
ans:=0;
for k:=1 to n-1 do
        begin
        min:=1e5;
        for I:=1 to n do
                if team[i] then
                begin
                for j:=1 to n do
                if (not team[j])and(dis[i,j]<min) then
                        begin
                        min:=dis[i,j];
                        gout:=i;
                        point:=j;
                        end;
                end;
        team[point]:=true;
        ans:=ans+dis[gout,point];
        end;
end;

begin
readln(n);
step:=0;
while N<>0 do
        begin
        inc(step);
        for I:=1 to n do readln(x[i],y[i]);
        makedis;
        prim;
        writeln('Case #',step,':');
        writeln('The minimal distance is: ',ans:0:2);
        readln(n);
        if n<>0 then writeln;
        end;
end.
