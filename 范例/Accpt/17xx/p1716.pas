PROGRAM p1716;

VAR
        total,sa,sb,h,w         :Integer;
        map                     :array[1..500,1..500]of 0..1;
        partsum,ans             :array[0..500,0..500]of Integer;

PROCEDURE Readin;
var
        i,a,b,j                 :Integer;
begin
fillchar(partsum,sizeof(partsum),0);
fillchar(ans,sizeof(ans),0);
fillchar(map,sizeof(map),0);
readln(h,w);
for i:=1 to total do
        begin
        readln(a,b);
        map[a][b]:=1;
        end;
for i:=1 to h do
        for j:=1 to w do
                if map[i][j]=1 then partsum[i][j]:=partsum[i][j-1]+1
                        else partsum[i][j]:=partsum[i][j-1];
readln(sa,sb);
end;

PROCEDURE Main;
var
        i,j,answer                              :Integer;
begin
if (sa>h)or(sb>w) then
        begin
        writeln(0);
        exit;
        end;
answer:=0;
for j:=sb to w do
        begin
        for i:=1 to sa do
                ans[sa][j]:=ans[sa][j]+partsum[i][j]-partsum[i][j-sb];
        if ans[sa][j]>answer then answer:=ans[sa][j];
        end;
for i:=sa+1 to h do
        for j:=sb to w do
                begin
                ans[i][j]:=ans[i-1][j]-partsum[i-sa][j]+partsum[i-sa][j-sb]+partsum[i][j]-partsum[i][j-sb];
                if ans[i][j]>answer then answer:=ans[i][j];
                end;
writeln(answer);
end;

BEGIN
//assign(input,'p.in');
//reset(input);
readln(total);
while (total<>0) do
        begin
        Readin;
        Main;
        readln(total);
        end;
END.