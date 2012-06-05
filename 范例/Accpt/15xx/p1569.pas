PROGRAM p1569;

VAR
        i     :integer;
        temp  :integer;
        sum   :longint;
        ans   :longint;
        n,m   :integer;
        leave :array[0..5000]of longint;
BEGIN
        while not eof do
        begin
        fillchar(leave,sizeof(leave),0);
        readln(n,m);
        sum:=0;
        for I:=1 to n do
        begin
        read(temp);
        sum:=(sum+temp) mod m;
        inc(leave[sum]);
        end;
        ans:=0;
        for i:=0 to m-1 do
         begin
         if leave[i] mod 2=0 then
             ans:=ans+((leave[i] div 2)*(leave[i]-1))
                            else
             ans:=ans+(((leave[i]-1) div 2)*leave[i]);
         end;
        ans:=ans+leave[0];
        writeln(ans);
 	 readln;
        end;
END.