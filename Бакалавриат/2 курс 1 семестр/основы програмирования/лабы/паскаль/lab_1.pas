program lab_1;
var x,y,z,sk,t,ny,nz,a,b:real;
begin 
  write('' :60);
  read (x,y,z);
  sk:=2*Pi*x/7;
  t:=sin(sk)/Cos(sk);
  a:=(t-1)*1.2;
  ny:=y*t*t+5.8;
  nz:=x-2.3;
  nz:=nz/Abs(nz)*Exp((Ln(Abs(nz)))/5);
  nz:=z-nz;
  b:=ny/nz;
  Writeln('a=':60,a:0:4);
  writeln( 'b=':60, b:0:4);
end.