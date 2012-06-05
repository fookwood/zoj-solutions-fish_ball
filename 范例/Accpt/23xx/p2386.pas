PROGRAM p2386;

CONST
        maxn=500000;

VAR
        n                       :Longint;
        data,temp               :array[1..maxn]of Longint;

PROCEDURE Readin;
var
        i                       :Longint;
begin
readln(n);
if (n=0) then halt;
for i:=1 to n do readln(data[i]);
end;

FUNCTION Sort(left,right:Longint):Int64;
var
        c                       :Int64;
         mid,i,j,t,leave        :Longint;
begin
c:=0;
if (left<right) then
        begin
        mid:=(left+right) div 2;
        c:=Sort(left,mid)+Sort(mid+1,right);
        t:=0; i:=left; j:=mid+1; leave:=right-left+1;

        while (t<leave) do
                begin
                inc(t);
                if (i<=mid) and ( (j>right) or (data[i]<=data[j])) then
                        begin
                        temp[t]:=data[i];
                        inc(i);
                        end else
                        begin
                        temp[t]:=data[j];
                        inc(j);
                        inc(c,mid-i+1);
                        end;
                end;

        for i:=1 to leave do data[left+i-1]:=temp[i];
        end;
Sort:=c;
end;

BEGIN
//assign(input,'p.in');
//reset(input);
while true do
        begin
        Readin;
        Writeln(Sort(1,n));
        end;
END.