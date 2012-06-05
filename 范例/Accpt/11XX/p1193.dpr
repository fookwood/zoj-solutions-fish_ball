program p1193;

{$APPTYPE CONSOLE}
{$R+,I+,Q+,S+}

uses
  SysUtils, math;


var
        step    : Longint;
        n       : Longint;
        X , Y , R       : array[1..25] of Double;
        A , B , C , D   : Double;

procedure init;
var     i       : Longint;
begin
        for i := 1 to n do readln ( X [i] , Y [i] , R [i] );
        readln ( A , B , C , D );
end;

procedure Work;
var     Px , Py         : Double;
        Sx , Sy         : Double;
        Dx , Dy         : Double;
        MinLong         : Double;
        d2 , L          : Double;
        i , j , Num     : Longint;
        Tx , Ty         : Double;
        Ux , Uy         : Double;
begin
        Tx := 0; Ty := 0; Sx := 0; Sy := 0; Num := 0;

        Px := A; Py := B; Dx := C; Dy := D;
        for i := 1 to 11 do
                begin
                MinLong := 1e10;
                for j := 1 to n do
                        begin
                        if ( X [j] - Px ) * Dx + ( Y [j] - Py ) * Dy <= 0 then continue;
                        d2 := sqr ( Dy * X [j] - Dx * Y [j] - Px * Dy + Py * Dx )/(sqr ( Dy ) + sqr ( Dx ));
                        if d2 >= sqr ( R [j] ) then continue;
                        
                        L := sqrt ( sqr (X [j] - Px) + sqr (Y [j] - Py) - d2 ) - sqrt ( sqr ( R [j] ) - d2 );

                        if L >= MinLong then continue;

                        MinLong := L;
                        Num := j;
                        Sx := Px + L * Dx / sqrt ( sqr ( Dx ) + sqr ( Dy ));
                        Sy := Py + L * Dy / sqrt ( Sqr ( Dx ) + sqr ( Dy ));

                        Tx := Sx - X [j];
                        Ty := Sy - Y [j];
                        
                        Ux := sqr ( Tx ) - sqr ( Ty );
                        Uy := 2 * Tx * Ty;

                        Tx := - ( Ux * Dx + Uy * Dy ); // (sqr ( Dx ) + sqr ( Dy ));
                        Ty :=   ( Ux * Dy - Uy * Dx ); // (sqr ( Dx ) + sqr ( Dy ));
                        end;
                if MinLong < 1e10 then
                        begin
                        if i = 11 then
                                begin
                                writeln ( '...' );
                                exit;
                                end;
                        write ( Num , ' ' );
                        Px := Sx;
                        Py := Sy;

                        Dx := Tx;
                        Dy := Ty;
                        end else
                        begin
                        writeln ( 'inf' );
                        exit;
                        end;
                end;
end;

begin
  { TODO -oUser -cConsole Main : Insert code here }
        step := 0;
        while ( true ) do
                begin
                readln ( n ); if n = 0 then break;
                inc ( step );
                writeln ( 'Scene ' , step );
                init;
                Work;
                writeln;
                end;
end.
 