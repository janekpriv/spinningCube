syms A;
syms B;
syms C;

syms i;
syms j;
syms k;

J = [i;j;k];

Rx = [1, 0,     0;
      0, cos(A), -sin(A);
      0, sin(A), cos(A)];

Ry = [cos(B), 0, sin(B);
      0,      1, 0     ;
      -sin(B),0, cos(B)];

Rz = [cos(C), -sin(C), 0;
      sin(C), cos(C),  0;
      0,      0,       1];

R = Rx*Ry*Rz

Ra = R*J