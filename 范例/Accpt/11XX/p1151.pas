// GPC ACed FPC TLE

PROGRAM p1151;

VAR
        n,k       :integer;
        team      :integer;
        s       :string;
        i       :Integer;

FUNCTION ans(s:string):string;
var
        j       :integer;
        u       :integer;
        t       :string;
        temp    :char;
        a       :string;
        one     :boolean;
begin
j:=1;
one:=false;
a:='';
while (j<=length(s)) do
        begin
        t:='';
        while (j<=length(s))and(s[j]<>' ') do
                begin
                t:=t+s[j];
                inc(j);
                end;
        for u:=1 to length(t) div 2 do
                begin
                temp:=t[u];
                t[u]:=t[length(t)-u+1];
                t[length(t)-u+1]:=temp;
                end;
        if one then a:=a+' ';
        a:=a+t;
        one:=true;
        inc(j);
        end;
ans:=a;
end;


BEGIN
readln(n);
readln;
for team:=1 to n do
        begin
        readln(k);
        for i:=1 to k do
                begin
                readln(s);
                writeln(ans(s));
                end;
        if team<>n then writeln;
        end;
END.
