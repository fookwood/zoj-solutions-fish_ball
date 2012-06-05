program p1181;

{$APPTYPE CONSOLE}
var
        temp    :array[1..100]of string;
        dic     :array[1..101,'a'..'z']of integer;
        s       :string;
        t       :string;
        dicnum  :integer;
        i,j     :integer;
        have    :boolean;
        ch      :char;
        y       :boolean;


PROCEDURE makedic;
var
        i,j     :Integer;
begin
fillchar(dic,sizeof(dic),0);
for i:=1 to dicnum do
        for J:=1 to length(temp[i]) do inc(dic[i,temp[i][j]]);
end;

begin
readln(s);
dicnum:=0;
while s<>'XXXXXX' do
        begin
        inc(dicnum);
        temp[dicnum]:=s;
        readln(s);
        end;
for i:=1 to dicnum-1 do
        for j:=i+1 to dicnum do
                if temp[i]>temp[j] then
                        begin
                        t:=temp[i];
                        temp[i]:=temp[j];
                        temp[j]:=t;
                        end;
makedic;
readln(s);
while s<>'XXXXXX' do
        begin
        have:=false;
        for ch:='a' to 'z' do dic[101,ch]:=0;
        for i:=1 to length(s) do inc(dic[101,s[i]]);
        for i:=1 to dicnum do
                begin
                y:=true;
                for ch:='a' to 'z' do
                        if dic[101,ch]<>dic[i,ch] then
                                begin
                                y:=false;
                                break;
                                end;
                if y then writeln(temp[i]);
                have:=y or have;
                end;
        if not have then writeln('NOT A VALID WORD');
        writeln('******');
        readln(s);
        end;

end.
