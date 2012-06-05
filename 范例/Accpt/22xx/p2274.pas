PROGRAM p2274;

VAR
        n,i,j,k                                 :Integer;
        ans                                     :Longint;
        num                                     :array[1..500]of Longint;
        total                                   :array[1..500,0..1]of Longint;

FUNCTION prime(a,b:Longint):Boolean;
begin
if a=0 then
        begin
        if b=1 then prime:=true else prime:=false;
        end else
        prime:=prime(b mod a,a);
end;

PROCEDURE Main;
var
        flag                            :Boolean;
        i,j,c                           :Integer;
        ans,d                           :Longint;
begin
for i:=1 to n-1 do
        for j:=i+1 to n do
                begin
                if num[i]>num[j] then flag:=prime(num[j],num[i])
                        else flag:=prime(num[i],num[j]);
                if flag then c:=1 else c:=0;
                inc(total[i][c]);
                inc(total[j][c]);
                end;

ans:=1;
for i:=1 to 3 do
        ans:=ans * (n-i+1) div i;
d:=0;
for I:=1 to n do
        inc(d,total[i][0] * total[i][1]);
ans:=ans - d div 2;
writeln(ans);
end;

BEGIN
//assign(input,'p.in');
//reset(input);
while not eof do
        begin
        readln(n);
        for i:=1 to n do read(num[i]);
        readln;
        fillchar(total,sizeof(total),0);
        Main;
        end;
END.