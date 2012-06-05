PROGRAM p1842;

CONST
        MAXN = 2147483647;

VAR
        m,n                     :Longint;
        num                     :Longint;
        prime                   :array[1..4800]of Longint;
        whether                 :array[0..1000000]of Boolean;

PROCEDURE MakePrime;
var
        i,j                     :Longint;
        t                       :Longint;
begin
t:=trunc(sqrt(maxn));
fillchar(whether,sizeof(whether),1);
num:=0;
for i:=2 to t do
        if whether[i] then
                begin
                for j:=2 to t div i do whether[i*j]:=false;
                inc(num);
                prime[num]:=i;
                end;

end;

PROCEDURE Main;
var
        half                            :Longint;
        i,j,start                       :Longint;
        s                               :Longint;
        min,max                         :Longint;
        min_p1,min_p2,max_p1,max_p2     :Longint;

begin
if m=1 then m:=2;

if (n<=m) then
        begin
        writeln('There are no adjacent primes.');
        exit;
        end;

fillchar(whether,n-m+1,1);

half:=n div 2;

for i:=1 to num do
        begin
        if prime[i] > half then break;

        {if prime[3330]=0 then
                begin
                writeln(i);
                readln;
                end;}

        if m div prime[i]>1 then
                begin
                start:=m div prime[i];
                if m mod prime[i]>0 then inc(start);
                end else start:=2;

        //if i>1001 then writeln(start,' ',prime[i],' ',n div prime[i]);

        for j:=start to n div prime[i] do
                whether[prime[i] * j - m]:=false;
        end;

min:=maxint;
max:=-1;

s:=-1;
for i:=0 to n-m do
        if whether[i] then
                begin
                if s=-1 then
                        begin
                        s:=i;
                        continue;
                        end;

                if i-s>max then
                        begin
                        max:=i-s;
                        max_p1:=s;
                        max_p2:=i;
                        end;

                if i-s<min then
                        begin
                        min:=i-s;
                        min_p1:=s;
                        min_p2:=i;
                        end;
                s:=i;
                end;

if max>0 then
        writeln(min_p1+m,',',min_p2+m,' are closest, ',max_p1+m,',',max_p2+m,' are most distant.')
                else
        writeln('There are no adjacent primes.');
end;

BEGIN
MakePrime;
while not eof do
        begin
        readln(m,n);
        Main;
        end;
END.
