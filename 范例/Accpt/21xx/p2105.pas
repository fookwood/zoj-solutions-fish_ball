PROGRAM p2105;


VAR
        a,b                                     :Integer;
        n                                       :Longint;
        total                                   :Integer;
        pos                                     :array[0..6,0..6]of Integer;
        save                                    :array[1..52]of Integer;

PROCEDURE Main;
var
        i,j                                    :Integer;
        ans,l,w                                     :Longint;
begin
save[1]:=1;
save[2]:=1;
i:=3;
fillchar(pos,sizeof(pos),0);
pos[1,1]:=1;
repeat
        save[i]:=(save[i-1]*a+save[i-2]*b) mod 7;
        if pos[save[i],save[i-1]]=0 then pos[save[i],save[i-1]]:=i-1 else break;
        inc(i);
until false;

l:=i-1-pos[save[i],save[i-1]];

if n<=pos[save[i],save[i-1]] then writeln(save[n])
        else
        begin
        w:=n-pos[save[i],save[i-1]]+1;
        if w mod l=0 then writeln(save[i-2]) else
                writeln(save[(w mod l)+pos[save[i],save[i-1]]-1]);
        end;
end;

BEGIN
readln(a,b,n);
while (a<>0)or(b<>0)or(n<>0) do
        begin
        Main;
        readln(a,b,n);
        end;
END.