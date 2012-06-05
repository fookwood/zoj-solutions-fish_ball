program p1949;

{$APPTYPE CONSOLE}



var
        map     :array[1..100,1..100]of 0..1;
        n       :integer;
        h,s     :array[1..100]of 0..1;
        i,j     :Integer;
        ho,so   :integer;
        x,y     :integer;

begin
readln(n);
while n<>0 do
        begin
        for i:=1 to n do
                begin
                for J:=1 to n do read(map[i,j]);
                readln;
                end;
        for I:=1 to n do
                begin
                h[i]:=0;
                for j:=1 to n do
                        if map[i,j]=1 then
                        begin
                        if h[i]=0 then h[i]:=1 else h[i]:=0;
                        end;
                s[i]:=0;
                for j:=1 to n do
                        if map[j,i]=1 then
                        begin
                        if s[i]=0 then s[i]:=1 else s[i]:=0;
                        end;
                end;

        ho:=0;so:=0;
        for I:=1 to n do
                begin
                if h[i]=1 then
                        begin
                        x:=i;
                        inc(ho);
                        end;
                if s[i]=1 then
                        begin
                        y:=i;
                        inc(so);
                        end;
                end;
        if (ho=0)and(so=0) then
                writeln('OK') else
                begin
                if (so=1)and(ho=1) then
                   writeln('Change bit (',x,',',y,')')
                        else writeln('Corrupt');
                end;
        readln(n);
        end;
end.
 