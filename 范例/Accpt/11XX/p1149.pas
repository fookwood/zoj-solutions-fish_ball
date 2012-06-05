PROGRAM p1149;

TYPE
        Twhether        = array[0..60000]of Boolean;
        Tnum            = array[1..6]of Integer;

VAR
        totalval , step         :Longint;
        ans                     :Boolean;
        num                     :Tnum;
        whether                 :Twhether;

FUNCTION Init   :Boolean;
var
        i                       :Integer;
begin
totalval:=0;
for i:=1 to 6 do
        begin
        read(num[i]);
        inc(totalval,num[i] * i);
        end;
if totalval=0 then
        init:=false
        else
        init:=true;
end;

PROCEDURE Dp;
var
        i , j , left , k
                        :Longint;
begin
if odd(totalval) then
        begin
        ans := false;
        exit;
        end;

totalval := totalval div 2;
fillchar(whether , sizeof(whether) , 0);
whether[0] := true;


for i := 1 to 6 do
        for j := 0 to i-1 do
                begin
                k := j;
                left := 0;
                while k<=totalval do
                        begin
                        if whether [k] then
                                left := num[i]
                                        else
                                if (left > 0) then
                                        begin
                                        dec( left ) ;
                                        whether [k] := true;
                                        end;
                        inc( k , i );
                        end;
                if whether [totalval] then
                        begin
                        Ans := true;
                        exit;
                        end;
                end;
Ans := false;
end;

BEGIN
//assign(input,'p.in');
//reset(input);
step:=0;
while init do
        begin
        inc(step);
        Dp;
        writeln('Collection #',step,':');
        if ans then writeln('Can be divided.') else
                writeln('Can''t be divided.');
        writeln;
        end;
END.
