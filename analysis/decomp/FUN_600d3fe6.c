// 600d3fe6  FUN_600d3fe6  size=38 bytes
// --- callers ---
//   60065074 FUN_60065074
//   6005b740 FUN_6005b740
//   60075ee0 FUN_60075ee0
//   60075fac FUN_60075fac
//   600638d4 FUN_600638d4
//   60074cc8 FUN_60074cc8
// --- callees ---
//   6013d310 thunk_EXT_FUN_0000b52a


int * FUN_600d3fe6(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (*param_1 != 0) {
    iVar1 = param_1[9];
    for (puVar2 = (undefined4 *)param_1[5]; puVar2 < (undefined4 *)(iVar1 + 4); puVar2 = puVar2 + 1)
    {
      thunk_EXT_FUN_0000b52a(*puVar2);
    }
    thunk_EXT_FUN_0000b52a(*param_1);
  }
  return param_1;
}


