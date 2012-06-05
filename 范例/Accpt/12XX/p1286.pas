PROGRAM p1286;

{$APPTYPE CONSOLE}

VAR
        n,i                             :Integer;
        pos                             :Integer;
        s                               :String;

FUNCTION CheckSlump(d:Integer):Boolean;
begin
if (pos>length(s))or((s[pos]<>'D')and(s[pos]<>'E')) then
        begin
        CheckSlump:=false;
        exit;
        end;
inc(pos);
if (pos>length(s))or(s[pos]<>'F') then
        begin
        checkSlump:=false;
        exit;
        end;
while (pos<length(s))and(s[pos]='F') do inc(pos);
if (pos>length(s)) then
        begin
        checkSlump:=false;
        exit;
        end;
if s[pos]='G' then
                begin
                inc(pos);
                CheckSlump:=true;
                end
                else
                Checkslump:=CheckSlump(1);
end;

FUNCTION CheckSlimp(d:Integer):Boolean;
begin
if s[pos]<>'A' then
        begin
        CheckSlimp:=false;
        exit;
        end;
inc(pos);
if (pos>length(s)) then
        begin
        CheckSlimp:=false;
        exit;
        end;
if s[pos]='H' then
        begin
        inc(pos);
        checkSlimp:=true;
        exit;
        end;
if (pos>length(s)) then
        begin
        inc(pos);
        checkSlimp:=false;
        exit;
        end;
if (pos>length(s)) then
        begin
        CheckSlimp:=false;
        exit;
        end;
if s[pos]='B' then
        begin
        inc(pos);
        if not CheckSlimp(1) then
                begin
                CheckSlimp:=false;
                exit;
                end;
        if Pos>length(s) then
                begin
                CheckSlimp:=false;
                exit;
                end;
        if s[pos]='C' then
                begin
                inc(pos);
                CheckSlimp:=true
                end else CheckSlimp:=false;
        end
        else
        begin
        CheckSlimp:=CheckSlump(1);
        if (pos<=length(s))and(s[pos]='C') then inc(pos) else CheckSlimp:=false;
        end;
end;

BEGIN
//assign(input,'p.in');
//reset(input);
readln(n);
writeln('SLURPYS OUTPUT');
for i:=1 to n do
        begin
        pos:=1;
        readln(s);
        //writeln(s);
        if CheckSlimp(1) and CheckSlump(1) and (pos>length(s)) then writeln('YES') else writeln('NO');
        end;
writeln('END OF OUTPUT');
END.
