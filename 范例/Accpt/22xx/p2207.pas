PROGRAM p2207;

VAR
        n,i,j,min                       :Integer;
        ans,goal                        :String[5];
        data                            :array[1..100]of String[5];
        appear                          :array['A'..'E']of Boolean;
        pos                             :array[0..100,'A'..'E']of Integer;

PROCEDURE check;
var
        i                               :Integer;
        ch1,ch2                         :Char;
        dis                             :Integer;
begin
dis:=0;
for I:=1 to 5 do
        pos[0,goal[i]]:=i;
for i:=1 to n do
        for ch1:='A' to 'E' do
                for ch2:=succ(ch1) to 'E' do
                        if ((pos[0,ch1]>pos[0,ch2])and(pos[i,ch1]<pos[i,ch2]))
                        or((pos[0,ch1]<pos[0,ch2])and(pos[i,ch1]>pos[i,ch2])) then inc(dis);
if dis<min then
        begin
        min:=dis;
        ans:=goal;
        end;
end;

PROCEDURE Search(dep:Integer);
var
        ch                              :Char;
begin
if dep=6 then
        begin
        check;
        exit;
        end;
for ch:='A' to 'E' do
        if not appear[ch] then
                begin
                appear[ch]:=true;
                goal[dep]:=ch;
                Search(dep+1);
                appear[ch]:=false;
                end;
end;


BEGIN
readln(n);
while n<>0 do
        begin
        fillchar(appear,sizeof(appear),0);
        goal:='12345';
        min:=maxint;
        for i:=1 to n do
                begin
                readln(data[i]);
                for j:=1 to 5 do pos[i,data[i][j]]:=j;
                end;
        Search(1);
        writeln(ans,' is the median ranking with value ',min,'.');
        readln(n);
        end;
END.
