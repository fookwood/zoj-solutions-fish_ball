PROGRAM P1098;

VAR
        accu,pc,i                               :Integer;
        data                                    :array[0..31]of String[8];

FUNCTION StrToInt(s:String):Integer;
var
        i,temp                                  :Integer;
begin
temp:=0;
for i:=1 to length(s) do
        temp:=temp*2+ord(s[i])-48;
StrToInt:=temp;
end;

FUNCTION IntToStr(p:Integer):String[8];
var
        i                                       :Integer;
        s                                       :String[8];
begin
s:='';
while p>0 do
        begin
        s:=char(p mod 2+48)+s;
        p:=p div 2;
        end;
while length(s)<8 do s:='0'+s;
IntToStr:=s;
end;


PROCEDURE Main;
var
        order                                   :String[3];
        t                                       :String[5];
begin
pc:=0;accu:=0;
while true do
        begin
        if pc=32 then pc:=0;
        order:=copy(data[pc],1,3);
        t:=copy(data[pc],4,5);
        if order='000' then
                begin
                data[StrToInt(t)]:=IntToStr(accu);
                inc(pc);
                end else
        if order='001' then
                begin
                accu:=StrToInt(data[StrToInt(t)]);
                inc(pc);
                end else
        if order='010' then
                begin
                if accu=0 then pc:=StrToInt(t) else inc(pc);
                end else
        if order='011' then
                begin
                inc(pc);
                end else
        if order='100' then
                begin
                accu:=(accu+255) mod 256;;
                inc(pc);
                end else
        if order='101' then
                begin
                accu:=(accu+1) mod 256;
                inc(pc);
                end else
        if order='110' then
                begin
                pc:=StrToInt(t);
                end else
        if order='111' then
                begin
                break;
                end;
        end;
writeln(IntToStr(accu));
end;


BEGIN
//assign(input,'p.in');
//reset(input);
while not eof do
        begin
        for i:=0 to 31 do readln(data[i]);
        Main;
        end;
END.
