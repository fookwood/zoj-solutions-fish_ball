PROGRAM p2001;

VAR
        a,b     :longint;
        k       :integer;
        team    :integer;

FUNCTION back(m:longint):longint;
var
        s       :string;
        code    :integer;
        l       :integer;
        temp    :char;
        p       :longint;
begin
str(m,s);
l:=length(s);
for code:=1 to l div 2 do
   begin
   temp:=s[code];
   s[code]:=s[l-code+1];
   s[l-code+1]:=temp;
   end;
val(s,p,code);
back:=p;
end;


BEGIN
readln(k);
for team:=1 to k do
        begin
        readln(a,b);
        a:=back(a);
        b:=back(b);
        a:=a+b;
        writeln(back(a));
        end;
END.
