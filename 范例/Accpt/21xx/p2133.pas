PROGRAM p2133;

VAR
        part,p                          :Integer;
        n                               :Integer;
        map                             :array[1..50,1..20]of Char;
        dout,din                        :array['A'..'Z']of Integer;
        whether                         :array['A'..'Z','A'..'Z']of Boolean;
        have                            :array['A'..'Z']of Boolean;

PROCEDURE Readin;
var
        ch,e                              :Char;
        i,j                             :Integer;
begin
readln(n);
fillchar(whether,sizeof(whether),0);
fillchar(have,sizeof(have),0);
fillchar(dout,sizeof(dout),0);
fillchar(din,sizeof(din),0);
for I:=1 to n do
        begin
        for j:=1 to 20 do
                begin
                read(map[i,j]);
                if (map[i,j]>='A')and(map[i,j]<='Z') then
                        begin
                        have[map[i,j]]:=true;
                        if (i>1)and(map[i-1,j]>='A')and(map[i-1,j]<='Z') and (map[i-1,j]<>map[i,j])and(not whether[map[i-1,j],map[i,j]]) then
                                begin
                                whether[map[i-1,j],map[i,j]]:=true;
                                inc(din[map[i,j]],1);
                                inc(dout[map[i-1,j]],1);
                                end;
                        end;
                end;
        readln;
        end;
end;

PROCEDURE Topu;
var
        s                                               :String;
        total                                           :Integer;
        i,j                                             :Integer;
        ca,cb                                           :Char;
begin
total:=0;
s:='';
for ca:='A' to 'Z' do
        if have[ca] then
                inc(total);
for i:=1 to total do
        begin
        for ca:='A' to 'Z' do
        if (have[ca]) and (pos(ca,s)=0) and (dout[ca]=0) then break;
        s:=s+ca;
        for cb:='A' to 'Z' do
                if whether[cb,ca] then dec(dout[cb]);
        end;
writeln(s);
end;


BEGIN
readln(part);
for p:=1 to part do
        begin
        readln;
        readin;
        topu;
        if p<part then writeln;
        end;

END.