program p1945;

{$APPTYPE CONSOLE}

var
        f                       :Text;
        code                    :Integer;
        part,per,j,w            :Longint;
        s,t                     :String;
        p,u,i,cheng             :Extended;

begin
//assign(f,'p.in');
//reset(f);
readln(part);
for per:=1 to part do
        begin
        readln(S);
        p:=-1;u:=-1;i:=-1;
        j:=pos('P=',s);
        if j>0 then
                begin
                w:=j;
                while (s[w]<>'W') do inc(w);
                t:=copy(s,j+2,w-j-2);
                cheng:=1;
                case t[length(t)] of
                'm'             :cheng:=0.001;
                'k'             :cheng:=1000;
                'M'             :cheng:=1000000;
                else            t:=t+' ';
                end;
                delete(t,length(t),1);
                val(t,p,code);
                p:=p*cheng;
                end;

        j:=pos('I=',s);
        if j>0 then
                begin
                w:=j;
                while (s[w]<>'A') do inc(w);
                t:=copy(s,j+2,w-j-2);
                 cheng:=1;
                case t[length(t)] of
                'm'             :cheng:=0.001;
                'k'             :cheng:=1000;
                'M'             :cheng:=1000000;
                else            t:=t+' ';
                end;
                delete(t,length(t),1);
                val(t,i,code);
                i:=i*cheng;
                end;
        j:=pos('U=',s);
        if j>0 then
                begin
                w:=j;
                while (s[w]<>'V') do inc(w);
                t:=copy(s,j+2,w-j-2);
                 cheng:=1;
                case t[length(t)] of
                'm'             :cheng:=0.001;
                'k'             :cheng:=1000;
                'M'             :cheng:=1000000;
                else            t:=t+' ';
                end;
                delete(t,length(t),1);
                val(t,u,code);
                u:=u*cheng;
                end;

        writeln('Problem #',per);
        if p<0 then
                writeln('P=',u*i:0:2,'W')
                else
        if i<0 then
                begin
                if abs(u)<0.000000001 then
                writeln('I=',0.0:0:2,'A') else 
                writeln('I=',p/u:0:2,'A')
                end
                else
                begin
                if abs(i)<0.000000001 then
                writeln('U=',0.0:0:2,'V') else 
                writeln('U=',p/i:0:2,'V');
                end;
        writeln;
        end;
end.
