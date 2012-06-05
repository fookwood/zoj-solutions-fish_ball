PROGRAM p1504;

VAR
        n                       :Integer;
        map                     :array[1..12,1..12]of Char;

PROCEDURE Main;
var
        a,b,i,j,p,q             :Integer;
        total                   :Integer;
        whether                 :array['a'..'z']of Boolean;
        ch                      :Char;

        Function check:Boolean;
        var
                i,j             :Integer;
        begin
        check:=false;
        for i:=1 to n do
                for j:=0 to n do
                if (a+j<=n)and(b+i<=a+j)and(a+i<=n)and(b-j<=a)and(b+i-j>0) and (map[a,b]=map[a+j,b+i])and(map[a+i,b+i-j]=map[a,b]) then
                        begin
                        check:=true;
                        exit;
                        end;
        //check:=false;
        end;

begin
total:=0;
fillchar(whether,sizeof(whether),0);
for a:=1 to n do
        for b:=1 to a do
                if not whether[map[a,b]] and check then
                        begin
                        inc(total);
                        whether[map[a,b]]:=true;
                        end;
if total=0 then writeln('LOOOOOOOOSER!') else
        begin
        for ch:='a' to 'z' do
                if whether[ch] then write(ch);
        writeln;
        end;
end;

PROCEDURE Readin;
var
        i,j                     :Integer;
begin
for I:=1 to n do  for J:=1 to i do read(map[i,j]);
readln;
end;

BEGIN
//assign(input,'p.in');
//reset(input);
readln(n);
while (n<>0) do
        begin
        Readin;
        Main;
        readln(n);
        end;
END.