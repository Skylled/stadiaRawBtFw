// 600ecc98  FUN_600ecc98  size=60 bytes
// --- callers ---
//   600902e4 FUN_600902e4
// --- callees ---
//   600ecb94 FUN_600ecb94
//   6013d3a0 thunk_EXT_FUN_0000b572


undefined4 FUN_600ecc98(undefined4 *param_1,int *param_2,undefined4 param_3,int param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined4 *)FUN_600ecb94(param_3,param_4 + 0x10);
  if ((puVar1 == (undefined4 *)0x0) || (puVar1[2] != 0)) {
    uVar2 = 0;
  }
  else {
    if (param_2 != (int *)0x0) {
      if (puVar1[1] != 0) {
        thunk_EXT_FUN_0000b572(*param_2,*puVar1);
      }
      *param_2 = *param_2 + puVar1[1];
    }
    if (param_1 != (undefined4 *)0x0) {
      *param_1 = puVar1[1];
    }
    uVar2 = 1;
  }
  return uVar2;
}


