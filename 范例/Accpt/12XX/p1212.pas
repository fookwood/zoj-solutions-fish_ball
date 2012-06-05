{$IFDEF DEBUG}
  {$I+,Q+,R+,S-}
{$ENDIF DEBUG}

PROGRAM p1212;

TYPE
        Tnum    =       array[0..7]of Real;

VAR
        total , i       : Longint;
        Up , Long       : Real;
        A , D           : Tnum;


BEGIN
//assign( input , 'p.in' );
//reset ( input );
writeln ( 'Problem 6 by team x' );
while not eof do
        begin
        total := 0;

        read ( A [ total ] );
        A [ total ] := A [ total ] * pi / 180;

        while not eoln do
                begin
                read ( D [ total ] );
                inc ( total );
                read ( A [ total ] );
                A [ total ] := A [ total ] * pi / 180;
                end;

        Up := 0 ;
        Long := 0;

        writeln;

        for i:= 0 to total - 1 do
                begin
                Long := Long + D [i] * cos ( A [i] );
                Up := Up + D [i] * sin ( A [i] );
                writeln ( 'Altitude of peak ' , i + 1 , ' =' , Up : 7 : 1 );
                end;

        Long := Long - Up * cos ( A [total] ) / sin ( A [ total ] ) ;


        writeln ( 'Pipeline length    =' , Long : 7 : 1 );
        readln;
        end;
writeln ( 'End of problem 6 by team x' );
END.
