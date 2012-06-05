PROGRAM p1880;

TYPE
        Tnum = array[1..100] of Longint;

VAR
        n , i , nd , j , temp   : Integer;
        sum1 , sum2             : Longint;
        num                     : Tnum;
        change                  : Boolean;

BEGIN
//assign(input,'p.in');
//reset(input);

while not eof do
        begin
        readln ( n );
        for i:= 1 to n do readln ( num [i] );

        sum1 := 0;
        sum2 := 0;
        nd := n div 2;
        for i:=1 to nd do sum1 := sum1 + num [i];
        for i:= nd + 1 to n do sum2 := sum2 + num [i];

        while true do
                begin
                change := false;

                for i:=1 to nd do
                        for j:= nd + 1 to n do
                                if abs (( sum1 + num [i] - num [j] ) - ( sum2 - num [i] + num [j] )) < abs ( sum1 - sum2 ) then
                                        begin
                                        sum1 := sum1 + num [i] - num [j];
                                        sum2 := sum2 - num [i] + num [j];
                                        temp := num [i];
                                        num [i] := num [j];
                                        num [j] := temp;
                                        change := true;
                                        end;

                if not change then
                        begin
                        if sum2 < sum1 then
                                begin
                                temp := sum1;
                                sum1 := sum2;
                                sum2 := temp;
                                end;
                        break;
                        end ;
                end;
        writeln ( sum1 , ' ' , sum2 );
        end;
END.