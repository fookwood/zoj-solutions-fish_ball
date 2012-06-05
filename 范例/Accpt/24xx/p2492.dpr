program p2492;

{$APPTYPE CONSOLE}

uses    math;

var
        part , p , x                    : Longint;
        s                               : String;

procedure dowith ( T : String; var A , B : Longint );
var     xv                              : Boolean;
        i , j , value , value2 , code   : Longint;
begin
//writeln ( 'T = ' , T , '$' );

A := 0; B := 0; i := length ( T );
while ( i > 0 ) do
        begin
        if T [i] = 'x' then begin xv := true; dec ( i ) end else xv := false;
//        writeln ( 'i =  ' , i );
        j := i;

        if j > 0 then val ( copy ( T , j , i - j + 1 ) , value , code ); value2 := value;
        if ( code <> 0 ) or ( j <= 0 ) then begin if ( j <= 0 ) or ( T [j] = '+' ) then value2 := 1 else value2 := -1; dec ( j );end else
        while ( j > 0 ) and ( code = 0 ) do begin dec (j); value2 := value;
                if j > 0 then val ( copy ( T , j , i - j + 1 ) , value , code ) else break;
        end;

//        writeln ( 'j = ' , j , '  ' ,value2);

        if xv then inc ( A , value2 ) else inc ( B , value2 );
        i := j;
        end;
end;

function Check ( var x : Longint ) : Longint;
var     left , right                    : String;
        A , B , Ta , Tb , T             : Longint;
begin
T := 1; while ( T <= length ( s )) do if s [T] = ' ' then Delete ( s , T , 1 ) else inc ( T );

T := pos ( '=' , s );
left := copy ( s , 1 , T - 1);
right := copy ( s , T + 1 , length ( s ) - T );

dowith ( left , Ta , Tb ); A := Ta; B := Tb;
dowith ( right , Ta , Tb ); dec ( A , Ta ); dec ( B , Tb );

if A = 0 then
        if B = 0 then Check := 0
                else Check := -1
        else
        begin
        Check := 1;
        x := floor ( - B / A );
        end;
//writeln ( 'A = ' , A , ' B = ' , B );
end;

begin
readln ( part );
for p := 1 to part do
        begin
        readln ( s );
        case Check ( x ) of
                -1            : writeln ( 'IMPOSSIBLE' );
                0             : writeln ( 'IDENTITY' );
                1             : writeln ( x );
        end;
        end;
end.
