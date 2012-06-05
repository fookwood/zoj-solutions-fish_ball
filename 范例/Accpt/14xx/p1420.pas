PROGRAM p1420;

CONST
        infinity=60000;

VAR
        num,s,r                 :array[-1..23]of Longint;
        n,part                  :Longint;

PROCEDURE Readin;
var
        i,a                     :Longint;
begin
for i:=0 to 23 do read(num[i]);
readln;
readln(n);
fillchar(r,sizeof(r),0);
for i:=1 to n do
        begin
        readln(a);
        inc(R[a]);
        end;
end;

FUNCTION check(v:Longint):Boolean;
var
        be                      :Boolean;
        i,j,min                 :Longint;
begin
check:=false;
for i:=0 to 23 do s[i]:=infinity;
s[23]:=v;
for j:=1 to 23 do
        begin
        be:=false;
        if s[0]>r[0] then
                begin
                s[0]:=r[0];
                be:=true;
                end;
        for I:=23 downto 8 do
                if (s[i-8]-s[i]>-num[i])and(abs(s[i]-num[i])<infinity) then
                        begin
                        s[i-8]:=s[i]-num[i];
                        be:=true;
                        end;
        for i:=0 to 7 do
                if (s[i+16]-s[i]>v-num[i])and(abs(s[i]+v-num[i])<infinity) then
                        begin
                        s[i+16]:=s[i]+v-num[i];
                        be:=true;
                        end;
        for i:=23 downto 1 do
                if (s[i-1]-s[i]>0)and(abs(s[i])<infinity) then
                        begin
                        s[i-1]:=s[i];
                        be:=true;
                        end;
        for i:=23 downto 1 do
                if (s[i]-s[i-1]>r[i])and(abs(s[i-1]+r[i])<infinity) then
                        begin
                        s[i]:=s[i-1]+r[i];
                        be:=true;
                        end;
        if not be then break;
        end;

if s[23]<>v then exit;
if s[0]>r[0] then exit;
for i:=23 downto 8 do
        if (s[i-8]-s[i]>-num[i]) then exit;
for i:=0 to 7 do
        if (s[i+16]-s[i]>v-num[i]) then exit;
for i:=23 downto 1 do
        if (s[i-1]-s[i]>0) then exit;
for i:=23 downto 1 do
        if s[i]-s[i-1]>r[i] then exit;

check:=true;
end;

PROCEDURE Main;
var
        ans                     :Boolean;
        i                       :Longint;
        left,right,mid          :Longint;
begin
left:=0;
right:=n;
while (left<right) do
        begin
        mid:=(left+right) div 2;
        if check(mid) then
                begin
                right:=mid;
                end else left:=mid+1;
        end;
if check(left) then writeln(left)
else if check(right) then writeln(right)
        else writeln('No Solution');
end;

BEGIN
//assign(input,'p.in');
//reset(input);
readln(part);
for part:=part downto 1 do
        begin
        Readin;
        Main;
        end;
END.
