
function mult1(var chek:boolean):integer;
  var n:integer;
  begin
    read(n);
    if (n=0) and (chek=true) then 
      mult1:=1
    else if (n=0) and (chek=false) then  
      mult1:=0
    else if n mod 2 <>0 then begin
      chek:=true;
      mult1:=n*mult1(chek)
    end
    else 
      mult1:=mult1(chek);
  end;
  
function mult ():integer;
  var n:boolean;
  begin
  n:=false; 
  mult:=mult1(n);
  end;
  
var n:integer;  
begin
  n:=mult();
  writeln(n);
end.