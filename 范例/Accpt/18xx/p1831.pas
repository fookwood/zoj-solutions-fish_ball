PROGRAM p1831;

VAR
        ch                              :Char;
        s,pre                           :String;

BEGIN
//assign(input,'p.in');
//reset(input);
readln(s);
readln(pre);
writeln(pre);
writeln(s);
repeat
        read(ch);
        //if ord(ch)=13 then writeln else
        if pos(ch,s)>0 then write(pre[pos(ch,s)]) else write(ch);
        if eof then break;
until false;
END.