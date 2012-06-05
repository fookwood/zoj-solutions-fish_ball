PROGRAM p1225;

VAR
        ch                      :Char;
        s                       :AnsiString;
        nNum,nChar,total        :Integer;
        p                       :Longint;
        code                    :Integer;
        PosNum,PosChar          :array[1..1000]of Integer;
        data                    :array[1..2000]of AnsiString;

PROCEDURE Sort;
var
        a,b                             :Longint;
        i,j,code                        :Integer;
        temp                            :AnsiString;
begin
for i:=1 to nNum-1 do
        for j:=i+1 to nNum do
                begin
                Val(data[PosNum[j]],a,code);
                Val(data[PosNum[i]],b,code);
                if a<b then
                        begin
                        temp:=data[PosNum[j]];
                        data[PosNum[j]]:=data[PosNum[i]];
                        data[PosNum[i]]:=temp;
                        end;
                end;
for i:=1 to nChar-1 do
        for j:=i+1 to nChar do
                if UpCase(data[PosChar[j]])<UpCase(data[PosChar[i]]) then
                        begin
                        temp:=data[PosChar[j]];
                        data[PosChar[j]]:=data[PosChar[i]];
                        data[PosChar[i]]:=temp;
                        end;

for i:=1 to total-1 do
        write(data[i],', ');
writeln(data[total],'.');

end;


BEGIN
read(ch);
while ch<>'.' do
        begin
        nNum:=0;
        nChar:=0;
        total:=0;
        while ch<>'.' do
                begin
                s:='';
                while (ch<>',')and(ch<>'.') do
                        begin
                        s:=s+ch;
                        read(ch);
                        end;
                inc(total);
                data[total]:=s;
                Val(s,p,code);
                if code=0 then
                        begin
                        inc(nNum);
                        PosNum[nNum]:=total;
                        end else
                        begin
                        inc(nChar);
                        PosChar[nChar]:=total;
                        end;
                if ch<>'.' then read(ch,ch);
                end;
        Sort;
        readln;
        read(ch);
        end;
END.