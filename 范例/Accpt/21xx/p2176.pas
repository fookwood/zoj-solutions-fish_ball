PROGRAM p2176;

VAR
        n       :integer;
        i       :integer;
        time    :longint;
        a,b,savea,saveb         :longint;
        ans     :longint;
BEGIN
readln(n);
while n<>-1 do
        begin
        ans:=0;
        savea:=0;saveb:=0;
        for i:=1 to n do
                begin
                readln(a,b);
                time:=b-saveb;
                ans:=ans+a*time;
                savea:=a;
                saveb:=b;
                end;
        writeln(ans,' miles');
        readln(n);
        end;
END.