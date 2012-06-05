program p1202;

{$APPTYPE CONSOLE}

var
        n       :longint;
        sum     :array[0..12]of longint;
        i       :longint;
        j       :longint;
        ans     :int64;
        same    :array[0..12]of longint;


        
FUNCTION c(a,b  :int64):int64;
var
        ta      :int64;
        i       :longint;
begin
ta:=1;
for i:=a downto a-b+1 do ta:=ta*i;
for I:=2 to b do ta:=ta div i;
c:=ta;
end;

begin
while not eof do
        begin
        readln(n);
        fillchar(same,sizeof(same),0);
        fillchar(sum,sizeof(sum),0);
        for I:=1 to n do
                begin
                read(sum[i]);
                inc(same[sum[i]]);
                sum[i]:=sum[i-1]+sum[i];
                end;
        ans:=1;
        for I:=2 to n do
                begin
                ans:=ans*c(sum[i],sum[i]-sum[i-1]);
                end;
        for i:=1 to 12 do
                if same[i]>1 then
                for J:=2 to same[i] do ans:=ans div j;
        writeln(ans);
        readln;
        end;
end.
 