PROGRAM p1537;

VAR
        k                               :Integer;
        leave                           :array[1..9]of Integer;
        whether                         :array[1..9,0..999]of Boolean;
        stop                            :array[1..9]of Boolean;

PROCEDURE Main;
var
        step                            :Integer;
        i,j                             :Integer;
begin
fillchar(leave,sizeof(leave),0);
fillchar(whether,sizeof(whether),0);
fillchar(stop,sizeof(stop),0);
for i:=1 to 9 do whether[i,0]:=true;
for i:=1 to 9 do
        begin
step:=0;
repeat
        inc(step);

                if not stop[i] then
                begin
                leave[i]:=(leave[i]*10+i) mod k;
                //writeln(i,' ',leave[i]);readln;
                if whether[i,leave[i]] then
                        begin
                        if leave[i]=0 then
                                begin
                                writeln(i,' ',step);
                                exit;
                                end else
                                stop[i]:=true;
                        end else whether[i,leave[i]]:=true;
                end else break;
until step>1000;
        end;
writeln(-1);
end;

BEGIN
while not eof do
        begin
        readln(k);
        //if k=0 then writeln('0 1') else
        Main;
        end;
END.