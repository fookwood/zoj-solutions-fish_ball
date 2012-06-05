{ Solution: this is a tricky task;
  One can observe (consider Stirling's triangle) that
  
  S(n,m) == (Newton(n-1-m div 2, (m-1) div 2)) mod 2, where
  Newton denotes the binomial coefficient.

  The parity of the binomial coefficient Neawton(a,b) is easy to compute -
  it suffices to compare numbers of 2 in factorizations of a! and b!c!,
  where c=a-b. 
  
  Running time: O(log n)  
}  

var i, d : integer;
    n, m, a, b, c, a2, bc2 : longint;

begin
  readln(d); 
  for i := 1 to d do begin
    readln(n, m);
    a := n-1-m div 2; b := (m-1) div 2; c := a - b;

    a2 := 0;
    while a > 0 do
    begin
      a := a div 2; a2 := a2 + a
    end;

    bc2 := 0;
    while  b > 0 do
    begin
      b := b div 2; bc2 := bc2 + b
    end;
    
    while c > 0 do
    begin
      c := c div 2; bc2 := bc2 + c
    end;
        
    if a2 > bc2 then
      writeln(0)
    else
      writeln(1)        
  end;
end.
