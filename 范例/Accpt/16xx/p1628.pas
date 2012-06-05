PROGRAM p1628;

VAR
        i,j,x1,y1,x2,y2                 :Integer;
        map                             :array[1..8,1..8]of Char;



FUNCTION check :Boolean;
var
        ch                              :Char;
        i,j                             :Integer;
begin
if not (((x1=x2)and(abs(y1-y2)=1))or((abs(x1-x2)=1)and(y1=y2))) then
        begin
        check:=false;
        exit;
        end;


ch:=map[x1,y1];map[x1,y1]:=map[x2,y2];map[x2,y2]:=ch;
i:=y1+1;
j:=0;
while (i<=8)and(map[x1,i]=map[x1,i-1]) do
        begin
        inc(j);
        inc(i);
        end;
i:=y1-1;
while (i>=1)and(map[x1,i]=map[x1,i+1]) do
        begin
        inc(j);
        dec(i);
        end;
if j>=2 then
        begin
        check:=true;
        exit;
        end;
i:=y2+1;
j:=0;
while (i<=8)and(map[x2,i]=map[x2,i-1]) do
        begin
        inc(j);
        inc(i);
        end;
i:=y2-1;
while (i>=1)and(map[x2,i]=map[x2,i+1]) do
        begin
        inc(j);
        dec(i);
        end;
if j>=2 then
        begin
        check:=true;
        exit;
        end;

j:=0;
i:=x1-1;
while (i>=1)and(map[i,y1]=map[i+1,y1]) do
        begin
        dec(i);
        inc(j);
        end;
i:=x1+1;
while (i<=8)and(map[i,y1]=map[i-1,y1]) do
        begin
        inc(i);
        inc(j);
        end;
if j>=2 then
        begin
        check:=true;
        exit;
        end;
j:=0;
i:=x2-1;
while (i>=1)and(map[i,y2]=map[i+1,y2]) do
        begin
        dec(i);
        inc(j);
        end;
i:=x2+1;
while (i<=8)and(map[i,y2]=map[i-1,y2]) do
        begin
        inc(i);
        inc(j);
        end;
if j>=2 then
        begin
        check:=true;
        exit;
        end;
check:=false;
end;

BEGIN
//assign(input,'p.in');
//reset(input);
while not eof do
        begin
        for i:=1 to 8 do
                begin
                for j:=1 to 8 do read(map[i,j]);
                readln;
                end;
        readln(x1,y1,x2,y2);
        if check then writeln('Ok!') else writeln('Illegal move!');
        end;
END.