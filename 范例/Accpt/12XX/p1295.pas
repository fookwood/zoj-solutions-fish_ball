PROGRAM p1295;

VAR
        s       :string;
        i       :longint;
        k       :longint;
        j       :longint;
        l       :Integer;
        temp    :char;

BEGIN
readln(k);
for i:=1 to k do
        begin
        readln(s);
        l:=length(s);
        for j:=1 to l div 2 do
                begin
                temp:=s[j];
                s[j]:=s[l-j+1];
                s[l-j+1]:=temp;
                end;
        writeln(s);
        end;
END.