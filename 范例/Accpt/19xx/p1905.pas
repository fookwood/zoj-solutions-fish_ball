PROGRAM p1905;

VAR
        data    :array[1..1100000]of char;
        long    :longint;
        i       :longint;
        j       :longint;
        ans     :longint;
        find    :boolean;
        equl    :boolean;
        k       :longint;

BEGIN
read(data[1]);
while data[1]<>'.' do
        begin
        long:=1;
        if not eoln then
                repeat
                inc(long);
                read(data[long]);
                until eoln;
        readln;
        i:=1;
        ans:=0;
        find:=false;
        while not find do
                begin
                if long mod i=0 then
                        begin
                        equl:=true;
                        for j:=2 to long div i do
                                begin
                                for k:=1 to i do
                                        if data[(j-1)*i+k]<>data[(j-2)*i+k] then
                                        begin
                                        equl:=false;
                                        break;
                                        end;
                                if not equl then break;
                                end;
                        if equl then
                                begin
                                find:=true;
                                ans:=long div i;
                                end;
                        i:=i*(j-1)+k;
                        end else inc(i);
                end;
        writeln(ans);
        read(data[1]);
        end;
END.