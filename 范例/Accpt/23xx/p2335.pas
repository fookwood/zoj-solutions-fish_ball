PROGRAM p2335;

CONST
        infinity=1e10;
        small=1e-9;

TYPE
        Circle=record
                x,y,r                           :Extended;
        end;

VAR
        f                                               :Text;
        ans,temp                                :Extended;
        part,p,i                                :Integer;
        data                                    :array[1..3]of Circle;

FUNCTION Find(down,up:Extended;var r,a,b,t:Extended):Extended;
var
        mid,temp                                :Extended;
        com1,com2                               :Extended;
begin
if abs(down-up)<small then
        begin
        find:=up;
        exit;
        end;
mid:=(up+down)/2;
temp:=(down+mid)/2;

com1:=sqrt(sqr(a)+sqr(r)-2*cos(mid)*a*r)+sqrt(sqr(b)+sqr(r)-2*cos(t-mid)*b*r);
com2:=sqrt(sqr(a)+sqr(r)-2*cos(temp)*a*r)+sqrt(sqr(b)+sqr(r)-2*cos(t-temp)*b*r);

if com2<com1 then Find:=Find(down,mid,r,a,b,t)
        else Find:=Find(temp,up,r,a,b,t);

end;

FUNCTION Maxget(mid,left,right:Circle):Extended;
var
        a,b,c                                   :Extended;
        jiao,x,sure                             :Extended;
begin
a:=sqrt(sqr(mid.x-left.x)+sqr(mid.y-left.y));
b:=sqrt(sqr(mid.x-right.x)+sqr(mid.y-right.y));
c:=sqrt(sqr(left.x-right.x)+sqr(left.y-right.y));
x:=(sqr(a)+sqr(b)-sqr(c))/a/b/2;
{if x<0 then
        begin
        Maxget:=c-left.r-right.r;
        exit;
        end;}
jiao:=ArcTan(sqrt(1-sqr(x))/x);
if jiao<small then jiao:=jiao+pi;
sure:=Find(0,jiao,mid.r,a,b,jiao);
Maxget:=sqrt(sqr(a)+sqr(mid.r)-2*cos(sure)*a*mid.r)+sqrt(sqr(b)+sqr(mid.r)-2*cos(jiao-sure)*b*mid.r)-left.r-right.r;
end;


BEGIN
//assign(input,'p.in');
//reset(input);
readln(part);
for p:=1 to part do
        begin
        for i:=1 to 3 do with data[i] do read(data[i].x,data[i].y,data[i].r);
        readln;
        ans:=infinity;
        temp:=Maxget(data[1],data[2],data[3]);
        if temp<ans then ans:=temp;
        temp:=Maxget(data[2],data[1],data[3]);
        if temp<ans then ans:=temp;
        temp:=Maxget(data[3],data[1],data[2]);
        if temp<ans then ans:=temp;
        ans:=ans+2*pi*(data[1].r+data[2].r+data[3].r);
        writeln(ans:0:3);
        end;
END.