PROGRAM P1824;

CONST
        change                  :array[0..3,1..2]of Integer=
        ((-1,0),(0,1),(1,0),(0,-1));

VAR
        ch                              :Char;
        order                           :Set of Char;
        h,w                             :Longint;
        i,j,x,y,face                    :Longint;
        map                             :array[1..5000,1..5000]of Char;

BEGIN
//assign(input,'p.in');
//reset(input);
order:=['L','R','F'];
while not eof do
        begin
        face:=0;
        readln(h,w);
        for I:=1 to h do
                begin
                for J:=1 to w do
                        read(map[i,j]);
                readln;
                end;
        read(x,y);
        read(ch);
        while ch<>'Q' do
                begin
                if ch in order then
                        begin
                        if ch='L' then face:=(face+3) mod 4;
                        if ch='R' then face:=(face+1) mod 4;
                        if ch='F' then
                                begin
                                i:=x+change[face,1];
                                j:=y+change[face,2];
                                if (i>=1)and(i<=h)and(j>=1)and(j<=w)and(map[i,j]<>'*') then
                                        begin
                                        x:=i;
                                        y:=j;
                                        end;
                                end;
                        end;
                read(ch);
                end;
        write(x,' ',y,' ');
        case face of
        0               :writeln('N');
        1               :writeln('E');
        2               :writelN('S');
        3               :writeln('W');
        end;
        if not eof then readln;
        end;
END.