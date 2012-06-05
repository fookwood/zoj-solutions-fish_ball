PROGRAM p1579;

VAR
        n,i,temp                        :Longint;
        data                            :array[1..100000]of int64;

PROCEDURE Swap(var a,b:Int64);
var
        temp                            :Int64;
begin
temp:=a;
a:=b;
b:=temp;
end;

FUNCTION Partition(left,right:Longint;key:Int64):Longint;
var
        i,j                             :Longint;
begin
i:=left-1;
j:=right+1;
while true do
        begin
        repeat j:=j-1 until data[j]<=key;
        repeat i:=i+1 until data[i]>=key;
        if i<j then swap(data[i],data[j])
                else
                begin
                Partition:=j;
                exit;
                end;
        end;
end;

PROCEDURE Qsort(left,right:Longint);
var
        q                               :Longint;
begin
if left<right then
        begin
        q:=Partition(left,right,data[left]);
        Qsort(left,q);
        Qsort(q+1,right);
        end;
end;

PROCEDURE Main;

var

        ans,a1,a2                                 :Int64;
begin
ans:=0;
while n>=4 do
        begin
        a1:=data[2]+data[2]+data[1]+data[n];
        a2:=data[n-1]+data[n]+data[1]+data[1];
        if a1<a2 then inc(ans,a1) else inc(ans,a2);
        dec(n,2);
        end;
if n<=2 then
        inc(ans,data[n]);
if n=3 then
        inc(ans,data[1] + data[2] + data[3]);
writeln(ans);
end;

BEGIN
//assign(input,'p.in');
//reset(input);
while not eof do
        begin
        readln(n);
        for I:=1 to n do
                begin
                read(temp);
                data[i]:=temp;
                end;
        readln;
        if n=0 then
                begin
                writeln(0);
                continue;
                end;
        Qsort(1,n);
        Main;
        end;
END.
