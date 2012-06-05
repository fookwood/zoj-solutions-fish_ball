PROGRAM p1720;

VAR
        i                       :Integer;
        num                     :array[0..8]of Longint;

PROCEDURE Main;
var
        i,p                     :Integer;
        ch                      :String;
begin
p:=8;
while (p>0)and(num[p]=0) do dec(p);
if p=0 then
        begin
        writeln(num[p]);
        exit;
        end;
if num[p]>1 then
        begin
        if p=1 then write(num[p],'x') else write(num[p],'x^',p);
        end;
if num[p]<-1 then
        begin
        if p=1 then write(num[p],'x') else write(num[p],'x^',p);
        end;
if num[p]=1 then
        begin
        if p=1 then write('x') else write('x^',p);
        end;
if num[p]=-1 then
        begin
        if p=1 then write('-x') else write('-x^',p);
        end;
for i:=p-1 downto 1 do
        begin
        if num[i]>0 then ch:='+' else ch:='-';
        if (i<>1)and(num[i]<>0) then
                begin
                if abs(num[i])=1 then write(' ',ch,' x^',i)
                        else write(' ',ch,' ',abs(num[i]),'x^',i);
                end;
        if (i=1)and(num[i]<>0) then
                begin
                if abs(num[i])=1 then write(' ',ch,' x')
                        else write(' ',ch,' ',abs(num[i]),'x');
                end;
        end;
if num[0]>0 then
        write(' + ',num[0]);
if num[0]<0 then
        write(' - ',-num[0]);
writeln;
end;

BEGIN
while not eof do
        begin
        for i:=8 downto 0 do read(num[i]);
        readln;
        Main;
        end;
END.