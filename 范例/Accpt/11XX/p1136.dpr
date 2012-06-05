program p1136;

{$APPTYPE CONSOLE}

var
        i               :Integer;
        temp            :Integer;
        n,m,have        :integer;
        num             :array[1..10]of integer;
        whether         :array[0..9]of boolean;
        line,puss,leave            :array[1..10000]of integer;
        cheng           :array[1..10000]of boolean;
        yu              :array[0..4999]of boolean;
        
PROCEDURE print(p:integer);
begin
if p=0 then exit;
print(puss[p]);
write(line[p]);
end;

PROCEDURE main;
var
        i,j,temp        :Integer;
        s,t             :integer;

begin

fillchar(yu,sizeof(yu),false);
for i:=1 to have-1 do
        for j:=i+1 to have do
                if num[i]>num[j] then
                        begin
                        temp:=num[i];
                        num[i]:=num[j];
                        num[j]:=temp;
                        end;

if n=0 then
                begin
                writeln(0);
                end else
        begin
        s:=1;t:=have;
        for I:=1 to have do
                begin
                line[i]:=num[i];
                leave[i]:=num[i] mod n;
                puss[i]:=0;
                yu[num[i]]:=true;
                if (leave[i]=0)and(num[i]<>0) then
                        begin
                        print(i);
                        writeln;
                        exit
                        end;
                if leave[i]=0 then cheng[i]:=false else cheng[i]:=true;
                end;
        repeat
                for i:=1 to have do
                        begin
                        inc(t);
                        line[t]:=num[i];
                        puss[t]:=s;
                        leave[t]:=(leave[s]*10+num[i]) mod n;
                        if num[i]=0 then cheng[t]:=cheng[s] else cheng[t]:=true;
                        if (leave[t]=0)and(cheng[t]) then
                                begin
                                print(t);
                                writeln;
                                exit;
                                end;
                        if yu[leave[t]] then dec(t) else yu[leave[t]]:=true;
                        end;
                inc(s);
        until s>t;
        writeln(0);
        end;
end;

begin


while not eof do
        begin
        have:=0;
        fillchar(whether,sizeof(whether),false);
        readln(n);
        readln(m);
        for i:=1 to m do
                begin
                readln(temp);
                if not whether[temp] then
                        begin
                        inc(have);
                        num[have]:=temp;
                        whether[temp]:=true;
                        end;
                end;
        main;
        readln;
        end;
end.
 