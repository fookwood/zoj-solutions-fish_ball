PROGRAM p1727;

TYPE
        Node    = record
                top , bottom , left , right
                        : Integer;
                map     : array[1..25,1..25] of Char;
        end;
        TData           = array[0..100] of Node;
        Thave           = array[1..100] of Boolean;
        Tchoose         = array[0..10,0..10] of Integer;

VAR
        n , h , w               : Integer;
        Data                    : TData;
        have                    : Thave;
        choose                  : Tchoose;
        Find                    : Boolean;

PROCEDURE Init;
var
        i , j , k               : Integer;
begin
fillchar ( Data [0] , sizeof ( Data[0] ) , 0 );
fillchar ( Choose , sizeof ( choose ), 0 );
readln ( n , h , w );
for i:= 1 to n * n do
        begin
        for j:= 1 to h do
                begin
                for k := 1 to w do
                        read ( Data [i] . map [j] [k] );
                readln;
                end;
        with Data [i] do readln ( top , left, bottom , right );
        if not eof then readln;
        end;

fillchar ( have , sizeof ( have ) , 0 );
end;

PROCEDURE Print;
var
        i , j , r , t                   : Integer;
begin
for i:= 1 to n do
        for r := 1 to h do
                begin
                for j := 1 to n do
                        for t := 1 to w do
                                write ( Data [choose [i] [j]] . map [r] [t] );
                writeln;
                end;
end;

PROCEDURE Search ( x , y :Integer );
var
        i                               : Integer;
        j :Integer;
        function push : boolean;
        begin
        //if ( x = 1 ) and ( y = 1 ) then exit ( true );
        //if ( x = 1 ) then exit ( Data [choose [x] [y - 1]] . right + Data [i] . left = 0);
        //if ( y = 1 ) then exit ( Data [choose [x - 1] [y]] . bottom + Data [i] . top = 0);
        exit ( ( Data [choose [ x - 1] [y]] . bottom + Data [i] . top = 0 )
                and ( Data [choose [x] [y - 1]] . right + Data [i] . left = 0 ) );
        end;

begin
if ( x = n + 1 ) then
        begin
        Find := true;
        print ;
        exit;
        end;

for i:= 1 to n * n do
        if not have [i] and push then
                begin
                have [i] := true;
                choose [x] [y] := i;
                if y = n then Search ( x + 1 , 1 )
                        else Search ( x , y + 1 );
                have [i] := false;
                if Find then exit;
                end;
end;

BEGIN
//assign ( input ,'p.in');
//reset ( input );

while not eof do
        begin
        Init;
        Find := false;
        Search ( 1 , 1 );
        end;
END.
