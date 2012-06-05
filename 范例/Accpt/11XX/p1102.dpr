program p1102;

{$APPTYPE CONSOLE}

uses
  SysUtils;

const
        maxL    = 100000;

type
        longstring      = array[1..1000] of Char;

var
        n , l   : Longint;
        TotalMin: Longint;
        min     : array[1..2048 , 'A'..'Z'] of Longint;
        map     : array[1..1024] of longstring;
        Ans     : longstring;
        
procedure init;
var     i       : Longint;
        j       : Longint;
begin
        TotalMin := 0;
        for i := 1 to n do
                begin
                for j := 1 to l do read ( map [i] [j] );
                readln;
                end;
        readln;
end;

procedure load ( p : Longint );
var     i       : Longint;
        ch      : Char;    
begin
        for i := 1 to n do
                begin
                for ch := 'A' to 'Z' do
                        min [n + i - 1] [ch] := maxL;
                min [n + i - 1] [map [i] [p]] := 0;
                end;
end;

function minone ( a , b : Longint ): Longint;
begin
        if a > b then minone := b else minone := a;
end;

procedure Conculate ( p : Longint );
var     i       : Longint;
        l       : Longint;
        r       : Longint;
        ch      : Char;
        c       : Char;
        s       : Longint;
        sl      : Longint;
        sr      : Longint;
begin
        for i := n - 1 downto 1 do
                begin
                l := i shl 1 ;
                r := l + 1;

                sl := maxL; sr := maxL;
                for ch := 'A' to 'Z' do
                        begin
                        if min [l] [ch] < sl then sl := min [l] [ch];
                        if min [r] [ch] < sr then sr := min [r] [ch];
                        end;
                inc ( sl ); inc ( sr );

                for ch := 'A' to 'Z' do
                        min [i] [ch] := minone ( sl , min [l] [ch] )
                                + minone ( sr , min [r] [ch] );
                end;
        s := maxL;
        c := 'A';
        for ch := 'A' to 'Z' do
                if min [1] [ch] < s then
                        begin
                        s := min [1] [ch];
                        c := ch;
                        end;
                        
        inc ( TotalMin , s );
        Ans [p] := c;
end;



procedure main;
var     i       : Longint;
begin
        for i := 1 to l do
                begin
                Load ( i );
                Conculate ( i );
                end;
end;

procedure print;
var     i       : Longint;
begin
        for i := 1 to l do write ( Ans [i] );
        writeln ( ' ' , TotalMin );
end;

begin
  { TODO -oUser -cConsole Main : Insert code here }
        assign ( input , 'p.in' );
        reset ( input );
        assign ( output , 'p.out' );
        rewrite ( output );
         
        while true do
                begin
                readln ( n , l );
                if ( n = 0 ) then break;
                init;
                main;
                print;
                end;

end.
