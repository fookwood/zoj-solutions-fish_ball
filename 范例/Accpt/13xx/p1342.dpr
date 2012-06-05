program p1342;

{$APPTYPE CONSOLE}

const
        max=83681;

var
        dic     :array[1..max]of string[5];
        s       :string;

FUNCTION check(left,right:longint):longint;
var
        mid     :Longint;
begin
if dic[right]=s then check:=right else
        begin
        mid:=(left+right) div 2;
        if dic[mid]<s then check:=check(mid,right)
                else check:=check(left,mid);
        end;
end;

FUNCTION find:longint;
var
        i       :integer;
begin
for I:=2 to length(s) do if s[i]<=s[i-1] then
        begin
        find:=0;
        exit;
        end;
for i:=1 to 5-length(s) do s:='`'+s;
find:=check(1,max);
end;

PROCEDURE makedic;
var
        i       :longint;
        j       :integer;
        c       :integer;
begin
dic[1]:='````a';
for i:=2 to max do
        begin
        j:=5;
        dic[i]:=dic[i-1];
        while dic[i][j]='z' do dec(j);
        while ord('z')-ord(dic[i][j])<=5-j do dec(j);
        dic[i][j]:=chr(ord(dic[i][j])+1);
        for c:=j+1 to 5 do
                dic[i][c]:=chr(ord(dic[i][c-1])+1);
        end;
end;

begin
makedic;
while not eof do
        begin
        readln(s);
        writeln(find);
        end;
end.
