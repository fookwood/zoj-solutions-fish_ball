PROGRAM p1016;

VAR
        k       :integer;
        team    :integer;
        n       :integer;
        j       :integer;
        num     :array[1..20]of integer;


PROCEDURE answer;
var     I       :integer;
        s       :string;
        right   :integer;
        have,max:integer;
        j       :integer;
begin
s:='';
for I:=1 to 2*n do s:=s+'(';
for i:=1 to n do
        begin
        s[i+num[i]]:=')';
        have:=1;
        j:=i+num[i]-1;
        max:=0;
        while have<>0 do
                begin
                if s[j]='(' then
                        begin
                        dec(have);inc(max);
                        end else inc(have);
                dec(j);
                end;
        if i=n then writeln(max) else write(max,' ');
        end;
end;

BEGIN
readln(k);
for team:=1 to k do
        begin
        read(n);
        for j:=1 to n do read(num[j]);
        readln;
        answer;
        end;
END.
