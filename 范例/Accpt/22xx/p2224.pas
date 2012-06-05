PROGRAM P2224;

VAR
        money,days              :Longint;
        part,p,n,i              :Integer;
        per,cost                :array[1..40]of Longint;
        max                     :array[0..1000000]of Longint;

PROCEDURE Main;
var
        i,j,ans,temp            :Longint;
        leave,k                 :Longint;
begin
max[0]:=0;leave:=money mod 1000;i:=1;ans:=money div 1000;
for j:=1 to days do
        begin
        while (i<=ans) do
                begin
                max[i]:=i*1000;
                for k:=1 to n do
                        if (i-per[k]>=0)and(max[i-per[k]]+per[k]*1000+cost[k]>max[i]) then
                                max[i]:=max[i-per[k]]+per[k]*1000+cost[k];
                inc(i);
                end;
        if j<days then
                begin
                temp:=max[ans];
                ans:=(temp+leave) div 1000;
                leave:=(temp+leave) mod 1000;
                end;
        end;
writeln(max[ans]+leave);
end;

BEGIN
readln(part);
for p:=1 to part do
        begin
        readln(money,days);
        readln(n);
        for i:=1 to n do
                begin
                readln(per[i],cost[i]);
                per[i]:=per[i] div 1000;
                end;
        Main;
        end;
END.