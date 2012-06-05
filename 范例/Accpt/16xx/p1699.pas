{$R-,I-,Q-,S-}
PROGRAM p1699;

TYPE
        TData           = array[0..4] of String;
        Tchoose         = array[0..199] of String;

VAR
        Data                    : TData;
        choose                  : Tchoose;
        n , Long , T , i        : Integer;
        Find                    : Boolean;

        step                    : Integer;

FUNCTION Init : Boolean;
var
        i                       : Integer;
begin
readln ( n , Long , T );
if n = 0 then exit ( false );
readln ( Data [0] );
i := 1;
for i := 1 to n - 1 do Data [i] := Data [0];
for i := 0 to T - 1  do readln ( choose [i] );
exit ( true );
end;

FUNCTION check ( v : Integer ) : Boolean;
var
        i , j , temp             : Integer;
begin
i := v mod n;
for j := 1 to length ( choose [v] ) do
        if ( choose [v] [j] <> ' ' ) then
                begin
                temp := pos ( choose [v] [j] , Data [i] );
                if ( temp = 0 ) or ( temp = length ( Data [i] ) ) then exit ( true );
                Delete ( Data [i] , 1 , temp );
                end;
exit ( false );
end;

BEGIN
//assign ( input , 'p.in' );
//reset ( input );
step := 0;

while ( Init ) do
        begin
        inc ( step );
        Find := false;
        for i := 0 to T - 1 do
                begin
                if Check ( i ) then
                        begin
                        writeln ( 'Player ', i mod n + 1 , ' won after ', i + 1,' cards.');
                        Find := true;
                        break;
                        end;
                if Find then break;
                end;
        if not Find then writeln ( 'No player won after ' , T ,' cards.');
        end;
END.