program lab_8;
type Px=record
  s:integer;
  a:integer;
end;

const n=3;

type t_diap=0..n;
     t_mas = array[t_diap] of Px;
     
procedure read_mas (var a:t_mas);
  var i:integer;
  begin
    for i:=0 to n do
      read (a[i].s,a[i].a) ;      
  end;

function count (x:integer; a:t_mas):integer ;
  var m,i,j,z,k:integer ;
  begin
    m:=0;
    k := 0;
    z := 1;
    for i:=n downto 0 do begin
     for j := 1 to a[i].s-k do
      z := z * x;
     m := z*a[i].a+m;
     k := a[i].s;
    end;
    count:=m;
  end;
   
var x,p :integer;
     a:t_mas;  
begin 
  read (x);
  read_mas (a);
  p:=count (x,a);
  writeln(p);
end.