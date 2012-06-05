program p1244;

{$APPTYPE CONSOLE}


var
        volu    :array['a'..'z']of integer;
        have    :boolean;
        ch      :char;
        max     :char;
        n,i     :Integer;
        step    :integer;
        s       :string;
begin
readln(n);
step:=0;
while n<>0 do
        begin
        inc(step);
        fillchar(volu,sizeof(volu),0);
        volu['a']:=1;
        for I:=1 to n do
                begin
                readln(s);
                volu[s[1]]:=volu[s[5]];
                end;
        have:=false;
        writeln('Program #',step);
        for max:='a' to 'z' do
                if volu[max]=1 then
                        begin
                        have:=true;
                        write(max,' ');
                        end;
        if not have then writeln('none') else writeln;
        writeln;
        readln(n);
        end;
end.
