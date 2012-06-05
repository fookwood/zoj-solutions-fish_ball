PROGRAM p2021;

CONST
        maxn    =  200;
        A_      =    1;
        S_      =    2;
        M_      =    3;
        D_      =    4;

TYPE
        TNode   = record
                struct           : Byte;
                        // 0 : number 1 : add 2 : sub 3 : mul 4 : div
                name            : String;
                father , leftchild , rightchild
                                : Longint;
                end;

        TTree   = array [1..maxn ] of TNode;

VAR
        part , p , T            : Longint;
        Tree                    : TTree;
        s                       : String;
        fu                      : Set of Char;

PROCEDURE Partive ( s : String ; N : Integer ) ;
var
        i , have , l , r , max , j
                                : Longint;
        fu2                     : Set of Char;

begin
while ( true ) do
        begin
        if length ( s ) = 1 then
                with Tree [N] do
                        begin
                        leftchild  := 0;
                        rightchild := 0;
                        struct     := 0;
                        name       := s;
                        exit;
                        end;

        have := 0;

        max := 0;
        for j := length ( s ) downto 1 do
                begin
                if s [j] = ')' then inc ( have );
                if s [j] = '(' then dec ( have );
                if ( have = 0 ) then
                     begin
                     if ( s [j] = '+' ) or ( s [j] = '-' ) then
                                begin
                                max := 2;
                                i := j;
                                break;
                                end;

                     if ( s [j] = '*' ) or ( s [j] = '/' ) then
                                if 1 > max then
                                        begin
                                        max := 1;
                                        i := j;
                                        end;
                     end;
                end;

        case max of
        0       : begin
                delete ( s ,            1 , 1 );
                delete ( s , length ( s ) , 1 );
                continue;
                end;
        1       : fu := ['*' , '/'];
        2       : fu := ['+' , '-'];
        end;


        have := 0;
//        for i := length ( s ) downto 1 do
                begin
                if s [i] = '(' then inc ( have );
                if s [i] = ')' then dec ( have );

                if ( have = 0 ) and ( s[i] in fu ) then
                        begin
                        with Tree [N] do
                                begin
                                case s [i] of
                                        '+'     : struct := A_;
                                        '-'     : struct := S_;
                                        '*'     : struct := M_;
                                        '/'     : struct := D_;
                                end;

                                leftchild  := T + 1 ;
                                rightchild := T + 2 ;
                                end;

                        Tree [T + 1] . father := N;
                        Tree [T + 2] . father := N;
                        l := T + 1;
                        r := T + 2;
                        inc ( T , 2 );


                        Partive ( copy ( s , 1 , i - 1 ) , l );
                        Partive ( copy ( s , i + 1 , length ( s ) - i ) , r );

                        case s [i] of
                        '+'     : begin
                                Tree [N] . name := Tree [l] . name + '+' + Tree [r] . name;
                                end;
                        '-'     : begin
                                if ( Tree [r] . struct = A_ ) or ( Tree [r] . struct = S_ ) then
                                        Tree [N] . name := Tree [l] . name + '-(' + Tree [r] . name + ')'
                                                else
                                        Tree [N] . name := Tree [l] . name + '-' + Tree [r] . name ;
                                end;
                        '*'     : begin
                                if ( Tree [l] . struct = A_ ) or ( Tree [l] . struct = S_ ) then
                                        Tree [N] . name := '(' + Tree [l] . name + ')*'
                                                else
                                        Tree [N] . name := Tree [l] . name + '*';

                                if ( Tree [r] . struct = A_ ) or ( Tree [r] . struct = S_ ) then
                                        Tree [N] . name := Tree [N] . name + '(' + Tree [r] . name + ')'
                                                else
                                        Tree [N] . name := Tree [N] . name + Tree [r] . name;
                                end;
                        '/'     : begin
                                if ( Tree [l] . struct = A_ ) or ( Tree [l] . struct = S_ ) then
                                        Tree [N] . name := '(' + Tree [l] . name + ')/'
                                                else
                                        Tree [N] . name := Tree [l] . name + '/';

                                if ( Tree [r] . struct <> 0 ) then
                                        Tree [N] . name := Tree [N] . name + '(' + Tree [r] . name + ')'
                                                else
                                        Tree [N] . name := Tree [N] . name + Tree [r] . name;
                                end;


                        end;

                        exit;
                        end;
                end;

        end;
end;

BEGIN
readln ( part );
for p := 1 to part do
        begin
        T := 1;
        readln ( s );
        Partive ( s , 1 );
        writeln ( Tree [1] . name );
        end;
END.