PROGRAM p1150;

VAR
        n,step                  :Integer;
        order,path              :array[1..7]of Integer;
        ans                     :array[1..128]of Integer;

PROCEDURE Readin;
var
        i                       :Integer;
        s                       :String;
        ch                      :Char;
begin
readln(s);
for i:=1 to n do
        begin
        order[ord(s[2])-48]:=i;
        if i<n then delete(s,1,3);
        end;

for i:=1 to trunc(power(2,n)) do
        begin
        read(ch);
        ans[i]:=ord (ch) - 48;
        end;
readln;

end;

PROCEDURE Main;
var
        t,i,p,q                 :Integer;
        ch                      :Char;
begin
readln(t);
for p:=1 to t do
        begin
        for i:=1 to n do
                begin
                read(ch);
                path[order[i]]:=ord(ch)-48;
                end;
        readln;
        q:=1;
        for i:=1 to n do
                if path[i]=0 then q:=q shl 1 else q:=q shl 1 + 1;

        write(ans[q-trunc(power(2,n))+1]);
        end;
writeln;
end;

BEGIN
//assign(input,'p.in');
//reset(input);
readln(n);
step:=0;
while (n<>0) do
        begin
        inc(step);
        writeln('S-Tree #',step,':');
        readin;
        Main;
        writeln;
        readln(n);
        end;
END.