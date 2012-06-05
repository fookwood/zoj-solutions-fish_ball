PROGRAM p1916;

CONST
        name  : array[1..32] of string =
        ('UTC', 'GMT', 'BST', 'IST', 'WET','WEST', 'CET','CEST', 'EET','EEST',
        'MSK' , 'MSD', 'AST', 'ADT', 'NST', 'NDT', 'EST', 'EDT', 'CST', 'CDT',
        'MST' , 'MDT', 'PST', 'PDT', 'HST','AKST','AKDT','AEST','AEDT','ACST',
        'ACDT','AWST');
        change : array[1..32] of Real =
        (    0,     0,     1,      1,     0,    1,     1,     2,     2,     3,
             3,     4,    -4,     -3,  -3.5, -2.5,    -5,    -4,    -6,    -5,
            -7,    -6,    -8,     -7,   -10,   -9,    -8,    10,    11,   9.5,
          10.5,     8);

VAR
        part, p , code , h , m  : Longint;
        s , t                   : String;
        i                       : Integer;

// Make Time well
PROCEDURE Push ( var h , m :Longint ) ;
begin
if m >= 60 then
        begin
        m := m - 60;
        h := h +  1;
        end;
if m < 0 then
        begin
        m := m + 60;
        h := h -  1;
        end;
if h >= 24 then h := h - 24;
if h < 0 then h := h + 24;
end;

PROCEDURE Print ( h , m : Longint ) ;
begin
if ( h = 0 ) and ( m = 0 ) then
        begin
        writeln ( 'midnight' );
        exit;
        end;

if ( h = 12 ) and ( m = 0 ) then
        begin
        writeln ( 'noon' );
        exit;
        end;

if h >= 12 then
        begin
        if h > 12 then h := h - 12;
        write ( h,':');
        if m < 10 then write ( 0 );
        writeln ( m ,' p.m.');
        exit;
        end;

if h = 0 then h := 12;
write ( h ,':' );
if m < 10 then write ( 0 );
writeln ( m ,' a.m.');
end;

// delete the more space
PROCEDURE dowith ( var s :String );
var
        i                       : Longint;
begin
i := 2;
while ( i <= length ( s ) ) do
        if ( s[i-1] = ' ' ) and ( s[i] = ' ' ) then
                delete ( s , i , 1)
                else inc ( i );

while ( s[length(s)] = ' ' ) do
        delete ( s , length (s) , 1 );
end;

PROCEDURE Put_S_To_h_m ;
begin
if pos ('noon' , s ) > 0 then
        begin
        h := 12;
        m := 0;
        Delete ( s , 1 , pos (' ' , s ) );
        exit;
        end;

if pos ('midnight' , s ) > 0 then
        begin
        h := 0;
        m := 0;
        Delete ( s , 1 , pos (' ' , s ) );
        exit;
        end;

val ( copy ( s , 1 , pos ( ':' , s ) - 1 ) , h , code );
Delete ( s , 1 , pos ( ':' , s ) );

val ( copy ( s , 1 , pos ( ' ' , s ) - 1 ) , m , code );
Delete ( s , 1 , pos ( ' ' , s ) );

if pos ( 'p.m.' , s ) > 0 then
        begin
        if h <> 12 then inc ( h , 12 );
        end else
        if h = 12 then h := 0;

Delete ( s , 1 , pos ( ' ' , s ) );
end;

FUNCTION Find ( t : String ) : Integer;
var
        i                       : Integer;
begin
for i:= 1to 32 do if name[i] = t then exit ( i );
end;

PROCEDURE Change_Time;
begin
i := Find (copy ( s , 1 , pos ( ' ' , s ) - 1 ) );
m := round ( m - frac ( change [i] ) * 60 );
h := h - trunc ( change [i] );
push ( h , m );
Delete ( s , 1 , pos ( ' ' , s  ) );

i := Find ( s );
m := round ( m + frac ( change [i] ) * 60 );
h := h + trunc ( change [i] );
push ( h , m );
end;

BEGIN
readln ( part );
for p := 1 to part do
        begin

        readln ( s );

        dowith ( s ); // Make the input very fixful

        Put_S_To_h_m; // h = hour     m = minutes

        Change_Time;  // Do twice one change to UTC one change to the goal

        Print ( h , m );  //  Just output
        end;
END.