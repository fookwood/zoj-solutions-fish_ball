// Accept 
// Time 2005/06/08
program p1072;

{$APPTYPE CONSOLE}

const
        Mmax    = 255;
        base_p  = 16;

type
        Tmemory = array[0..Mmax ] of Byte;

var
        A , B , p       : Integer;
        finish          : Boolean;
        memory          : Tmemory;

function hex ( c : Char ) : Integer;
begin
if ( c >= 'A' ) and ( c <= 'F' ) then Hex := ord ( c ) - ord ( 'A' ) + 10 else
if ( c >= '0' ) and ( c <= '9' ) then Hex := ord ( c ) - ord ( '0' ) else
Hex := -1;
end;

function init : Boolean;
var
        i               : Integer;
        ch              : Char;
begin
i := 0;
while ( i <= Mmax ) do
        begin
        read ( ch );
        while hex ( ch ) = -1 do read ( ch );
        memory [i] := hex ( ch );

        if ( memory [0] = 8 ) then
                begin
                init := false;;
                exit;
                end;
                
        inc ( i );
        end;
init := true;
end;

procedure main;
var
        t                       : Integer;
begin
p := 0;
A := 0;
B := 0;
finish := false;
while not finish do
        case memory [p] of
        0               : begin
                        t := memory [p + 1] * base_p + memory [p + 2];
                        p := p + 3;
                        A := memory [t];
                        end;
        1               : begin
                        t := memory [p + 1] * base_p + memory [p + 2];
                        p := p + 3;
                        memory [t] := A;                 
                        end;
        2               : begin
                        t := A;
                        A := B;
                        B := t;
                        p := p + 1;
                        end;
        3               : begin
                        t := A + B;
                        A := t mod base_p;
                        B := t div base_p;
                        p := p + 1;
                        end;
        4               : begin
                        A := ( A + 1 ) mod base_p;
                        p := p + 1;
                        end;
        5               : begin
                        A := ( A - 1 + base_p ) mod base_p;
                        p := p + 1;
                        end;
        6               : begin
                        t := memory [p + 1] * base_p + memory [p + 2];
                        if ( A = 0 ) then
                                p := t
                                        else
                                p := p + 3;
                        end;
        7               : begin
                        t := memory [p + 1] * base_p + memory [p + 2];
                        p := t;
                        end;
        8               : finish := true;
        end;
end;

function HexStr ( s : Integer ) : Char;
begin
if s < 10 then HexStr := chr ( s + 48 )
        else HexStr := chr ( s + ord ( 'A' ) - 10 );
end;

procedure print;
var
        i                       : Integer;
begin
for i := 0 to Mmax do
        begin
//        if i mod 64 = 0 then writeln;
        write ( HexStr ( memory [i] ) );
        end;
writeln;
end;

begin
assign ( input ,'p.in' );
reset ( input );
assign ( output , 'p.out' );
rewrite ( output );

while init do
        begin
        main;
        print;
        while not eof and eoln do readln;
        end;
end.
