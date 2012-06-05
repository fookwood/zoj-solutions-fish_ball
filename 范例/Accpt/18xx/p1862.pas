PROGRAM P1862;

CONST
        change                  :array[1..8,1..2]of Integer=
        ((1,0),(0,1),(-1,0),(0,-1),(1,1),(-1,-1),(1,-1),(-1,1));

VAR
        n,i,j,k                 :Integer;
        many                    :array[0..11,0..11]of Integer;
        diel                    :Boolean;
        map,try2                :array[1..10,1..10]of Char;

BEGIN
//assign(input,'p.in');
//reset(input);
while not eof do
        begin
        readln(n);
        fillchar(many,sizeof(many),0);
        for I:=1 to n do
                begin
                for J:=1 to n do
                        begin
                        read(map[i,j]);
                        if map[i,j]='*' then
                                for k:=1 to 8 do inc(many[i+change[k,1],j+change[k,2]]);
                        end;
                readln;
                end;
        diel:=false;

        for i:=1 to n do
                begin
                for j:=1 to n do
                        begin
                        read(try2[i,j]);
                        if (map[i,j]='*')and(try2[i,j]='x') then
                                diel:=true;
                        end;
                readln;
                end;

        if diel then
                begin
                for I:=1 to n do
                        begin
                        for J:=1 to n do
                                if map[i,j]<>'*' then
                                        begin
                                        if try2[i,j]='x' then write(many[i,j]) else write('.');
                                        end else
                                        write('*');
                        writeln;
                        end;
                end else
                begin
                for i:=1 to n do
                        begin
                        for J:=1 to n do
                                if try2[i,j]='x' then write(many[i,j])
                                        else write('.');
                        writeln;
                        end;
                end;
        if not eof then writeln;
        end;
END.