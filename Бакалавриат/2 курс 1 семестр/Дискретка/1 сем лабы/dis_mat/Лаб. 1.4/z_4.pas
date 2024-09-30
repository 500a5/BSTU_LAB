program z_4;
  uses or_arr;
  
  var a, b, c, x, u, d, e, f, g: t_arr;
      n, m, k, j, l, y, z, w, h: byte;
      
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
    z := complement (b, m, e);
    w := complement (c, k, f);
    y := intersection (a, c, n, k, d);
    h := unification (e, f, z, w, g);
    z := unification (g, d, h, y, e);
    y := complement (u, l, d);
    write ('𝛗∅ = { ');
    output (e, z);
    write ('}');
    writeln;
    write ('φ̅U  = { ');
    output (d, y);
    write ('}');
  end.