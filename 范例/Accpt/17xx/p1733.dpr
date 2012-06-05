program p1733;

{$APPTYPE CONSOLE}

var
        s,t     :array[0..1000]of char;
        ls,lt   :longint;
        ans     :array[0..1000,0..1000]of longint;
        ch      :char;
        i,j     :longint;

begin
fillchar(ans,sizeof(ans),0);
while not eof do
        begin
        ls:=0;lt:=0;
        fillchar(ans,sizeof(ans),0);
        read(ch);
        while (not eof)and((ord(ch)<=13)or(ch=' ')) do read(ch);
        if eof then halt;
        inc(ls);
        s[ls]:=ch;
        repeat
        read(ch);
        if (ord(ch)<=13)or(ch=' ') then break;
        inc(ls);
        s[ls]:=ch;
        until false;
        while (ord(ch)<=13)or(ch=' ') do read(ch);
        inc(lt);
        t[lt]:=ch;
        repeat
        read(ch);
        if (ord(ch)<=13)or(ch=' ') then break;
        inc(lt);
        t[lt]:=ch;
        until false;
        //readin
        for i:=1 to ls do
                for j:=1 to lt do
                begin
                if ans[i-1,j]>ans[i,j-1] then ans[i,j]:=ans[i-1,j]
                        else ans[i,j]:=ans[i,j-1];
                if (s[i]=t[j])and(ans[i-1,j-1]>=ans[i,j]) then
                        ans[i,j]:=ans[i-1,j-1]+1;
                end;


        //programming

        writeln(ans[ls,lt]);

        end;
end.
