#include <stdio.h>

int      N;

main()
{
      int  total , x1 , y1 , x2 , y2 , sx , sy;
      double     Ansx , Ansy , TotalArea , T;
      for ( scanf ( "%d" , &total ); total; total -- ) {
          scanf ( "%d" , &N );
          scanf ( "%d%d" , &sx , &sy );
          x1 = sx , y1 = sy , TotalArea = 0 , Ansx = 0 , Ansy = 0;
          while ( -- N ) {
                scanf ( "%d%d" , &x2 , &y2 );
                T = x1 * y2 - x2 * y1;
                TotalArea += T;
                Ansx = Ansx + T * ( x1 + x2 ) / 3;
                Ansy = Ansy + T * ( y1 + y2 ) / 3;
                x1 = x2 , y1 = y2;
          }
          T = x1 * sy - y1 * sx;
          TotalArea += T;
          Ansx += T * ( x1 + sx ) / 3;
          Ansy += T * ( y1 + sy ) / 3;
          
          printf ( "%.2lf %.2lf\n" , (Ansx + 0.001 )/ TotalArea , ( Ansy + 0.001 ) / TotalArea );
      }
}
