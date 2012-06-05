PROGRAM P1712;

CONST
        max=29;

VAR
        pre     :array[1..31]of longint;
        s       :string;
        ans     :longint;
        i       :integer;

PROCEDURE make;
var     i       :integer;
        mi      :longint;
begin
mi:=1;
for i:=1 to max do
        begin
        mi:=mi*2;
        pre[i]:=mi-1;
        end;
pre[30]:=pre[max]*2+1;
pre[31]:=pre[30]*2+1;
end;


BEGIN
make;
readln(s);
while s<>'0' do
        begin
        ans:=0;
        for i:=length(s) downto 1 do
                ans:=ans+pre[length(s)-i+1]*(ord(s[i])-48);
        writeln(ans);
        readln(s);
        end;
END.