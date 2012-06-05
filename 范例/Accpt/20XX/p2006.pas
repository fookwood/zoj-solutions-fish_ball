PROGRAM p2006;

VAR
        n,i,j,ans,part          :Integer;
        data                    :array[0..10000]of Char;

PROCEDURE Main;
var
        i,k,p1,p2               :Integer;
        down                    :Boolean;
begin
p1:=0;
p2:=1;
repeat
        k:=0;
        while (data[(p1+k) mod n]=data[(p2+k) mod n]) do
                begin
                inc(k);
                if k=n then break;
                end;
        if k=n then break;
        if data[(p1+k) mod n]>data[(p2+k) mod n] then p1:=p1+k+1;
        if data[(p1+k) mod n]<data[(p2+k) mod n] then p2:=p2+k+1;
        if p1=p2 then inc(p1);
        if p1>=n then
                begin
                writeln(p2+1);
                exit;
                end;
        if p2>=n then
                begin
                writeln(p1+1);
                exit;
                end;
until k>n;
if p1>p2 then writeln(p2+1) else writeln(p1+1);
end;

BEGIN
//assign(input,'p.in');
//reset(input);
readln(part);
for i:=1 to part do
        begin
        n:=0;
        while not eoln do
                begin
                read(data[n]);
                inc(n);
                end;
        readln;
        Main;
        end;
END.