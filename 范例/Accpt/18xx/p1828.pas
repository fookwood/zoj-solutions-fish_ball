PROGRAM p1828;


VAR
        data    :array[1..6000,0..1000]of byte;
        n       :integer;
        i,j     :integer;


PROCEDURE makedata;
var
        i,j     :Integer;
        temp    :Integer;
begin
fillchar(data,sizeof(data),0);
data[1,1]:=1;
data[2,1]:=1;
data[1,0]:=1;
data[2,0]:=1;
for i:=3 to 6000 do
        begin
        temp:=0;
        for j:=1 to 1000 do
                begin
                temp:=temp+data[i-1,j]+data[i-2,j];
                data[i,j]:=temp mod 10;
                temp:=temp div 10;
                end;
        end;
end;


BEGIN
makedata;
while not eof do
        begin
        readln(n);
        for j:=1000 downto 1 do if data[n,j]<>0 then break;
        for i:=j downto 1 do write(data[n,i]);
        writeln;
        end;

END.