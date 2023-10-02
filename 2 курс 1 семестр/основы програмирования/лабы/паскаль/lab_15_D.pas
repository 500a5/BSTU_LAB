program lab_15_D;

type t_base = real;
     t_arr = array[1..65520 div sizeof(t_base)] of t_base;
     t_p_arr = ^t_arr;
     t_matr = array[1..65520 div sizeof(pointer)] of t_p_arr;
     pt_matr = ^t_matr;

procedure read_matr(var a: pt_matr; m,n : integer);
  var i, j : integer;
  begin
    for i:=1 to m do begin
      for j:=1 to n do
        read(a^[i]^[j]);
      writeln();
    end;
  end;

function max_s (a: pt_matr; m,n:integer):integer;
  var i,j,k:integer;
      max:real;
  begin
    k:=1;
    max:=a^[1]^[1];
    for i:=1 to m do begin
      for j:=1 to n do begin
        if a^[i]^[j]>max then begin
          max:=a^[i]^[j];
          k:=i;
        end;
      end;
    end;
    max_s:=k;
  end;

function min_s (a: pt_matr; m,n:integer):integer;
var i,j,k:integer;
      min:real;
  begin
    k:=1;
    min:=a^[1]^[1];
    for i:=1 to m do begin
      for j:=1 to n do begin
        if a^[i]^[j]<=min then begin
          min:=a^[i]^[j];
          k:=i;
        end;
      end;
    end;
    min_s:=k;
  end;

function skal (a: pt_matr; n,min,max:integer):real;
  var sum :real;
      i:integer;
  begin
    sum:=0;
    for i:=1 to n do
      sum:=sum+a^[min]^[i]*a^[max]^[i];
    skal:=sum;
  end;

var n,m,min,max,i,j:integer;
    a: pt_matr;
    pow:real;
begin
  read(m,n);
  writeln;
  GetMem(a,M*sizeof(t_p_arr));
  for i:= 1 to N do
    GetMem(a^[i], M*sizeof(t_base));

    read_matr(a,m,n);
    max:=max_s(a,m,n);
    min:=min_s(a,m,n);
    pow:=skal(a,n,min,max);
    write(pow:4:4);


  for i:=1 to N do
    FreeMem(a^[i], N*sizeof(t_base));
  FreeMem(a,m*sizeof(t_p_arr));
  readln();
end.
