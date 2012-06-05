PROGRAM p1090;

CONST
     pi=3.141592653;

VAR
     x1,y1,x2,y2,x3,y3  :real;
     a,b,c              :real;
     s                  :real;
     sin                :real;
     r                  :real;

BEGIN
while not eof do
      begin
      readln(x1,y1,x2,y2,x3,y3);
      a:=sqrt(sqr(x1-x2)+sqr(y1-y2));
      b:=sqrt(sqr(x1-x3)+sqr(y1-y3));
      c:=sqrt(sqr(x2-x3)+sqr(y2-y3));
      s:=(a+b+c)/2;
      sin:=sqrt(s*(s-a)*(s-b)*(s-c));
      r:=a*c*b/4/sin;
      writeln(pi*r*2:0:2);
      end;
END.
