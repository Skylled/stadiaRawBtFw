// 600cc9e4  FUN_600cc9e4  size=72 bytes
// --- callers ---
//   6010201a FUN_6010201a
// --- callees ---
//   60101fd2 FUN_60101fd2
//   6013d3a0 thunk_EXT_FUN_0000b572


void FUN_600cc9e4(int param_1,int param_2)

{
  int iVar1;
  undefined1 auStack_78 [4];
  undefined1 auStack_74 [100];
  undefined1 auStack_10 [8];
  
  param_2 = param_2 - param_1;
  thunk_EXT_FUN_0000b572(auStack_74,DAT_600cca2c,0x69);
  iVar1 = -(param_2 + 0x77U & 0xfffffff8);
  thunk_EXT_FUN_0000b572(auStack_78 + iVar1,auStack_74,0x68);
  thunk_EXT_FUN_0000b572(auStack_10 + iVar1,param_1,param_2);
  auStack_10[param_2 + iVar1] = 0;
                    /* WARNING: Subroutine does not return */
  FUN_60101fd2(auStack_78 + iVar1);
}


