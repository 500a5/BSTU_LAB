program lab_3;
var n,k,z: integer;
begin 
  k:=0;
  read(n);
  z:=n;
  if z=0 then 
    writeln(n)
  else begin
    while (n mod 10 = 0) do begin 
      n:= n div 10;
      k:=k+1;
    end;
    writeln(n,'*10^', k);
  end;
  read(n);
end.
    