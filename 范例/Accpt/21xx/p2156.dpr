program p2156;

{$APPTYPE CONSOLE}

var
        p , c1 , c5 , c10 , c25         : Longint;
        u1 , u2 , u3 , u4               : Longint;

procedure answer ( k : Longint );
begin
if k = 0 then writeln ( 'Charlie cannot buy coffee.' )
        else writeln ( 'Throw in ' , u1 , ' cents, ' , u2 , ' nickels, ' , u3 , ' dimes, and ' , u4 , ' quarters.' );
end;

function check ( Tot : Longint; var a2 , a5 : Longint ) : Boolean;
begin
if Tot < 0 then begin check := false; exit; end;

if odd ( Tot )
        then begin
        if Tot < 5 then begin check := false; exit; end;
        a2 := ( Tot - 5 ) div 2;
        end
        else a2 := Tot div 2;
        
if a2 > c10 then
        if ( a2 - c10 ) mod 5 = 0
                then a2 := c10
                else a2 := a2 - ( a2 - c10 ) div 5 * 5 - 5;
a5 := ( Tot - 2 * a2 ) div 5;
check := ( a2 >= 0 ) and ( a5 <= c25 );
end;

procedure main;
var     t       : Longint;
        FirstCan : Longint;
        i , j , k : Longint;
        l , d   : Longint;
begin
u1 := 0; u2 := 0; u3 := 0; u4 := 0;

if p <= c1 then begin u1 := p; answer ( 1 ); exit; end; // 都可以用一分的凑出

u1 := p mod 5;  // 至少需要用的一分的数目，其他的都是5的倍数
dec ( c1 , u1 ); p := p - u1;
if c1 < 0 then begin answer ( 0 ); exit; end;

p := p div 5;

t := c1 div 5;
inc ( u1 , t * 5 ); dec ( p , t ); // 其余的尽可能多的用一分的

        // 以下满足方程：u2 + 2 * u3 + 5 * u4 = p

t := c5 + c10 * 2 + c25 * 5;
if t < p then begin answer ( 0 ); exit; end;
        // 总数仍然不够

FirstCan := -1;
d := u1;
for l := 0 to 5 do
begin
if u1 - l * 5 < 0 then break;

for i := c5 downto 0 do
        if check ( p - i , j , k ) then
                begin
                if ( FirstCan = - 1 ) then FirstCan := i;

                if ( d - l * 5 + i + j + k > u1 + u2 + u3 + u4 ) then
                        begin
                        u1 := d - l * 5; u2 := i; u3 := j; u4 := k;
                        end;
                if ( FirstCan - i > 5 ) then break;
                end;
inc ( p , 1 );
end;

answer ( ord ( FirstCan <> - 1 ));
end;

begin
assign ( input , 'p.in' ); reset ( input );
assign ( output , 'p.out' ); rewrite ( output );

while true do
        begin
        readln ( p , c1 , c5 , c10 , c25 );
        if ( p = 0 ) and ( c1 = 0 ) and ( c5 = 0 ) and ( c10 = 0 ) and ( c25 = 0 ) then break;
        main;
        end;
end.
