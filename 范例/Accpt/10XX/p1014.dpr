program p1014;

{$APPTYPE CONSOLE}

const
        stop = '*';
        // priority :
        K_ = 1;    // parentheses       '()'
        P_ = 2;    // power             '^'
        M_ = 3;    // multiplition      '*'
        A_ = 4;    // addition          '+'


type
        Tnum    =       array[1..100]of Longint;
        Tpart   =       array[1..100]of String;

var
        s , name                : String;
        n , ni , total , t , j  : Longint;
        num                     : Tnum;
        part                    : Tpart;

// the function used for return the lowest priority
FUNCTION Ret_First ( s : String ) : Longint;
var
        i , have , t            : Longint;
begin
t := 0;
have := 0;
for i:= 1 to length ( s ) do
        begin
        if s [i] = '(' then inc ( have );
        if s [i] = ')' then dec ( have );
        if ( have > 0 ) and ( t < 1 ) then t := K_; //  parentheses is the lowest priority
        if ( have = 0 ) and ( s [i] = '^' ) and ( t < P_ ) then t := P_;   // power is the lowest priority
        if ( have = 0 ) and ( s [i] = '*' ) and ( t < M_ ) then t := M_;   // multiplition is the lowest priority
        if ( have = 0 ) and ( s [i] = '+' ) and ( t < A_ ) then t := A_;   // addition is the lowest priority
        end;
Ret_First := t;
end;

// this procedure part s to total parts as the priority First
// First the defined upper place
PROCEDURE Part_It ( s : String ; First : Longint ) ;
var
        i , have , last         : Longint;
        add                     : Boolean;
begin
total := 0;

case First of
        0       : begin    // only a varity
                inc ( total );
                part [ total ] := s;
                exit;
                end;
        K_      : begin    // the parentheses we part like ( 1 ( 2 ( 3 ( 4 ... ))))
                i := 1;
                while ( s [i] = '(' ) and ( s [ length ( s ) - i + 1 ] = ')' ) and ( i <= length ( s ) div 2 ) do
                        begin
                        inc ( total );
                        part [total] := copy ( s , i + 1 , length ( s ) - 2 * i );
                        inc ( i );
                        end;
                exit;
                end;       // add a operator to the end for keep the last varity
        P_      : s := s + '^';
        M_      : s := s + '*';
        A_      : s := s + '+';
end; { case }

have := 0;
last := 1;
for i := 1 to length ( s ) do
        begin
        add := false;
        if ( s[i] = '(' ) then inc ( have );
        if ( s[i] = ')' ) then dec ( have );
        if ( have = 0 ) then
                case s [i] of
                '*'     : add := First = M_;
                '^'     : add := First = P_;
                '+'     : add := First = A_;
                end;
        if add then
                begin
                inc ( total );
                part [total] := copy ( s , last , i - last );
                last := i + 1;     
                end;
        end;
end;

// use this function recursively to find the answer
FUNCTION Deal_ ( s : String ; w : Longint) : String ;
var
        First                   : Longint;
begin
if w > n then
        begin
        Deal_ := s;
        exit;
        end;

First := Ret_First ( s );  // return the priority like we defined
Part_It ( s , First );  // part s to total parts

if num [w] > total then Deal_ := part [ total ] else // I don't know why that the problem seemed not metion for this but if no the answer is wrong
Deal_ := Deal_ ( part [ num [w] ] , w + 1 ); // give the answer recursively
end;


begin
readln ( s );
while ( true ) do
        begin
        name := copy ( s , 1 , pos ( ':=' , s ) - 1 ) ;   // keep the name 
        writeln ( 'Expression ' , name , ':' );
        delete ( s , 1 , length ( name ) + 2 );

        readln ( t );
        for ni := 1 to t do
                begin
                n := 0;
                while not eoln do
                        begin
                        inc ( n );
                        read ( num [n] );
                        end;
                for j := n downto 1 do write ( 'op(' , num[j] , ',' );
                write ( name );
                for j := 1 to n do write ( ')' );
                write ( '=' );
                writeln ( Deal_ ( s , 1 ) ) ;
                readln;
                end;

        readln ( s );
        if ( s = stop ) then break else writeln;
        end;
end.
