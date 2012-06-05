PROGRAM p1623;

VAR
        part,p                          :Integer;
        n,i,ans                         :Longint;
        s,t                             :AnsiString;

PROCEDURE Make;
var
        p1,p2,p3                       :Longint;
        i,j                            :Longint;
begin
ans:=0;
t:='';
while true do
        begin
        p1:=pos('/*',s);
        p2:=pos('//',s);
        if (p1=0) and (p2=0) then
                begin
                t:=t + s;
                break;
                end;

        if p1=0 then
                begin
                inc(ans);
                t:=t + copy(s,1,p2-1);

                j:=p2 + pos('@',copy(s,p2+2,length(s)-p2-1)) + 1;

                t:=t + upcase(copy(s,p2,j-p2+1));

                delete(s,1,j);
                continue;
                end;


        if (p2=0) or (p2>p1) then
                begin
                p3:=pos('*/',copy(s,p1+2,length(s)-p1-1))+p1+1;

                if p3>p1+1 then
                        begin
                        inc(ans);
                        t:=t + copy(s,1,p1-1);

                        t:=t + upcase(copy(s,p1,p3-p1+2));


                        delete(s,1,p3+1);

                        continue;
                        end else
                if p2=0 then
                        begin
                        t:=t + s;
                        s:='';
                        continue;
                        end;
                end;


        inc(ans);
        t:=t + copy(s,1,p2-1);

        j:=p2 + pos('@',copy(s,p2+2,length(s)-p2-1)) + 1;

        t:=t + upcase(copy(s,p2,j-p2+1));

        delete(s,1,j);
        end;

writeln(ans);

for i:=1 to length(t) do
        if t[i]='@' then writeln else write(t[i]);
end;

BEGIN
//assign(input,'p.in');
//reset(input);
readln(part);
for p:=1 to part do
        begin
        readln(n);
        s:='';
        for i:=1 to n do
                begin
                Readln(t);
                s:=s+t+'@';
                end;
        make;
        //make;
        writeln;
        end;
END.