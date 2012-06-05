PROGRAM p1177;

TYPE
        BigNum=array[0..200000]of Longint;

VAR
        part,p,k                        :Integer;
        ans                             :BigNum;

PROCEDURE Print;
var
        i                               :Longint;
begin
for i:=1 to ans[0]-1 do
        write(ans[i]);
writeln;
end;

PROCEDURE Main;
var
        temp,i                          :Longint;
        left                            :BigNum;
begin
Ans[0]:=maxlongint;
for i:=1 to 9 do
        begin
        left[0]:=1;
        temp:=0;
        left[1]:=i;
        repeat
                temp:=temp * 10 + left[left[0]];
                inc(left[0]);
                left[left[0]]:=temp div k;
                temp:=temp mod k;
        until  (temp=0)and(left[left[0]]=i);
        if left[0]<ans[0] then ans:=left;
        end;
Print;
end;

BEGIN
readln(part);
for p:=1 to part do
        begin
        readln(k);
        Main;
        if p<part then writeln;
        end;
END.

