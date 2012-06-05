PROGRAM p1681;

CONST
        Max=151200;

VAR
        n,i                             :Longint;
        total_a,total_b                 :Integer;
        line_a,line_b                   :array[1..100]of Longint;
        line                            :array[0..max]of Boolean;

PROCEDURE MakeLine;
var
        i,j,k                           :Longint;
begin
fillchar(line,sizeof(line),0);

for i:=0 to 100 do
        begin
        j:=i*i*i;
        if J>max then break else line_a[i+1]:=j;
        end;

total_a:=i;

line_b[1]:=1;
line_b[2]:=4;
for i:=2 to 200 do
        begin
        j:=line_b[i] * (i+3) div i;

        if j>max then break else line_b[ i+1 ]:=j;
        end;

total_b:=i;

for i:=1 to total_a do
        begin
        for j:=1 to total_b do
                begin
                k:=line_a[i]+line_b[j] ;
                if k<=max then line[k]:=true;
//                if k>max then break else line[k]:=true;
                end;
        line[line_a[i]]:=true;
        end;
end;

BEGIN
MakeLine;
readln(n);
while (n<>0) do
        begin
        for i:=n downto 0 do if line[i] then break;
        writeln(i);
        readln(n);
        end;
END.