PROGRAM p1766;

CONST
        maxn    = 5000;


TYPE
        TNode   = record
                next    : array['a' .. 'z' ] of Integer;
                w       : Integer;
                end;

        TTree   = array[1..maxn ] of TNode;
        Tans    = array[1..maxn ] of String;


VAR
        T                       : Integer;
        Tree                    : TTree;
        Find , total            : Integer;
        ans                     : Tans;
        S                       : String;
        ch                      : Char;

PROCEDURE Add ( s : String ) ;
var
        p , i                   : Integer;
begin
p := 1;
for i := 1 to length ( s ) do
        begin
        if Tree [p] . next [s [i]] = 0 then
                begin
                Inc ( T );
                Tree [p] . next [s [i]] := T;
                fillchar ( Tree [T] , sizeof ( Tree [T] ) , 0);
                end;
        p := Tree [p] . next [s [i]];
        end;
inc ( Tree [p] . w );
if ( Tree [p] . w = Find ) then
        begin
        inc ( Total );
        ans [Total] := s;
        end;
if ( Tree [p] . w > Find ) then
        begin
        Find  := Tree [p] . w;
        Total := 1;
        ans [Total] := s;
        end;
end;

PROCEDURE Sort;
var
        i , j                   : Integer;
        temp                    : String;
begin
for i := 1 to Total do
        for j := i+ 1 to Total do
                if ans [i] > ans [j] then
                        begin
                        temp := ans [i];
                        ans [i] := ans [j];
                        ans [j] := temp;
                        end;

writeln (Find ,' occurrences' );
for i := 1 to Total do
        writeln ( ans [i] );
end;

BEGIN
T := 1;
fillchar ( Tree [1] , sizeof ( Tree [1] ) , 0 );
Find := -1;

s := '';
repeat
        if eof then break;
        read ( ch );
        ch := lowercase ( ch );
        if ( ch >= 'a' ) and ( ch <= 'z' ) then
                s := s + ch
                else
                begin
                if s <> '' then Add ( s );
                s := '';
                end;
until false;
Sort;
END.