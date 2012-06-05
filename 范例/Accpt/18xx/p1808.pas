PROGRAM p1808;

VAR
        data    :array[1..2000]of string;
        have    :longint;
        s       :string;
        step    :longint;


FUNCTION check:boolean;
var
        i,j     :longint;
begin
check:=true;
for I:=1 to have do
        for j:=1 to have do
                if (i<>j)and(length(data[i])<=length(data[j]))and(pos(data[i],data[j])=1)then
                        begin
                        check:=false;
                        exit;
                        end;
end;

BEGIN
step:=0;
while not eof do
        begin
        readln(s);
        inc(step);
        have:=0;
        while s<>'9' do
                begin
                inc(have);
                data[have]:=s;
                readln(s);
                end;
        if check then writeln('Set ',step,' is immediately decodable') else
                writeln('Set ',step,' is not immediately decodable');
        end;
END.