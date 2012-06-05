program p1755;

var
	took , betook		: String;
	name			: String;
	min , max		: Longint;
	a , b , c		: Longint;
        n                       : Longint;
	i			: Longint;
	t			: Longint;

begin
	while ( true ) do
		begin
		readln ( n ); if ( n = -1 ) then break;
		min := maxLongint; max := -1;
		for i := 1 to n do
			begin
			read ( a , b , c , name );
			Delete ( name , 1 , 1 );
			t := a * b * c;
			if ( t > max ) then
				begin
				max := t;
				took := name;
				end;	
			if ( t < min ) then
				begin
				min := t;
				betook := name;
				end;
			end;
		writeln ( took , ' took clay from ' , betook , '.' );
		end;
end.
