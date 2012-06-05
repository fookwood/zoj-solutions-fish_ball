PROGRAM p2002;

VAR
        part,p                  :Integer;
        n,i,d,j                 :Integer;
        l,r                     :Integer;
        data                    :array[1..500]of Longint;
        sum                     :array[0..500]of Longint;
        save,line               :array[1..501]of Integer;


FUNCTION Check(mid:Integer):Boolean;
var
        i,j                     :Integer;
begin
line[d+1]:=n;
for i:=d downto 2 do
        begin
        for J:=line[d+1]-1 downto i-1 do
                if sum[line[i+1]]-sum[j]>mid  then break;
        if sum[line[i+1]]-sum[j]>mid then inc(j);
        if j>line[d+1]-1 then
                begin
                check:=false;
                exit;
                end;
        line[i]:=j;
        end;
line[1]:=0;
if sum[line[2]]-sum[0]>mid then
        begin
        check:=false;
        exit;
        end;
check:=true;
end;

PROCEDURE Search(Left,right:Integer);
var
        mid                     :Integer;
begin
if left>right then exit;
mid:=(left+right) div 2;
if check(mid) then begin
        save:=line;
        Search(left,mid-1);
        end else Search(mid+1,right);
end;

BEGIN
readln(part);
for p:=1 to part do
        begin
        readln(n,d);
        sum[0]:=0;
        for i:=1 to n do
                begin
                read(data[i]);
                sum[i]:=sum[i-1]+data[i];
                end;
        l:=1;r:=sum[n];
        search(l,r);
        j:=2;
        for i:=1 to n-1 do
                begin
                write(data[i],' ');
                if (j<=d)and(save[j]=i) then
                        begin
                        inc(j);
                        write('/ ');
                        end;
                end;
        writeln(data[n]);
        end;
END.
