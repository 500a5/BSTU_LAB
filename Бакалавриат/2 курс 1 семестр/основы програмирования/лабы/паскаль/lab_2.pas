program lab_2;
var x,y,r:real;
begin 
  read (x,y);
  read (r);
  if (sqr(x)+sqr(y) <= sqr(r)) and (abs(x)>=abs(y)) then 
    writeln ('точка принадлежит')
  else 
    writeln ('точка не принадлежит');
end.  