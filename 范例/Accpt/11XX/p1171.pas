PROGRAM p1171;

VAR
        reach           :longint;
        n               :longint;
        up              :array[1..100000]of boolean;
        part,p          :integer;
        ch              :char;

PROCEDURE main;
var
        f1,f2           :longint;
        i               :longint;
begin
f1:=0;f2:=0;
for i:=1 to n do
        begin
        if f1 mod 2=0 then
                begin
                if not up[i] then
                        inc(f1);
                end else
                begin
                if up[i] then inc(f1);
                end;
        if f2 mod 2=0 then
                begin
                if up[i] then inc(f2);
                end else
                begin
                if not up[i] then inc(f2);
                end;
        end;
if f1<f2 then writeln(f1) else writeln(f2);
end;


BEGIN
readln(part);
for P:=1 to part do
        begin
        readln;
        readln(n);
        reach:=0;
        repeat
                read(ch);
                if (ch='U')or(ch='D') then
                        begin
                        inc(reach);
                        if ch='U' then up[reach]:=true else up[reach]:=false;
                        end;
        until reach=n;
        readln;
        main;
        if p<>part then writeln;
        end;
END.