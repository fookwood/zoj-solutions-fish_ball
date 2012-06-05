{
ID: andyzh11
PROG: heritage
}

PROGRAM American_Heritage;

  VAR
    f:text;
    start,middle:string;
    back:array[1..26]of char;

PROCEDURE makeback(a,b:integer;s,m:string);
  var num:integer;
    ch:char;
  begin
  if a>b then exit;
  num:=pos(copy(s,1,1),m);
  back[b]:=s[1];
  makeback(a,a+num-2,copy(s,2,num-1),copy(m,1,num-1));
  makeback(a+num-1,b-1,copy(s,num+1,b-a+1-num),copy(m,num+1,b-a+1-num));
  end;

PROCEDURE readin;
var     i       :Integer;
  begin
  readln(middle);
  i:=1;
  while middle[i]<>' ' do
  inc(i);
  start:=copy(middle,1,i-1);
  delete(middle,1,i);
  back:='';
  for i:=1 to length(start) do
        back[i]:=' ';
  end;

PROCEDURE writeout;

  var i:integer;

  begin
  for I:=1 to length(start) do
    write(back[i]);
  writeln;
  end;

BEGIN
while not eof do
  begin
  readin;
  makeback(1,length(start),start,middle);
  writeout;
  end;
END.
