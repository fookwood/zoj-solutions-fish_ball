program p1159;

{$APPTYPE CONSOLE}

uses
  SysUtils;

const
        change  : array['A'..'Z'] of Longint =
        (2,2,2, 3,3,3, 4,4,4, 5,5,5, 6,6,6, 7,7,7,7, 8,8,8, 9,9,9,9);

type
        node    = record
                element : Longint;
                many    : Longint;
                next    : Longint;
                end;

var
        part , p        : Longint;
        bucket          : array[0..999] of Longint;
        Total           : Longint;
        line            : array[1..100000] of node;


procedure makenull;
begin
        Total := 0;
        fillchar ( bucket , sizeof ( bucket ) , 0 );
end;

procedure Add ( s : Longint );
var     b       : Longint;
        i       : Longint;
        f       : Longint;
        find    : Boolean;
begin
        b := s div 10000;
        s := s mod 10000;
        i := bucket [b];
        find := false;
        f := 0;
        while ( i <> 0 ) and ( line [i].element <= s ) do
                begin
                if line [i].element = s then
                        begin
                        inc ( line [i].many );
                        find := true;
                        end;
                f := i;
                i := line [i].Next;
                end;
        if not find then
                begin
                inc ( Total );
                line [Total].element := s;
                line [Total].many := 1;
                if ( f = 0 ) then
                        begin
                        line [Total].next := bucket [b];
                        bucket [b] := Total;
                        end else
                        begin
                        line [total].next := line [f].next;
                        line [f].next := Total;
                        end;
                end;
end;

procedure work;
var     s       : string;
        n       : Longint;
        i       : Longint;
        j       : Longint;
        t       : Longint;
begin
        readln ( n );
        for i := 1 to n do
                begin
                readln ( s );
                
                j := 1;
                while ( j <= length ( s )) do
                        if (( s [j] >= '0' ) and ( s [j] <= '9' )) or
                           (( s [j] >= 'A' ) and ( s [j] <= 'Z' )) then inc ( j )
                        else delete ( s , j , 1 );
                t := 0;
                
                for j := 1 to length ( s ) do
                        if ( s [j] >= '0' ) and ( s [j] <= '9' ) then
                                t := t * 10 + ord ( s [j] ) - 48
                                else t := t * 10 + change [ s[j]];
                Add ( t );
                end;
end;

procedure check;
var     i       : Longint;
        j       : Longint;
        find    : Boolean;
        s       : String;
        t       : String;
begin
        find := false;
        for i := 0 to 999 do
                begin
                str ( i + 1000 , s );
                delete ( s , 1 , 1 );
                j := bucket [i];
                while ( j <> 0 ) do
                        with line [j] do
                        begin
                        if many > 1 then
                                begin
                                str ( element + 10000 , t );
                                delete ( t , 1 , 1 );
                                writeln ( s , '-' , t , ' ' , many );
                                find := true;
                                end;
                        j := line [j].next;
                        end;
                end;
        if not find then writeln ( 'No duplicates.' );
end;


begin
  { TODO -oUser -cConsole Main : Insert code here }
        assign ( input , 'p.in' );
        reset ( input );
        assign ( output , 'p.out' );
        rewrite ( output );
        
        readln ( part );
        for p := 1 to part do
                begin
                if p > 1 then writeln;
                MakeNull;
                Work;
                check;
                end;
end.
