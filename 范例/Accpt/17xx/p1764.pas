PROGRAM p1764;

VAR
        n,i,j                           :Longint;
        s,bestname,name,t               :String;
        maxsolved,mincost               :Longint;
        p,q,code                        :Longint;
        a,b,solved,cost                 :Longint;

BEGIN
//assign(input,'p.in');
//reset(input);
while not eof do
        begin
        readln(n);
        maxsolved:=0;
        mincost:=maxlongint;
        for i:=1 to n do
                begin
                readln(s);
                s:=s+' ';
                name:=copy(s,1,pos(' ',s)-1);
                delete(s,1,pos(' ',s));
                solved:=0;cost:=0;
                for j:=1 to 4 do
                        begin
                        t:=copy(s,1,pos(' ',s)-1);
                        val(t,p,code);
                        delete(s,1,pos(' ',s));
                        t:=copy(s,1,pos(' ',s)-1);
                        val(t,q,code);
                        delete(s,1,pos(' ',s));
                        if q>0 then
                                begin
                                inc(solved);
                                inc(cost,(p-1)*20+q);
                                end;
                        end;

                if (solved=maxsolved)and(cost<mincost) then
                        begin
                        bestname:=name;
                        maxsolved:=solved;
                        mincost:=cost;
                        end;
                if (solved>maxsolved) then
                        begin
                        bestname:=name;
                        maxsolved:=solved;
                        mincost:=cost;
                        end;
                end;
        writeln(bestname,' ',maxsolved,' ',mincost);
        end;
END.