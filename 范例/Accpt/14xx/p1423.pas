PROGRAM p1423;

VAR
        s                               :string;
        n,i                             :integer;

PROCEDURE answer;
var
        i,j                             :integer;
        have                            :integer;
        change                          :boolean;



begin
i:=1;
while (i<=length(s)) do
        if s[i]=' ' then delete(s,i,1)
                else inc(i);

if length(s)>0 then
        repeat
                change:=false;
                i:=2;
                {if (length(s)>=2)and(s[1]='(')and(s[2]=')') then
                        begin
                        delete(s,1,2);
                        change:=true;
                        end;}

                while (i<=length(s)-1) do
                        if (s[i]>='A')and(s[i]<='Z') then
                                begin
                                if (s[i-1]='(')and(s[i+1]=')') then
                                        begin
                                        delete(s,i+1,1);
                                        delete(s,i-1,1);
                                        change:=true;
                                        end;
                                if (i+3<=length(s))and(s[i-1]='(') then
                                        if (i=2)or(s[i-2]='+')or(s[i-2]='(') then
                                                begin
                                                j:=i+1;
                                                have:=1;
                                                while have>0 do
                                                        begin
                                                        inc(j);
                                                        if s[j]='(' then inc(have);
                                                        if s[j]=')' then dec(have);
                                                        end;
                                                delete(s,j,1);
                                                delete(s,i-1,1);
                                                change:=true;
                                                end;
                                inc(i);
                                end else inc(i);{
                                begin
                                if (s[i]='(')and(s[i+1]=')') then
                                        begin
                                        delete(s,i,2);
                                        change:=true;
                                        end;
                                inc(i);
                                end;    }
        until not change;
writeln(s);
end;


BEGIN
//assign(input,'p1423.in');
//reset(input);
readln(n);
for i:=1 to n do
        begin
        readln(s);
        answer;
        end;
END.
