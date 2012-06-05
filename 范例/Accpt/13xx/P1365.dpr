program P1365;

{$APPTYPE CONSOLE}


var
        money   :real;
        s       :string;
        kind    :char;
        d       :real;
        code    :integer;
        j       :integer;
begin
readln(s);
while s<>'#' do
        begin
        money:=0;
        while s<>'0' do
                begin
                kind:=s[length(s)];
                delete(s,length(s)-1,2);
                j:=length(s);
                while s[j]<>' ' do dec(j);
                s:=copy(s,j+1,length(s)-j);
                val(s,d,code);
                case kind of
                        'F'     :money:=money+d*2;
                        'B'     :money:=money+d+d/2;
                        'Y'     :begin
                                if d<=500 then money:=money+500 else
                                        money:=money+d;
                                end;
                end;{case}
                readln(s);
                end;
        if trunc(money)=money then writeln(money:0:0)
                else writeln(money:0:1);
        readln(s);
        end;
end.
 