program p1292;

{$APPTYPE CONSOLE}

var
        total,s :string;
        part,p  :Integer;


PROCEDURE makenull;
var
        i       :Integer;
begin
total:='';
for i:=1 to 120 do total:=total+'0';
end;

PROCEDURE add;
var
        i,temp  :integer;
        ch      :char;
begin
for I:=1 to length(s) div 2 do
        begin
        ch:=s[i];
        s[i]:=s[length(s)-i+1];
        s[length(s)-i+1]:=ch;
        end;
for i:=length(s)+1 to 120 do s:=s+'0';
temp:=0;
for i:=1 to 115 do
        begin
        temp:=temp+ord(total[i])-48+ord(s[i])-48;
        total[i]:=chr((temp mod 10)+48);
        temp:=temp div 10;
        end;
end;


PROCEDURE output;
var
        i       :integer;
begin
while (length(total)>0)and(total[length(total)]='0') do delete(total,length(total),1);
if length(total)=0 then writeln(0) else
        for i:=length(total) downto 1 do write(total[i]);
writeln;
end;

begin
readln(part);
for p:=1 to part do
        begin
        readln;
        readln(s);
        makenull;
        while s<>'0' do
                begin
                add;
                readln(s);
                end;
        output;
        if p<>part then writeln;
        end;
end.
