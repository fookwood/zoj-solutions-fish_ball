PROGRAM p1084;

VAR
        n,i                             :Integer;
        ch1,ch2                         :Char;
        edge                            :array[1..26,0..26]of Integer;
        whether,col                     :array[1..26,1..26]of Boolean;
        chose                           :array[1..26]of Boolean;
        ans,total                       :array[1..26]of Integer;


PROCEDURE Main;
var
        i,j,k,max,answer                :Integer;
begin
for i:=1 to n do
        for J:=1 to n do
                if whether[i,j] then
                        begin
                        inc(edge[i,0]);
                        edge[i,edge[i,0]]:=j;
                        end;


answer:=0;

for i:=1 to n do
        begin
        max:=-1;
        for J:=1 to n do
                if (ans[j]=0)and(total[j]>max) then
                        begin
                        max:=total[j];
                        k:=j;
                        end;
        for j:=1 to n do
                if not col[k,j] then break;
        ans[k]:=j;
        if not chose[ans[k]] then
                begin
                chose[ans[k]]:=true;
                inc(answer);
                end;
        for j:=1 to edge[k,0] do
                if (ans[edge[k,j]]=0)and(not col[edge[k,j],ans[k]]) then
                        begin
                        inc(total[j]);
                        col[edge[k,j],ans[k]]:=true;
                        end;
        end;



if answer=1 then writeln(answer,' channel needed.') else
        writeln(answer,' channels needed.');
end;

BEGIN
readln(n);
while (n<>0) do
        begin
        fillchar(edge,sizeof(edge),0);
        fillchar(whether,sizeof(whether),0);
        fillchar(col,sizeof(col),0);
        fillchar(ans,sizeof(ans),0);
        fillchar(total,sizeof(total),0);
        fillchar(chose,sizeof(chose),0);
        for i:=1 to n do
                begin
                read(ch1,ch2);
                while not eoln do
                        begin
                        read(ch2);
                        whether[ord(ch1)-ord('A')+1,ord(ch2)-ord('A')+1]:=true;
                        whether[ord(ch2)-ord('A')+1,ord(ch1)-ord('A')+1]:=true;
                        end;
                readln;
                end;
        Main;
        readln(n);
        end;
END.
