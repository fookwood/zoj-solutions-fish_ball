PROGRAM p1902;

VAR
        n,m                             :Integer;
        i,j                             :Integer;
        ans                             :Longint;
        ch                              :Char;
        sum                                     :Longint;
        s                               :String;
        whether                         :array[1..7889]of Boolean;
        data                            :array[1..1000]of String;
        value                           :array[1..1000]of Longint;
        code                            :Integer;

PROCEDURE Check;
var
        i                               :Integer;
begin
sum:=0;
for i:=1 to length(s) do sum:=sum + ord(s[i]) - 27;
if not whether[sum mod 7889] then exit;
for i:=1 to n do
        if data[i]=s then
                begin
                inc(ans,value[i]);
                exit;
                end;
end;

BEGIN
//assign(input,'p.in');
//reset(input);
while not eof do
        begin
        readln(n,m);
        fillchar(whether,sizeof(whether),0);
        for i:=1 to n do
                begin
                readln(data[i]);
                j:=pos(' ',data[i]);
                val(copy(data[i],j+1,length(data[i])-j),value[i],code);
                delete(data[i],j,length(data[i])-j+1);
                sum:=0;
                for j:=1 to length(data[i]) do
                        sum:=sum + ord (data[i][j]) -27;
                whether[sum mod 7889]:=true;
                end;
        for i:=1 to m do
                begin
                s:='';
                ans:=0;
                repeat
                        read(ch);
                        if ch='.' then break;
                        if (ch=' ')or((ch>='0')and(ch<='9'))or(ord(ch)<=13) then
                                begin
                                check;
                                s:='';
                                end else s:=s+ch;
                until false;
                check;
                writeln(ans);
                if not eof then readln;
                end;
        end;
END.
