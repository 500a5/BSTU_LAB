program lab_4_1;
const n1=3;

var x,i,j,m,n,y,k:integer;
    a:array [0..n1-1] of integer;
begin
  m:=-1;
  n:=n1;
  write('x=');
  read (x);
  writeln();
  for i:=0 to n-1 do begin
    read(a[i]);
    if ((m=-1) and (a[i]=x)) then
      m:=i;
  end;
writeln(a);
  if m<>-1 then
    for i:=m+1 to n-1 do begin
      y:=a[i];
      j:=i;
      while ((j>m+1) and (a[j-1]>y)) do begin
        a[j]:=a[j-1];
        j:=j-1;
      end;
      a[j]:=y;
    end;
    writeln(m);
    writeln (a);
    for i:=0 to m-2 do begin
      for j:=0 to m-i-1 do begin 
        if a[j] < a[j+1] then begin 
          k := a[j];
          a[j] := a[j+1];
          a[j+1] := k;
        end;
      end;
    end;
     writeln();
     
  for i:=0 to n-1 do
    write (a[i],' ');
  readln(n);
end.
