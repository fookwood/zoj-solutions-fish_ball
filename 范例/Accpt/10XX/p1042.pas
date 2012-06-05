PROGRAM p1042;

VAR
        s       :string;
        pos     :array[0..180]of longint;
        save    :array[0..180]of char;
        k1,k2,k3        :longint;

PROCEDURE main;
var
        i,j     :integer;
begin
j:=-1;
for I:=1 to length(s) do
        if (s[i]>='a')and(s[i]<='i') then
        begin
        inc(j);
        pos[j]:=i;
        save[j]:=s[i];
        end;
for I:=0 to j do
        s[pos[i]]:=save[(i+(j+1)*k1-k1)mod (j+1)];

j:=-1;
for I:=1 to length(s) do
        if (s[i]>='j')and(s[i]<='r') then
        begin
        inc(j);
        pos[j]:=i;
        save[j]:=s[i];
        end;
for I:=0 to j do
        s[pos[i]]:=save[(i+(j+1)*k2-k2) mod (j+1)];

j:=-1;
for I:=1 to length(s) do
        if ((s[i]>='s')and(s[i]<='z'))or(s[i]='_') then
        begin
        inc(j);
        pos[j]:=i;
        save[j]:=s[i];
        end;
for I:=0 to j do
        s[pos[i]]:=save[(i+(j+1)*k3-k3)mod (j+1)];

writeln(s);
end;



BEGIN
readln(k1,k2,k3);
while (k1<>0)or(k2<>0)or(k3<>0) do
        begin
        readln(s);
        main;
        readln(k1,k2,k3);
        end;
END.