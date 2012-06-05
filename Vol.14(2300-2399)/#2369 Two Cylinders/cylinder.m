clear
clf

x = -1.2 : .05 : 1.2;
y = -1.5 : .05 : 1.5;

[X, Y] = meshgrid( x, y );

Z = 1 - X .* X;
Z( Z < 0 ) = 0;
Z = sqrt( Z );
Z_ = 1.44 - Y .* Y;
Z_( Z_ < 0 ) = 0;
Z_ = sqrt( Z_ );

P = Z;
P_= Z_;
Z( Z > Z_) = 0;
Z_(Z_ > Z) = 0;
P_(P_ > P) = 0;
P( P > P_) = 0;

V = Z + P_;
V(P~=0) = Z_(P~=0);

figure(1)
surf( X, Y, V );
axis( [-1.2, 1.2, -1.4, 1.4, 0, 1.3] )

figure(2)
contour( X, Y, V );

