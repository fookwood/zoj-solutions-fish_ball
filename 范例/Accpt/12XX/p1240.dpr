program p1240;

{$APPTYPE CONSOLE}

var
        s       :string;
        n,i,j   :longint;
        step   :integer;

begin
readln(n);
step:=0;
for I:=1 to n do
        begin
        inc(step);
        readln(s);
        for j:=1 to length(s) do
                if s[j]='Z' then s[j]:='A'
                        else s[j]:=chr(ord(s[j])+1);
        writeln('String #',step);
        writeln(s);
        writeln;
        end;
end.
 