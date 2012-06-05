// 又是一道超级蘑菇题，计算电话呼叫收费计算，下面现简述题意

// 一个国家，分为 m 个 union，他们又合并成 n 个 superunion
// 有 t 个镇，分别属于某些 union
// 这个国家里面的电话号码包含 d 位数字，每个镇都有它的一套电话号码
// 但是全国没有任何一个号码是另外一个号码的前缀
// 号码包括两个部分：区号(region code)和乡镇号(town code)

// 每一个呼叫是由它的呼出地的 region 和目的地 town 来描述的
// 根据呼出地的 region，有四种类型的呼叫 
// 1. 来自 home region
// 2. 在同一个 superregion 的来自同一 home network 的 
// 3. 不在同一个 superregion 的来自不同 superregion 的本国呼叫
// 4. 来自外网(alien network) 的呼叫 

// MegaHrunexists 网络分布在几个 region 里面，对于这个网络的签署者，
// 这些 regions 都是 home region，来自本 region 的呼叫都属第一类
// 而来自网络覆盖下同一 superregions 其他 region 的则属于第二类
// 而来自网络覆盖下不同 superregions 的则属于第三类
// 来自未被网络覆盖的 region 的则属于第四类

// 对应的，跟据呼叫目的地来分，也有四种不同的呼叫类型：
// 1. local         : 呼叫目的地处于同一个 town 
// 2. regional      : 呼叫目的地处于同一个 region 
// 3. interregional : 呼叫目的地处于网络覆干下不同的 region 
// 4. long distance : 其余的情况

// 给出组合的 16 种呼叫类型的价目表，和呼叫的描述，计算呼叫的总花费
// 接听免费。(不用计算) 
 

 
 
 
 
 
 
 
 
 
 

