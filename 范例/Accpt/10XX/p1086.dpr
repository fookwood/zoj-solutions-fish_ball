program p1086;

{$APPTYPE CONSOLE}

var
        num     :array[1..10000]of integer;
        copy    :array[1..10000]of integer;
        lc      :longint;
        ln      :longint;
        la      :longint;
        ans     :array[1..10000]of integer;
        i       :longint;
        ch      :char;
        mul     :integer;
        add     :int64;
        reach   :longint;

begin
while not eof do
        begin
        read(ch,ch);
        num[1]:=1;ln:=1;
        reach:=0;
        fillchar(ans,sizeof(ans),0);
        la:=0;
        lc:=0;
        repeat
                read(ch);
                mul:=ord(ch)-48;
                inc(lc);
                copy[lc]:=mul;
                inc(reach);
                inc(la,3);
                add:=0;
                for I:=1 to ln do
                        begin
                        add:=(num[i]*125)+add;
                        num[i]:=add mod 10;
                        add:=add div 10;
                        end;

                while add>0 do
                        begin
                        inc(ln);
                        num[ln]:=add mod 10;
                        add:=add div 10;
                        end;
                for i:=ln downto 1 do
                        inc(ans[3*reach-i+1],mul*num[i]);

                add:=0;
                for I:=la downto 1 do
                        begin
                        add:=add+ans[i];
                        ans[i]:=add mod 10;
                        add:=add div 10;
                        end;
        until eoln;
        write('0.');
        for I:=1 to lc do write(copy[i]);
        write(' [8] = 0.');
        for i:=1 to la do write(ans[i]);
        writeln(' [10]');
        readln;
        end;
end.
