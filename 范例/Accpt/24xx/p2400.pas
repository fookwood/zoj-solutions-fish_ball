PROGRAM p2400;

{$APPTYPE CONSOLE}

VAR
        s                       :array[1..66]of string;
        pri                     :Set of 3..80;
        n                       :Int64;
        k,i                     :Integer;

PROCEDURE Check(v:Int64);
var
        prime                   :Boolean;
        p,s                     :Int64;
begin
prime:=true;
p:=2;
s:=v;
while (p<=round(sqrt(v))) do
        if v mod p=0 then
        begin
        if not prime then write(' * ');
        write(p);
        prime:=false;
        v:=v div p;
        end else
        begin
        if p>2 then inc(p,2)
                else inc(p,1);
        end;
if not prime and (v>1) then write(' * ',v);
if not prime then writeln(' = ',s,' = ( 2 ^ ',i,' ) - 1');
end;

FUNCTION prim(v:Integer):Boolean;
var
        i                               :Integer;
begin
prim:=true;
for i:=2 to trunc(sqrt(v)) do
        if v mod i=0 then
                begin
                prim:=false;
                exit;
                end;
end;

PROCEDURE Main;
begin
n:=1;
for i:=1 to k do
        begin
        n:=n * 2;
        if (i>10) and prim(i) and not (i in pri) then
                begin
                check(n-1);
                end;
        end;
end;

BEGIN
s[11]:='23 * 89 = 2047 = ( 2 ^ 11 ) - 1';
s[23]:='47 * 178481 = 8388607 = ( 2 ^ 23 ) - 1';
s[29]:='233 * 1103 * 2089 = 536870911 = ( 2 ^ 29 ) - 1';
s[41]:='13367 * 164511353 = 2199023255551 = ( 2 ^ 41 ) - 1';
s[43]:='431 * 9719 * 2099863 = 8796093022207 = ( 2 ^ 43 ) - 1';
s[47]:='2351 * 59862819377 = 140737488355327 = ( 2 ^ 47 ) - 1';
s[53]:='69431 * 129728784761 = 9007199254740991 = ( 2 ^ 53 ) - 1';
s[59]:='179951 * 3203431780337 = 576460752303423487 = ( 2 ^ 59 ) - 1';
s[37]:='223 * 616318177 = 137438953471 = ( 2 ^ 37 ) - 1';
pri:=[2,3,5,7,13,17,19,31,61];
readln(k);
main;
END.
