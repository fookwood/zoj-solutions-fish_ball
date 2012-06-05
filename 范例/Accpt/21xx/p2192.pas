PROGRAM p2192;

VAR
        n,code,i,j                                      :Integer;
        s                                               :String;
        pre                                             :array['A'..'Z']of Integer;
        have,satisfy                                    :array[1..5]of Integer;
        whether                                         :array[1..5,1..20]of Boolean;

PROCEDURE makepre;
begin
pre['S']:=1;
pre['M']:=2;
pre['L']:=3;
pre['X']:=4;
pre['T']:=5;
end;

PROCEDURE Main;
var
        find                                            :Boolean;
        i,leave,j,k                                     :Integer;
        done                                            :array[1..5]of Boolean;
begin
leave:=n;
fillchar(done,sizeof(done),0);
repeat
        find:=false;
        for i:=1 to 5 do
                if not done[i] and (have[i]>=satisfy[i]) then
                        begin
                        find:=true;
                        break;
                        end;
        if find then
                begin
                done[i]:=true;
                dec(leave,satisfy[i]);
                for j:=1 to n do
                        if whether[i,j] then
                                for k:=1 to 5 do if whether[k,j] then
                                        begin
                                        dec(satisfy[k]);
                                        whether[k,j]:=false;
                                        end;
                end;
until not find or (leave=0);
if leave=0 then writeln('T-shirts rock!') else
        writeln('I','''','d rather not wear a shirt anyway...');
end;

BEGIN
makepre;
readln(s);
while (s<>'ENDOFINPUT') do
        begin
        fillchar(whether,sizeof(whether),0);
        fillchar(have,sizeof(have),0);
        fillchar(satisfy,sizeof(satisfy),0);


        delete(s,1,6);
        Val(s,n,code);

        readln(s);
        i:=1;
        while i<=length(s) do if s[i]=' ' then delete(s,i,1) else inc(i);
        for i:=1 to n do
                for j:=pre[s[2*i-1]] to pre[s[2*i]] do
                        begin
                        whether[j,i]:=true;
                        inc(satisfy[j]);
                        end;

        for i:=1 to 5 do read(have[i]);
        readln;
        readln;

        Main;

        readln(s);
        end;
END.