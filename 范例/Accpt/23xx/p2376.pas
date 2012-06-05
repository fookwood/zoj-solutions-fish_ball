PROGRAM p2376;

VAR
        part,p                  :Longint;
        board,max1,max2         :Longint;
        i,a,b,c                 :Longint;

BEGIN
readln(part);
for p:=1 to part do
        begin
        readln(board,a);
        max1:=0;
        max2:=0;
        for i:=1 to a do
                begin
                read(b);
                c:=board-b;
                if b>c then
                        begin
                        if b>max2 then max2:=b;
                        if c>max1 then max1:=c;
                        end else
                        begin
                        if b>max1 then max1:=b;
                        if c>max2 then max2:=c;
                        end;
                end;
        writeln(max1,' ',max2);
        end;
END.