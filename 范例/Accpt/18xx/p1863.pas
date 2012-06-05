PROGRAM p1863;

VAR
        ans,temp                        :Extended;
        p,q,r,s                         :Longint;
        i,j1,j2                         :Longint;

BEGIN
while not eof do
        begin
        readln(p,q,r,s);
        ans:=1;

        j1:=2;
        j2:=r-s+1;

        for i:=p-q+1 to p do
                begin
                ans:=ans*i;
                while (ans>j1)and(j1<=q) do
                        begin
                        ans:=ans / j1;
                        inc(j1);
                        end;
                while (ans>j2)and (j2<=r) do
                        begin
                        ans:= ans /j2;
                        inc(j2);
                        end;
                end;

        for i:=2 to s do
                begin
                ans:=ans * i;
                while (ans > j1)and(j1<=q) do
                        begin
                        ans:=ans / j1;
                        inc(j1);
                        end;
                while (ans>j2) and (j2<=r) do
                        begin
                        ans:=ans / j2;
                        inc(j2);
                        end;
                end;
        for i:=j1 to q do ans:=ans / i;
        for i:=j2 to r do ans:=ans / i;

        writeln(ans:0:5);
        end;
END.
