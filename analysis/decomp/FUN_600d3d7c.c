// 600d3d7c  FUN_600d3d7c  size=30 bytes
// --- callers ---
//   6005af04 pattern_player__6005af04
// --- callees ---
//   6013d2a0 thunk_EXT_FUN_00007a2c


undefined4 FUN_600d3d7c(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = thunk_EXT_FUN_00007a2c(param_1,3,0,0,10,param_2,param_3);
  if (iVar1 == 1) {
    uVar2 = 0;
  }
  else {
    uVar2 = 4;
  }
  return uVar2;
}


