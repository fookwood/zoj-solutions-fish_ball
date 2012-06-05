PROGRAM p1060;

VAR
        ans,sure                        :Boolean;
        first,fa                        :Boolean;
        n,m,i                           :Integer;
        stop                            :Integer;
        max                             :Char;
        whether,cwhether                :array['A'..'Z','A'..'Z']of Boolean;
        degree,cdegree                  :array['A'..'Z']of Integer;
        ch1,ch2,ch3                     :Char;
        s                               :String;


PROCEDURE Check;
var
        many                            :Integer;
        flag                            :Boolean;
        cha,chb                         :Char;
begin

cwhether:=whether;
cdegree:=degree;

s:='';
flag:=false;

repeat
        many:=0;
        chb:=' ';
        for cha:='A' to max do
                if (degree[cha]=0)and(pos(cha,s)=0) then
                        begin
                        inc(many);
                        chb:=cha;
                        end;
        if (pos(chb,s)>0)or(chb=' ') then break;
        if many>1 then flag:=true;
        s:=s+chb;
        for cha:='A' to max do
                if whether[chb,cha] then
                        dec(degree[cha]);
until false;

whether:=cwhether;
degree:=cdegree;
if length(s)<>n then ans:=false;
if not flag then sure:=true;

end;

BEGIN
assign(output,'p.out');
rewrite(output);
assign(input,'p.in');
reset(input);
readln(n,m);
while (n<>0)or(m<>0) do
        begin

        fillchar(degree,sizeof(degree),0);
        fillchar(whether,sizeof(whether),0);

        max:=chr(n+ord('A')-1);

        ans:=true;
        sure:=false;

        first:=true;
        fa:=true;

        for i:=1 to m do
                begin
                readln(ch1,ch2,ch3);

                if not ans or sure then continue;

                if ch2='>' then
                        begin

                        if whether[ch1,ch3] then
                                ans:=false else
                        if not whether[ch3,ch1] then
                                begin
                                whether[ch3,ch1]:=true;
                                inc(degree[ch1]);
                                end;

                        end else
                        begin

                        if whether[ch3,ch1] then
                                ans:=false else
                        if not whether[ch1,ch3] then
                                begin
                                whether[ch1,ch3]:=true;
                                inc(degree[ch3]);
                                end;

                        end;
                check;

                if first and sure then
                        begin
                        if ans and sure then writeln('Sorted sequence determined after ',i,' relations: ',s,'.');
                        stop:=i;
                        first:=false;
                        end;

                if not ans and fa then
                        begin
                        fa:=false;
                        writeln('Inconsistency found after ',i,' relations.');
                        end;
                end;




        if not sure and ans then
                writeln('Sorted sequence cannot be determined.');

        readln(n,m);
        end;
close(output);
END.
