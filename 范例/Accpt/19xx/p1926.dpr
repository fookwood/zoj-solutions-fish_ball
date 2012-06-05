program p1926;

{$APPTYPE CONSOLE}

var
        ask     :array[1..10]of boolean;
        hol     :array[1..10]of integer;
        ans     :integer;
        s       :string;
        check   :boolean;
        n       :integer;
        t       :integer;
        i       :Integer;
begin
readln(n);
while n<>0 do
        begin
        fillchar(ask,sizeof(ask),false);
        check:=true;
        repeat
        readln(s);
        if s='too high' then t:=1;
        if s='too low' then t:=0;
        if s='right on' then ans:=n else
                if (ask[n])and(hol[n]<>t) then check:=false else
                        begin
                        ask[n]:=true;
                        hol[n]:=t;
                        end;
        if s<>'right on' then readln(n);
        until s='right on';
        for i:=1 to 10 do
                if ask[i] then
                        begin
                        if ((hol[i]=1)and(i<ans))or((hol[i]=0)and(i>ans)) then
                        begin
                        check:=false;
                        break;
                        end;
                        end;
        if ask[ans] then check:=false;
        if check then writeln('Stan may be honest') else
                writeln('Stan is dishonest');
        readln(n);
        end;
end.
