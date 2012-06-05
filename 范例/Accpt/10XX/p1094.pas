PROGRAM P1094;

TYPE  node=record
        h,w     :longint;
                end;
      add=record
        h,w     :longint;
        flag    :boolean;
        end;

VAR
        n       :longint;
        ch      :char;
        k       :longint;
        s       :string;
        have    :array[1..26]of char;
        matrix  :array['A'..'Z']of node;
        gor     :boolean;
        sum     :longint;

FUNCTION check(str:string):add;
var     i,total :longint;
        temp    :add;
        temp2   :add;
        other   :char;
begin
if length(str)=1 then
        begin
        check.h:=matrix[str[1]].h;
        check.w:=matrix[str[1]].w;
        check.flag:=true;
        exit;
        end;
delete(str,1,1);
delete(str,length(str),1);
if str[1]='(' then
        begin
        if str[length(str)]=')' then
                begin
                i:=1;
                total:=1;
                while total<>0 do
                        begin
                        inc(i);
                        if str[i]='(' then inc(total);
                        if str[i]=')' then dec(total);
                        end;
                temp:=check(copy(str,1,i));
                temp2:=check(copy(str,i+1,length(str)-i));
                check.flag:=temp.flag and temp2.flag;
                if temp.w<>temp2.h then check.flag:=false;
                sum:=sum+temp.h*temp.w*temp2.w;
                end else
        begin
        other:=str[length(str)];
        delete(str,length(str),1);
        temp:=check(str);
        if temp.w<>matrix[other].h then
                begin
                check.flag:=false;
                exit;
                end;
        check.flag:=temp.flag;
        check.h:=temp.h;
        check.w:=matrix[other].w;
        sum:=sum+temp.w*temp.h*matrix[other].w;
        end;
        end else
        begin
        other:=str[1];
        delete(str,1,1);
        temp:=check(str);
        if matrix[other].w<>temp.h then
                begin
                check.flag:=false;
                exit;
                end;
        check.flag:=temp.flag;
        check.h:=matrix[other].h;
        check.w:=temp.w;
        sum:=sum+temp.w*temp.h*matrix[other].h;
        end;
end;

BEGIN
readln(n);
for ch:='A' to 'Z' do begin matrix[ch].h:=0;matrix[ch].w:=0;end;
for k:=1 to n do
        readln(have[k],matrix[have[k]].h,matrix[have[k]].w);
while not eof do
        begin
        readln(s);
        sum:=0;
        if not check(s).flag then writeln('error')
        else writeln(sum);
        end;
END.
