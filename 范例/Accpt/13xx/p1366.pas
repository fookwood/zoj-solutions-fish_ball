PROGRAM p1366;

VAR
        max                     :Longint;
        n,a,b                   :Longint;
        get                     :array[0..100000]of Boolean;

PROCEDURE Work;
var
        crash                   :Longint;
        i,j,k                   :Longint;
begin
fillchar(get,sizeof(get),0);
get[0]:=true;
read(crash);
read(n);
for I:=1 to n do
        begin
        read(a,b);
        if not get[crash] then
        for j:=crash downto 0 do
                if get[j] then
                        for k:=1 to a do
                                begin
                                if j+b*k>crash then break;
                                get[j+b*k]:=true;
                                end;
        end;
if eoln then readln;
j:=0;
if n<>0 then
for j:=crash downto 0 do
        if get[j] then break;
writeln(j);


end;

BEGIN
//assign(input,'p.in');
//reset(input);
while not eof do Work;
END.