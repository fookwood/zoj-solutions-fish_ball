PROGRAM p1496;

VAR
        f,r,i,j,part,p                          :Longint;
        min,goal                                :Extended;
        diameter,target                         :Longint;
        ff                                      :array[1..3]of Longint;
        rr                                      :array[1..9]of Longint;

BEGIN
//assign(input,'p.in');
//reset(input);
readln(part);
for p:=1 to part do
        begin
        for i:=1 to 3 do read(ff[i]);
        for i:=1 to 9 do read(rr[i]);
        readln(diameter,target);
        min:=999999;
        for i:=1 to 3 do for j:=1 to 9 do
                if abs(ff[i]/rr[j]*pi*diameter-target)<min then
                        begin
                        min:=abs(ff[i]/rr[j]*pi*diameter-target);
                        f:=i;
                        r:=j;
                        end;
        writeln('A gear selection of ',ff[f],'/',rr[r],' produces a gear size of ',ff[f]/rr[r]*pi*diameter:0:3,'.');
        if p<part then writeln;
        end;
END.
