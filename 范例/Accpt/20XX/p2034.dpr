program p2034;

{$APPTYPE CONSOLE}

{%File 'p.in'}

const
        maxn    = 100;

type
        Tb      = set of 1 .. maxn;

var
        light , heavy           : Tb; // 可能集合：轻 ，重
        part , n , m            : Longint;
        state                   : Char;

procedure doit;
var     left , right            : Tb;
        l , i , t               : Longint;
begin
left := []; right := [];
read ( l );
for i := 1 to l do
        begin
        read ( t );
        left := left + [t];
        end;

for i := 1 to l do
        begin
        read ( t ); if t in left then while true do;
        right := right + [t];
        end;
readln;
readln ( state );

case state of
        '='     : begin // 相等同时排除可能
                heavy := heavy - left - right;
                light := light - left - right;
                end;
        '>'     : begin // 左边重  那么对于重集合 只能出于左边 不可能在右边 轻的类似
                heavy := heavy * left; heavy := heavy - right;
                light := light - left; light := light * right;
                end;
        '<'     : begin // 类似
                heavy := heavy - left; heavy := heavy * right;
                light := light * left; light := light - right;
                end;
end;

end;

procedure print;
var     ta , tb         : Longint;
        c1 , c2 , c     : Longint;
        i               : Longint;
begin
ta := 0; tb := 0; c1 := 0; c2 := 0; c := 0;
for i := 1 to n do
        if i in light then
                begin
                c1 := i;    // 记录下其中的一个元素 如果只有一个那么这个就是唯一的答案
                c := i;
                inc ( ta ); // 在轻集合中的元素个数
                end;

for i := 1 to n do
        if i in heavy then
                begin
                c2 := i;
                c := i;
                inc ( tb ); // 在重集合中的元素个数
                end;

if ( ta + tb = 1 ) then writeln ( c ) else // 只有一个元素
if ( ta = 1 ) and ( tb = 1 ) and ( c1 = c2 ) then writeln ( c1 ) else // 两个集合中都有一个相同的元素
        writeln ( 0 );
end;

begin
readln ( part );
while ( part > 0 ) do
        begin
        readln ( n , m );

        light := [1..n];
        heavy := [1..n]; // 置所有的元素为可能的

        while ( m > 0 ) do
                begin
                doit; // 对输入做判断
                dec ( m );
                end;

        print;   // 输出

        dec ( part );
        if part > 0 then writeln;
        end;
end.

