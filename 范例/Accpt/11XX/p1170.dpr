program p1170;

{$APPTYPE CONSOLE}

{%File 'p.in'}

uses
  SysUtils;

var
        p1 , p2 : String;

function gcd ( a , b : Longint ) : Longint;
begin
        if a = 0 then gcd := b
                else gcd := gcd ( b mod a , a );
end;


procedure Work;
var     i       : Longint;
        j       : Longint;
        d       : Longint;
        len     : Longint;
        max     : Longint;
        get     : Longint;
begin
        p1 := copy ( p2 , 1 , pos ( ' ' , p2 ) -1 );
        delete ( p2 , 1 , pos ( ' ' , p2 ));

        len := length ( p1 ) + length ( p2 );
        max := 0;
        for i := 1 to length ( p1 ) do
                begin
                get := 0;
                for j := 1 to length ( p2 ) do
                        if ( i + j - 1 <= length ( p1 ))
                                and ( p1 [i + j - 1] = p2 [j] ) then inc ( get );
                if get > max then max := get;
                end;
                
        for i := 1 to length ( p2 ) do
                begin
                get := 0;
                for j := 1 to length ( p1 ) do
                        if ( i + j - 1 <= length ( p2 ))
                                and ( p2 [i + j - 1] = p1 [j] ) then inc ( get );
                if get > max then max := get;
                end;

        max := max * 2;

        write ( 'appx(' , p1 , ',' , p2 , ') = ' );
        if max = 0 then writeln ( 0 )
                else if max = len then writeln ( 1 )
                        else begin
                        d := gcd ( max , len );
                        max := max div d;
                        len := len div d;
                        writeln ( max , '/' , len );
                        end;
end;

begin
  { TODO -oUser -cConsole Main : Insert code here }
        assign ( input , 'p.in' );
        reset ( input );
        assign ( output , 'p.out' );
        rewrite ( output );

        while ( true ) do
                begin
                readln ( p2 );
                if ( p2 = '-1' ) then break;
                Work;
                end;

end.
