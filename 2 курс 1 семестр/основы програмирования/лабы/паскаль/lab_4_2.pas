program lab_4_2;
  const n=5;
  type t_diap=1..n;
       t_a=array[t_diap] of integer;
     
  procedure read_a(var a:t_a);
    var i:byte;
    begin
     for i:=1 to n do 
     read(a[i]);
    end;
    
  procedure sort_a (var a:t_a);
     var i,x,j:integer;
     begin
      
       for i:=2 to n do begin 
         x:=a[i];
         j:=i;
         while ((j>1) and (a[j-1]>x)) do begin 
           a[j]:=a[j-1];
           j:=j-1;
         end;
         a[j]:=x;
       end;
     end;
 
  function new_mas (a:t_a; var newa:t_a): integer;
    var i,s,j,m:integer;
    begin
      m:=0;   // подсчет колличесва чисел 
      s:=1;   // длина нового массива 
      j:=1; 
      i:=1;
     while (i<n) do begin
      while (a[i]=a[j]) do begin
        j:=j+1;
        m:=m+1;
      end;
      if (m>1) then begin 
      newa[s]:=a[i];
      s:=s+1;
      end;
      i:=j;
      m:=0;      
     end;
     
     new_mas:=s-1;
    end;
    
    
  procedure write_a(newa:t_a; n:integer);
    var i:byte;
    begin
     for i:=1 to n do 
     write(newa[i], ' ');
    end;  
    
var k:integer;
    a,newa:t_a;
    
begin 
  read_a(a);
  sort_a(a);
  k:=new_mas(a,newa);
  write_a(newa,k);
  readln(k);
end.