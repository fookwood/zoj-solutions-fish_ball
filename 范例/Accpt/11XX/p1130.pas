PROGRAM p1130;

VAR
        order                           :array[0..15]of Longint;
        n,k                             :Integer;
        total,l                         :Longint;
        whether                         :array[0..32768]of Boolean;
        dne                             :array[0..32768]of Boolean;
        ans                             :array[1..65536]of Longint;

PROCEDURE Search(p:Longint);
begin
if not dne[(p*2) mod total] then
        begin
        dne[(p*2) mod total]:=true;
        Search((p*2) mod total);
        end;
if not dne[(p*2) mod total+1] then
        begin
        dne[(p*2) mod total+1]:=true;
        Search((p*2) mod total+1);
        end;
inc(l);
ans[l]:=p;
end;

PROCEDURE Main;
var
        i,j                             :Integer;
begin
fillchar(dne,sizeof(dne),0);
fillchar(whether,sizeof(whether),0);
ans[1]:=0;
total:=order[n];
l:=0;
search(0);
writeln(ans[l-1-k]);
end;

PROCEDURE MakeOrder;
var
        i                               :Integer;
begin
order[0]:=1;
for i:=1 to 15 do order[i]:=order[i-1]*2;
end;

BEGIN
//assign(input,'p.in');
//reset(input);
MakeOrder;
readln(n,k);
while (n<>0) or (k<>0) do
        begin
        Main;
        readln(n,k);
        end;
END.