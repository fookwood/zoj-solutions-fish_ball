PROGRAM p1275;

VAR
        n                       :Longint;
        step                    :Integer;

FUNCTION Check:Boolean;
var
        i,j,l                   :Integer;
        s                       :String;
        have                    :array[0..9]of Boolean;
        reach                   :array[0..9]of Boolean;
begin
fillchar(have,sizeof(have),0);
fillchar(reach,sizeof(reach),0);
str(n,s);
j:=0;
i:=1;
l:=length(s);
repeat
        i:= (i+ord(s[i])-48) mod l;
        if i=0 then i:=l;
        inc(j);
        if reach[i] or have[ord(s[i])-48] then break;
        reach[i]:=true;
        have[ord(s[i])-48]:=true;
until false;
if j=l+1 then check:=true else check:=false;
end;

BEGIN
step:=0;
readln(n);
while n<>0 do
        begin
        inc(step);
        while not check do inc(n);
        writeln('Case ',step,': ',n);
        readln(n);
        end;
END.
