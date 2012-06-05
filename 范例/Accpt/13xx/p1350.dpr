program p1350;

{$APPTYPE CONSOLE}

var
        stay    :array[1..100]of boolean;
        total   :integer;
        n       :integer;
        part,p  :integer;
        i       :integer;
        j       :integer;
begin
readln(part);
for p:=1 to part do
        begin
        readln(n);
        total:=0;
        fillchar(stay,sizeof(stay),false);
        for I:=1 to n do
                for J:=1 to n div i do
                        stay[i*j]:=not stay[i*j];
        for i:=1 to n do if stay[i] then inc(total);
        writeln(total);
        end;
end.
