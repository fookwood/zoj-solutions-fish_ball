PROGRAM p1222;

TYPE
        BigNum=array[1..100]of Integer;

CONST
        ans     :array[0..9]of Integer=
        (1,1,2,6,4,4,4,8,4,6);
        d2      :array[2..8]of Integer=
        (6,0,2,0,8,0,4);

VAR
        max                                     :Integer;
        s                                       :BigNum;
        t                                       :String;
        l                                       :Integer;

FUNCTION s_1(var s:BigNum):Boolean;
var
        i                                        :Integer;
begin
s_1:=true;
for i:=2 to max do
        if s[i]<>0 then
                begin
                s_1:=false;
                exit;
                end;
end;

FUNCTION Divp(s:BigNum;p:integer):BigNum;
var
        i,temp                                  :Integer;
begin
temp:=0;
for i:=max downto 1 do
        begin
        temp:=temp*10+s[i];
        Divp[i]:=temp div p;
        temp:=temp mod p;
        end;
end;

FUNCTION Last(s:BigNum):Integer;
var
        copy                                            :BigNum;
        num,i                                           :Integer;
begin
if s_1(s) then
        begin
        if s[1]>=5 then Last:=d2[ans[s[1]]] else Last:=ans[s[1]];
        end else
        begin
        copy:=Divp(s,5);
        num:=6;
        for i:=1 to (copy[2]*10+copy[1]) mod 4 do
                num:=d2[num];
        num:=num*ans[s[1]];
        Last:=(Last(copy)*num)mod 10;
        end;
end;

BEGIN
while not eof do
        begin
        readln(t);
        fillchar(s,sizeof(s),0);
        for l:=1 to length(t) do
                s[length(t)-l+1]:=ord(t[l])-48;
        max:=Length(t);
        writeln(Last(s));
        end;
END.