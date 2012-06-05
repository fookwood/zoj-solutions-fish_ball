program p1745;

{$APPTYPE CONSOLE}

var
        a,b,goal        :longint;
        

begin
read(goal);
while goal<>5280 do
        begin
        a:=0;
        while not eoln do
                begin
                read(b);
                if b=goal then
                        writeln('Moving from ',a,' to ' ,b,': found it!') else
                if abs(a-goal)=abs(b-goal) then
                        writeln('Moving from ',a,' to ',b,': same.')
                        else
                        if abs(a-goal)>abs(b-goal) then
                        writeln('Moving from ',a,' to ',b,': warmer.')
                        else writeln('Moving from ',a,' to ',b,': colder.');
                a:=b;
                end;

        readln;
        read(goal);
        if goal<>5280 then writeln;
        end;
end.
 