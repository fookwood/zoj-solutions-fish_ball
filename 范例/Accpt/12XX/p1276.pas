PROGRAM p1276;

VAR
        n,step                  :Integer;
        a,b                     :array[1..10]of Integer;
        ans,chose               :array[1..10,1..10]of Longint;

PROCEDURE Print(left,right:Integer);
begin
//writeln;
//writeln(left,' ',right,' ',chose[left][right]);

if (right-left=1) then
        begin
        write('(A',left,' x A',right,')');
        end else
        begin
        if chose[left][right]=left+1 then
                begin
                write('(A',left,' x ');
                print(chose[left][right],right);
                write(')');
                end else
        if chose[left][right]=right then
                begin
                write('(');
                print(left,chose[left][right]-1);
                write(' x A',right,')');
                end else
                begin
                write('(');
                print(left,chose[left][right]-1);
                write(' x ');
                print(chose[left][right],right);
                write(')');
                end;
        end;
end;

PROCEDURE Readin;
var
        i                       :Integer;
begin
for i:=1 to n do readln(a[i],b[i]);
end;

PROCEDURE Main;
var
        i,l,j                   :Integer;
        left,right              :Integer;
        temp                    :Longint;

begin
write('Case ',step,': ');


if n=1 then
        begin
        writeln('A1');
        exit;
        end;

for i:=1 to n do ans[i][i]:=0;

for i:=1 to n-1 do
        begin
        ans[i][i+1]:=a[i]*b[i]*b[i+1];
        chose[i][i+1]:=0;
        end;

for l:=3 to n do
        for i:=1 to n-l+1 do
                begin
                left:=i;
                right:=i+l-1;

                ans[left][right]:= a[left] * b[left] * b[right]
                        + ans[left+1][right];
                chose[left][right]:=left+1;

                for j:=left+2 to right do
                        begin
                        temp:=a[left] * a[j] * b[right]
                                + ans[left][j-1] + ans[j][right];
                        if temp<ans[left][right] then
                                begin
                                ans[left][right]:=temp;
                                chose[left][right]:=j;
                                end;
                        end;
                end;

print(1,n);
writeln();
end;

BEGIN
//assign(input,'p.in');
//reset(input);
step:=0;
readln(n);
while (n<>0) do
        begin
        inc(step);
        Readin;
        main;
        readln(n);
        end;
END.
