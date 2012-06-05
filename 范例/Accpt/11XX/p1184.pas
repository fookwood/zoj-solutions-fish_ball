PROGRAM p1184;

VAR
        find                            :Boolean;
        ch                              :Char;
        sure,sure2,temp                 :Set of Char;
        s,t1,t2                         :String;
        n,i,j,k                         :Integer;

BEGIN
readln(n);
for I:=1 to n do
        begin
        sure:=['A','B','C','D','E','F','G','H','I','J','K','L'];
        sure2:=sure;
        for j:=1 to 3 do
                begin
                readln(s);
                t1:=copy(s,1,pos(' ',s)-1);
                delete(s,1,pos(' ',s));
                t2:=copy(s,1,pos(' ',s)-1);
                delete(s,1,pos(' ',s));
                if pos('even',s)>0 then
                        begin
                        for k:=1 to length(t1) do
                                        begin
                                        sure:=sure-[t1[k]];
                                        sure2:=sure2-[t1[k]];
                                        end;
                        for k:=1 to length(t2) do
                                begin
                                sure:=sure - [t2[k]];
                                sure2:=sure2 - [t2[k]];
                                end;
                        end else
                if pos('up',s)>0 then
                        begin
                        temp:=[];
                        for k:=1 to length(t2) do
                                temp:=temp + [t2[k]];
                        sure:=sure * temp;

                        temp:=[];
                        for k:=1 to length(t1) do
                                temp:=temp + [t1[k]];
                        sure2:=sure2 * temp;

                        for k:=1 to length(t1) do
                                sure:=sure - [t1[k]];

                        for k:=1 to length(t2) do
                                sure2:=sure2-[t2[k]];
                        end else
                        begin
                        temp:=[];
                        for k:=1 to length(t1) do temp:=temp + [t1[k]];
                        sure:=sure * temp;

                        temp:=[];
                        for k:=1 to length(t2) do temp:=temp + [t2[k]];
                        sure2:=sure2 * temp;

                        for k:=1 to length(t1) do
                                sure2:=sure2 - [t1[k]];
                        for k:=1 to length(t2) do
                                sure:=sure - [t2[k]];
                        end;
                end;

        find:=false;
        for ch:='A' to 'L' do
                if ch in sure2 then
                        begin
                        write(ch);
                        find:=true;
                        end;
        if find then writeln(' is the counterfeit coin and it is heavy.') else
                begin
                for ch:='A' to 'L' do
                        if ch in sure then
                                write(ch);
                writeln(' is the counterfeit coin and it is light.');
                end;
        end;
END.