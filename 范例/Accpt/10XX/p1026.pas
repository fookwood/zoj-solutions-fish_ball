PROGRAM p1026;

CONST
        max=10000;

VAR
        k,ci    :longint;
        n       :longint;
        i,j       :longint;
        x1,x2,x3,x4        :array[0..max+1]of longint;

BEGIN
readln(k);
for ci:=1 to k do
        begin
        read(x1[max+1]);
        for i:=x1[max+1]-1 downto 0 do
                read(x1[i]);
        readln();
        read(x2[max+1]);
        for i:=x2[max+1]-1 downto 0 do
                read(x2[i]);
        readln();
        read(x3[max+1]);
        for i:=x3[max+1]-1 downto 0 do
                read(x3[i]);
        readln();
        fillchar(x4,sizeof(x4),0);
        x4[max+1]:=x1[max+1]+x2[max+1];
        for i:=0 to x1[max+1]-1 do
                for j:=0 to x2[max+1]-1 do
                        x4[i+j]:=(x4[i+j]+x1[i]*x2[j]) mod 2;
        for i:=x4[max+1]-1 downto x3[max+1]-1 do
                begin
                if x4[i]=0 then continue;
                for j:=i downto i-x3[max+1]+1 do
                        x4[j]:=(x4[j]-x3[j-i+x3[max+1]-1]+2) mod 2;
                end;
        while x4[x4[max+1]-1]=0 do dec(x4[max+1]);
        write(x4[max+1],' ');
        for i:=x4[max+1]-1 downto 1 do write(x4[i],' ');
        writeln(x4[0]);
        end;
END.
