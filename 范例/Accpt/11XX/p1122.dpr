program p1122;

{$APPTYPE CONSOLE}

var
        a,b,c,d         :integer;
        time            :array[0..100]of real;


PROCEDURE main;
var
        copyc           :integer;
        j               :Integer;
        s,t             :real;
        have            :integer;
begin
if (c<a)or((c=a)and(d<b))then copyc:=c+12 else copyc:=c;
s:=a*60+b;
t:=copyc*60+d;
j:=0;
while time[j]<s do inc(j);
if time[j]<=t  then
        begin
        have:=0;
        while time[j]<=t do
                begin
                inc(have);
                inc(j);
                end;
        end else
        have:=0;
if a<10 then write(0:8,a)
        else write(a:9);
write(':');
if b<10 then write(0,b)
        else write(b);
if c<10 then write(0:8,c)
        else write(c:9);
write(':');
if d<10 then write(0,d)
        else write(d);
writeln(have:8);
end;

PROCEDURE maketime;

var
        i               :integer;
begin
for i:=0 to 24 do
        time[i]:=i*720/11;
end;

begin
maketime;
writeln('Program 3 by team X');
writeln('Initial time  Final time  Passes');
while not eof do
        begin
        readln(a,b,c,d);
        main;
        end;
writeln('End of program 3 by team X');
end.
