program p1205;

{$APPTYPE CONSOLE}
var
        i       :integer;
        s1,s2,s3        :string;
        ch      :char;
        temp    :longint;

FUNCTION c(ch:char):integer;
begin
if (ord(ch)>=ord('0'))and(ord(ch)<=ord('9')) then c:=ord(ch)-48 else
c:=ord(ch)-ord('a')+10;
end;

begin
while not eof do
        begin
        readln(s1);
        readln(s2);
        for i:=1 to (length(s1) div 2) do
                begin
                ch:=s1[i];
                s1[i]:=s1[length(s1)-i+1];
                s1[length(s1)-i+1]:=ch;
                end;
        for i:=1 to (length(s2) div 2) do
                begin
                ch:=s2[i];
                s2[i]:=s2[length(s2)-i+1];
                s2[length(s2)-i+1]:=ch;
                end;
        temp:=0;
        s3:='';
        for I:=length(s1)+1 to 150 do
                s1:=s1+'0';
        for i:=length(s2)+1 to 150 do
                s2:=s2+'0';
        for i:=1 to 120 do
                begin
                temp:=temp+c(s1[i])+c(s2[i]);
                if temp mod 20<10 then s3:=s3+chr((temp mod 20)+48)
                        else s3:=s3+chr((temp mod 20)-10+ord('a'));
                temp:=temp div 20;
                end;
        while (length(s3)>=1)and(s3[length(s3)]='0') do delete(s3,length(s3),1);
        if length(s3)=0 then write(0);
        for i:=length(s3) downto 1 do write(s3[i]);
        writeln;
        end;
end.
