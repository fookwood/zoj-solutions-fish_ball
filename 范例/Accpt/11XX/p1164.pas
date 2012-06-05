PROGRAM p1164;

CONST
        p=34943;

VAR
        ch                              :Char;
        left,cheng                      :Longint;
        s                               :String;

BEGIN
cheng:=trunc(1 shl 8 );
while true do
begin
left:=0;
if not eoln then
repeat
        read(ch);
        if ch='#' then halt;
        left:=(left * cheng + ord(ch) ) mod p;
until eoln;
readln;
left:=(left * cheng) mod p;
left:=(left * cheng) mod p;
s:=HexStr((p-left) mod p,4);
writeln(s[1],s[2],' ',s[3],s[4]);
end;
END.