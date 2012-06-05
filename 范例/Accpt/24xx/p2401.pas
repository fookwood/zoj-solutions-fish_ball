PROGRAM p2401;

TYPE
        integer=longint;

VAR
        part,p,step                             :Integer;
        s,t,goal                                :array[1..1000]of Char;
        ls,lt,lgoal                             :Integer;
        num1,num2                               :array['A'..'z']of Longint;

PROCEDURE Readin;
var
        ch                                      :Char;
begin
fillchar(num1,sizeof(num1),0);
fillchar(num2,sizeof(num2),0);
read(ch);
ls:=0;
while (ch<>' ') do
        begin
        inc(ls);
        s[ls]:=ch;
        inc(num1[ch]);
        read(ch);
        end;
inc(ls);
s[ls]:='*';
read(ch);
lt:=0;
while (ch<>' ') do
        begin
        inc(lt);
        t[lt]:=ch;
        inc(num1[ch]);
        read(ch);
        end;
lgoal:=0;
while (not eoln) do
        begin
        read(ch);
        inc(lgoal);
        goal[lgoal]:=ch;
        inc(num2[ch]);
        end;
inc(lgoal);
goal[lgoal]:='*';
readln;
end;

FUNCTION Check:Boolean;
var
        i                       :char;
begin
check:=true;
for i:='A' to 'z' do
        if num1[i]<>num2[i] then
                begin
                check:=false;
                exit;
                end;
end;

FUNCTION Find(p1,p2:Integer):Boolean;
var
        pgoal                                   :Integer;
begin
find:=true;
pgoal:=p1+p2-1;
while (p1<=ls) do
        begin
        while (p2<=lt)and(goal[pgoal]<>s[p1]) and (goal[pgoal]=t[p2]) do
                begin
                inc(p2);
                inc(pgoal);
                end;
        if (goal[pgoal]=s[p1]) then
                begin
                if (p1=ls) or find(p1+1,p2) then exit;
                if (p2<=lt) and (t[p2]=s[p1]) then
                        begin
                        inc(p2);
                        inc(pgoal);
                        end else break;
                end else break;
        end;
find:=false;
end;

BEGIN
//assign(input,'p.in');
//reset(input);
step:=0;
readln(part);
for p:=1 to part do
        begin
        inc(step);
        Readin;
        write('Data set ',step,': ');
        if check and find(1,1) then writeln('yes') else writeln('no');
        end;
END.