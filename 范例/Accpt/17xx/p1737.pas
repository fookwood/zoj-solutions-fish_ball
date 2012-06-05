PROGRAM p11737;

VAR
        part,p,i                        :Integer;
        s,t                             :String;

PROCEDURE jp(var s:String);
begin
s:=s+s[1];
delete(s,1,1);
end;

PROCEDURE cp(var s:String);
begin
s:=s[length(s)]+s;
delete(s,length(s),1);
end;

PROCEDURE Ep(var s:String);
var
        d                               :Integer;
        l1,l2                           :String;
begin
d:=length(s) div 2;
l1:=copy(s,1,d);
l2:=copy(s,length(s)-d+1,d);
delete(s,length(s)-d+1,d);
delete(s,1,d);
s:=l2+s+l1;
end;

PROCEDURE Ap(var s:String);
var
        i                               :Integer;
        temp                            :Char;
begin
for i:=1 to length(s) div 2 do
        begin
        temp:=s[i];
        s[i]:=s[length(s)-i+1];
        s[length(s)-i+1]:=temp;
        end;
end;

PROCEDURE pp(var s:String);
var
        i                               :Integer;
begin
for i:=1 to length(s) do
        if s[i]='9' then s[i]:='0' else
        if (s[i]>='0')and(s[i]<='8') then s[i]:=succ(s[i]);
end;

PROCEDURE mp(var s:String);
var
        i                               :Integer;
begin
for i:=1 to length(s) do
        if s[i]='0' then s[i]:='9' else
        if (s[i]>='1')and(s[i]<='9') then s[i]:=pred(s[i]);
end;

BEGIN
//assign(input,'p.in');
//reset(input);
readln(part);
for p:=1 to part do
        begin
        readln(t);
        readln(s);
        for i:=length(t) downto 1 do
                case t[i] of
                'A'             :ap(s);
                'C'             :jp(s);
                'J'             :cp(s);
                'E'             :ep(s);
                'M'             :pp(s);
                'P'             :mp(s);
                end;
        writeln(s);
        end;
END.