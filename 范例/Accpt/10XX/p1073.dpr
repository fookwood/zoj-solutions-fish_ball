PROGRAM p1073;

{$APPTYPE CONSOLE}



VAR
   num,sum  :array[1..60]of integer;
   long :integer;
   ch   :char;
   i    :integer;
   pack,temp :array[0..9]of integer;

FUNCTION check:boolean;
var
   i    :integer;
   add  :integer;
   step :integer;
begin
check:=true;
fillchar(pack,sizeof(pack),0);
for i:=1 to long do
    begin
    sum[i]:=num[i];
    inc(pack[sum[i]]);
    end;
step:=1;
while step<long do
begin
add:=0;
inc(step);
for i:=long downto 1 do
    begin
    add:=sum[i]+num[i]+add;
    sum[i]:=add mod 10;
    add:=add div 10;
    end;
if add=0 then
   begin
   fillchar(temp,sizeof(temp),0);
   for i:=1 to long do inc(temp[sum[i]]);
   for I:=0 to 9 do
       if temp[i]<>pack[i] then
       begin
       check:=false;
       exit;
       end;
   end else
        begin
        if step=long then
                begin
                check:=true;
                end else
                begin
                check:=false;
                exit;
                end;
        end;
end;
end;


BEGIN
while not eof do
      begin
      long:=0;
      while not eoln do
            begin
            read(ch);
            inc(long);
            num[long]:=ord(ch)-48;
            end;
      readln;
      for i:=1 to long do write(num[i]);
      if check then writeln(' is cyclic') else writeln(' is not cyclic');
      end;
END.

