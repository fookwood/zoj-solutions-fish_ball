PROGRAM p1985;

CONST
        maxn=100000;

VAR
        n                                       :Longint;
        long,left,right                         :array[0..maxn+1]of Longint;

PROCEDURE Readin;
var
        ans                                 :Int64;
        i,j                                 :Longint;
begin
ans:=0;
long[0]:=-1;
for i:=1 to n do
        begin
        read(long[i]);
        left[i]:=1;
        j:=i;
        while (long[j-left[j]]>=long[i]) do
                begin
                dec(j,left[j]);
                inc(left[i],left[j]);
                end;
        end;
readln;
long[n+1]:=-1;
for i:=n downto 1 do
        begin
        right[i]:=1;
        j:=i;
        while (long[j+right[j]]>=long[i]) do
                begin
                inc(j,right[j]);
                inc(right[i],right[j]);
                end;

        if int64(left[i]+right[i]-1) * long[i]>ans then
                ans:=int64(left[i]+right[i]-1) * long[i];
        end;
writeln(ans);
end;



BEGIN
//assign(input,'p.in');
//reset(input);
read(n);
while (n<>0) do
        begin
        Readin;
        read(n);
        end;
END.
