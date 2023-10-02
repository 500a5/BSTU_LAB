program z_8;
  uses or_arr;
  
  var a, b, c, x, d, e, f, g: t_arr;
      n, m, k, j, y, z, w, h: byte;
      
  begin
    writeln ('Введите количество элементов множества A');
    read (n);
    writeln ('Введите элементы множества А');
    input (a, n);
    writeln ('Введите количество элементов множества B');
    read (m);
    writeln ('Введите элементы множества B');
    input (b, m);
    writeln ('Введите количество элементов множества C');
    read (k);
    writeln ('Введите элементы множества C');
    input (c, k);
    j := difference(b, c, m, k, x);
    y := intersection(a, x, n, j, d);
    j := complement(d, y, x);
    y := difference(c, b, k, m, d);
    z := complement(d, y, e);
    y := intersection (x, e, j, z, d);
    j := complement(d, y, x);

    y := difference(b, c, m, k, d);
    h := complement(d, y, g);
    y := complement(a, n, d);
    z := unification(d, g, y, h, e);
    y := complement(e, z, d);
    w := difference(c, b, k, m, f);
    z := unification(d, f, y, w, e);
    
    if equality(x, e, j, z) then
      writeln('Решение верно')
    else
      writeln('Решение не верно');
  end.