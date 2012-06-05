PROGRAM p1247;

CONST
        p2=sqrt(2)/2;
        change                          :array[1..8,1..2]of Real=
        ((0,1),(p2,p2),(1,0),(p2,-p2),(0,-1),(-p2,-p2),(-1,0),(-p2,p2));

VAR
        d                               :Extended;
        make                            :Boolean;
        step                            :Integer;
        order                           :array[1..8]of String;
        x,y                             :Extended;
        s,t,num                         :String;
        n,code,j                        :Integer;


BEGIN
//assign(input,'p.in');
//reset(input);
step:=0;
order[1]:='N';
order[2]:='NE';
order[3]:='E';
order[4]:='SE';
order[5]:='S';
order[6]:='SW';
order[7]:='W';
order[8]:='NW';
while true  do
        begin
        inc(step);
        readln(s);
        if s='END' then break;
        x:=0;
        y:=0;
        while s<>'.' do
                begin
                if pos(',',s)>0 then
                        begin
                t:=copy(s,1,pos(',',s)-1);
                delete(s,1,pos(',',s));
                        end else
                        begin
                t:=copy(s,1,pos('.',s)-1);
                delete(s,1,pos('.',s)-1);
                        end;
                for j:=length(t) downto 1 do
                        begin
                        val(copy(t,1,j),n,code);
                        if code=0 then break;
                        end;
                delete(t,1,j);
                make:=false;
                for j:=1 to 8 do
                        if order[j]=t then
                                begin
                                x:=x + n * change[j,1];
                                y:=y + n * change[j,2];
                                make:=true;
                                end;
                if not make then while true do ;
                end;
        writeln('Map #',step);
        writeln('The treasure is located at (',x:0:3,',',y:0:3,').');
        d:=sqrt(sqr(x)+sqr(y));
        if (abs(d)<0.0005) then d:=abs(d);
        writeln('The distance to the treasure is ',d:0:3,'.');
        writeln;
        end;
END.