program p1294;

{$APPTYPE CONSOLE}

var
        n       :Integer;
        d       :integer;
        p       :integer;
        step    :integer;

begin
  { TODO -oUser -cConsole Main : Insert code here }
readln(p,n);
step:=0;
while p<>0 do
        begin
        d:=n-p;
        inc(step);
        writeln('Hole #',step);
        if n=1 then writeln('Hole-in-one.') else
                if d=0 then writeln('Par.') else
                if d<=-3 then writeln('Double Eagle.') else
                if d=-2 then writeln('Eagle.') else
                if d=-1 then writeln('Birdie.') else
                if d=1 then writeln('Bogey.') else
                writeln('Double Bogey.');
        readln(p,n);
        writeln;
        end;
end.
 