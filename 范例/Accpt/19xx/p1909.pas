PROGRAM p1909;

VAR
        part                            :Integer;
        long                            :array[1..20]of Longint;
        chose                           :array[1..20]of Boolean;
        avg,statu,n                     :Longint;

PROCEDURE Sort;
var
        i,j,temp                        :Longint;

begin
fillchar(chose,sizeof(chose),0);
for i:=1 to n-1 do
        for j:=i+1 to n do
                if long[i]<long[j] then
                        begin
                        temp:=long[i];
                        long[i]:=long[j];
                        long[j]:=temp;
                        end;
end;

PROCEDURE Readin;
var
        i                               :Integer;
begin
read(n);
avg:=0;
statu:=0;
for I:=1 to n do
        begin
        read(long[i]);
        inc(avg,long[i]);
        end;
readln;
if avg mod 4<>0 then Statu:=2 else Sort;
avg:=avg div 4;
if long[n]>avg then statu:=2;
end;

PROCEDURE Search(reach,sum,dep,fill:Longint);
var
        i                               :Integer;
begin
if (dep=n)and(fill=4) then
        begin
        statu:=1;
        exit;
        end;
if sum=0 then
        begin
        for i:=1 to n do
                if not chose[i] then break;
        chose[i]:=true;
        if long[i]=avg then Search(1,0,dep+1,fill+1)
                else Search(i+1,long[i],dep+1,fill);
        chose[i]:=false;
        end else
        begin
        for i:=reach to n do
                begin
                if statu>0 then exit;
                if not chose[i] and (sum+long[i]<=avg) then
                        begin
                        if sum+long[i]=avg then
                                begin
                                chose[i]:=true;
                                Search(1,0,dep+1,fill+1);
                                chose[i]:=false;
                                break;
                                end else
                                begin
                                chose[i]:=true;
                                Search(i+1,sum+long[i],dep+1,fill);
                                chose[i]:=false;
                                end;
                        end;
                end;
        end;
end;

BEGIN
//assign(input,'p.in');
//reset(input);
readln(part);
for part:=part downto 1 do
        begin
        Readin;
        if statu=0 then Search(1,0,0,0);
        if statu=1 then writeln('yes') else writeln('no');
        end;
END.