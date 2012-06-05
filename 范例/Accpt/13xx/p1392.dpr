program p1392;

{$APPTYPE CONSOLE}

const
        pre     :array['A'..'Z']of char=(
        'V','W','X','Y','Z','A','B','C','D','E','F','G','H','I',
        'J','K','L','M','N','O','P','Q','R','S','T','U');
        s='START';
        t='END';
        finish='ENDOFINPUT';

var
        i       :integer;
        r       :string;

begin
readln(r);
while r<>finish do
        begin
        while r<>t do
                if r=s then readln(r) else
                        begin
                        for I:=1 to length(r) do
                                if (r[i]>='A')and(r[i]<='Z') then
                                        r[i]:=pre[r[i]];
                        writeln(r);
                        readln(r);
                        end;
        readln(r);
        end;
end.
 