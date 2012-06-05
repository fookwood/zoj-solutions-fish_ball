PROGRAM p2402;

VAR
        maxm                    :Integer;
        part,p                  :Integer;
        n,m                     :Integer;
        ans                     :array[0..10,0..2000]of Int64;

PROCEDURE Dp;
var
        i,j,k,s                 :Integer;
begin
maxm:=2000;
for i:=0 to 2000 do ans[0][i]:=1;
for i:=1 to 10 do
        for j:=1 to maxm do
                begin
                ans[i][j]:=ans[i][j-1];
                ans[i][j]:=ans[i][j]+ans[i-1][j div 2];
                end;

end;

BEGIN
Dp;
readln(part);
for p:=1 to part do
        begin
        readln(n,m);
        writeln('Case ',p,': n = ',n,', m = ',m,', # lists = ',ans[n][m]);
        end;
END.