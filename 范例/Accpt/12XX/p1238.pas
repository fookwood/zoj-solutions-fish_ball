PROGRAM p1238;

CONST
        lef=37;

VAR
        ch                              :Char;
        part,p                                  :Integer;
        total,leave1,leave2                     :Longint;

PROCEDURE Main;
var
        i,ans                                   :Longint;
begin
if total=1 then
        begin
        if leave1=1 then writeln(1) else
        if leave1=4 then writeln(2) else
        writeln(-1);
        exit;
        end;
ans:=1;
repeat inc(ans);until trunc(ln(ans)/ln(10)*ans+1)>=total;
if trunc(ln(ans)/ln(10)*ans+1)>total then
        writeln(-1) else
begin
leave2:=1;
for i:=1 to ans do leave2:=(leave2*ans) mod lef;
if leave2=leave1 then writeln(ans) else writeln(-1);
end;
end;

BEGIN
//assign(input,'p.in');
//reset(input);
readln(part);
for p:=1 to part do
        begin
        total:=0;
        leave1:=0;
        while not eoln do
                begin
                read(ch);
                inc(total);
                leave1:=(leave1*10+ord(ch)-48) mod lef;
                end;
        readln;
        Main;
        end;
END.
