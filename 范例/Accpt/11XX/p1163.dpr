program p1163;

{$APPTYPE CONSOLE}
var
        ans     :array[0..500,0..500]of int64;
        quit,save:array[1..500]of int64;
        t       :integer;
        sum     :int64;
        n       :integer;

PROCEDURE make;
var
        i,j     :integer;
        k       :integer;
begin
fillchar(save,sizeof(save),0);
fillchar(ans,sizeof(ans),0);
for i:=1 to 500 do
        begin
        ans[i,i]:=1;
        quit[i]:=0;
        for j:=trunc((-1+sqrt(1+8*i))/2) to i-1 do
                begin
                ans[i,j]:=0;
                save[i-j]:=save[i-j]+ans[i-j,j-1];
                ans[i,j]:=save[i-j];
                {for k:=trunc((-1+sqrt(1+8*(i-j)))/2) to j-1 do ans[i,j]:=ans[i,j]+ans[i-j,k];
                }quit[i]:=quit[i]+ans[i,j];
                end;
        end;
end;

begin
make;
readln(n);
{while n<>0 do
        begin
        sum:=0;
        for t:=1 to n-1 do sum:=sum+ans[n,t];
        writeln(sum);
        readln(n);

        end;            }
while n<>0 do
        begin
        writeln(quit[n]);
        readln(n);
        end;

end.
