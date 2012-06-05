PROGRAM p1463;

VAR
        f                       :Text;
        part,p                  :Integer;
        order                   :String;
        ans                     :array[1..100,0..100]of String;
        temp                            :String;
PROCEDURE Main;
var
        l,i,k                   :Integer;
        temp                    :String;
begin
for i:=1 to length(order) do begin
        ans[i][0]:='';
        case order[i] of
                '('             :ans[i][1]:='()';
                ')'             :ans[i][1]:='()';
                '['             :ans[i][1]:='[]';
                ']'             :ans[i][1]:='[]';
        end;
        end;
for l:=2 to length(order) do
        for i:=1 to length(order)-l+1 do
                begin
                ans[i][l]:=ans[i][1]+ans[i+1][l-1];
                for k:=2 to l-1 do
                        begin
                        temp:=ans[i][k]+ans[i+k][l-k];
                        if length(temp)<length(ans[i][l]) then
                                ans[i][l]:=temp;
                        end;
                if (((order[i]='[') and (order[i+l-1]=']'))
                   or ((order[i]='(') and (order[i+l-1]=')')))
                   and (length(ans[i+1][l-2])+2<length(ans[i][l])) then
                        ans[i][l]:=order[i]+ans[i+1][l-2]+order[i+l-1];
                end;
writeln(ans[1][length(order)]);
end;

BEGIN
//assign(input,'p.in');
//reset(input);
{for p:=0 to 3 do
        begin
        assign(f,'bracket.1'+chr(p+48));
        reset(f);
        readln(f,order);
        close(f);
        main;
        temp:=ans[1][length(order)];
        assign(f,'bracket.1'+chr(p+48)+'a');
        reset(f);
        readln(f,order);
        close(f);
        if length(temp)=length(order) then writeln('yes') else writeln('no');
        end;
}
readln(part);
for p:=1 to part do
        begin
        readln;
        readln(order);
        Main;
        if p<part then writeln;
        end;
END.
