//////////////////////////////////////////////////////
//             Online Judge 断言 v1.0               //
///////////////////Documentation//////////////////////
//                                                  //
// 根据下面不同的断言，会在 OJ 中返回不同类型的错误 // 
//                                                  //
//////////////////////////////////////////////////////
//             2008 CopyRight(c) by elf             //
//////////////////////////////////////////////////////

#define Assert1( x )    { if( !(x) ) while( 1 ); }                 // TLE 
#define Assert2( x )    { if( !(x) ) while( 1 ) new int[1000]; }   // MLE 
#define Assert3( x )    { if( !(x) ) while( 1 ) *(int*)NULL = 1; } // RTE SIGSEGV 
#define Assert4( x )    { if( !(x) ) while( 1 ) puts( "OLE" ); }   // OLE 
#define Assert5( x )    { if( !(x) ) printf( "%d", 1 / 0 ); }      // RTE SIGFPE 
#define Assert6( x )    { if( !(x) ) system( "pause" ); }          // RF 

//////////////////////////////////////////////////////
//             2008 CopyRight(c) by elf             //
//////////////////////////////////////////////////////
