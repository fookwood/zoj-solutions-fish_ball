PROGRAM p1950;

VAR
        ans                     :array[1..16,1..5,1..16]of Extended;
        name                    :array[1..16]of String;
        order                   :array[1..16,1..16]of Extended;

PROCEDURE Readin;
var
        i,j                     :Integer;
begin
if eof then halt;
for i:=1 to 16 do
        begin
        readln(name[i]);
        while length(name[i])<10 do name[i]:=name[i]+' ';
        while length(name[i])>10 do delete(name[i],length(name[i]),1);
        end;
for i:=1 to 16 do
        begin
        for j:=1 to 16 do
                begin
                read(order[i][j]);
                order[i][j]:=order[i][j] / 100;
                end;
        readln;
        end;
end;

PROCEDURE Main;
var
        i,j,k1,k2               :Integer;
begin
fillchar(ans,sizeof(ans),0);
for i:=1 to 16 do ans[i,5,i]:=1;
for i:=4 downto 1 do
        begin
        for j:=1 to trunc(exp(ln(2)*(i-1))) do
                begin
                for k1:=1 to 16 do
                        for k2:=1 to 16 do
                                if (k1<>k2) then
                                begin
                                ans[k1][i][j]:=ans[k1][i][j]+ans[k1][i+1][2*j]*ans[k2][i+1][2*j-1]*order[k1][k2]
                                        +ans[k2][i+1][2*j]*ans[k1][i+1][2*j-1]*order[k1][k2];
                                end;
                end;
        end;
for i:=1 to 16 do
        writeln(name[i],' ','p=',ans[i][1][1]*100:0:2,'%');
end;

BEGIN
//assign(input,'p.in');
//reset(input);
while true do
        begin
        readIn;
        Main;
        end;
END.
