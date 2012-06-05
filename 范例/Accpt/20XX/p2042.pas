PROGRAM p2042;

VAR
        i                                       :Longint;
        n,part,p,temp                           :Longint;
        k                                       :Longint;
        have                                    :array[0..99]of Longint;
        make,ans                                :array[0..99,0..99]of Boolean;

PROCEDURE Main;
var
        i,j,l                                   :Longint;
        c1,c2                                   :array[0..99]of Boolean;
begin
fillchar(make,sizeof(make),0);

for i:=1 to k-1 do
        begin
        fillchar(c1,sizeof(c1),false);
        c1[0]:=true;
        for j:=1 to have[i] do
                begin
                fillchar(c2,sizeof(c2),false);
                for l:=0 to k-1 do
                if c1[l] then
                        begin
                        c2[(l+i)mod k]:=true;
                        c2[(l+k-i) mod k]:=true;
                        end;
                c1:=c2;
                end;
        move(c1[0],make[i,0],sizeof(c1));
        end;

fillchar(ans,sizeof(ans),0);
ans[0,0]:=true;
for i:=1 to k-1 do
        for j:=0 to k-1 do
                if Ans[i-1,j] then
                for L:=0 to k-1 do
                        if make[i,l] then
                                Ans[i,(j+l) mod k]:=true;
if ans[k-1,0] then
        writeln('Divisible') else
        writeln('Not divisible');
end;

BEGIN
readln(part);
for p:=1 to part do
        begin
        readln;
        readln(n,k);
        fillchar(have,sizeof(have),0);
        for i:=1 to n do
                begin
                read(temp);
                inc(have[(temp+(abs(temp div k)+2)*k) mod k]);
                end;
        readln;
        if k=1 then
                begin
                writeln('Divisible');
                continue;
                end;
        Main;
        if p<>part then writeln;
        end;
END.