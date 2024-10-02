program lab_5;
const m=5;
type t_diap=1..m;
     t_row=array[t_diap] of integer;
     t_matr=array[t_diap] of t_row;

procedure read_matr(var a:t_matr);
  var i,j:integer;
  begin
    for i:=1 to m do 
      for j:=1 to m do 
        read(a[i,j]);
  end;
  
function one_max(a:t_matr):integer;
  var i,j,max,k:integer;
  begin 
    k:=1;
    max:=a[1,1];
    for i:=1 to m do 
      for j:=1 to m do 
       if (a[i,j]>max) then begin
         max:=a[i,j];
         k:=i;
      end;
  one_max:=k;
 end;
 
 procedure swap(var a:t_matr; k:integer);
  var i:integer;
  begin 
    for i:=1 to m do 
      if i<>k then 
        a[i,(m-1)]:=a[k,i];
      a[k,(m-1)]:=a[k,k];
    end;
    
 procedure write_matr(a:t_matr);
   var i,j:integer;
  begin
    for i:=1 to m do begin
      for j:=1 to m do 
        write(a[i][j]:4);
      writeln();
    end;
  end;
  
 var s:integer;
     a:t_matr;
 begin
  read_matr(a);
  s:=one_max(a);
  swap(a,s);
  write_matr(a);
 end.