// 600d8778  FUN_600d8778  size=72 bytes
// --- callers ---
//   600d87c0 FUN_600d87c0
//   600d87f4 FUN_600d87f4
// --- callees ---
//   600d83bc FUN_600d83bc
//   600d86ba FUN_600d86ba
//   6013cef8 thunk_EXT_FUN_0000737c
//   600d84ce FUN_600d84ce
//   600d847c FUN_600d847c


uint FUN_600d8778(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  uint uVar2;
  
  uVar2 = FUN_600d86ba();
  if ((uVar2 & 0xff) == 0) {
    bVar1 = FUN_600d84ce(param_1,0,0x13,200,param_4);
    uVar2 = (uint)bVar1;
    if (uVar2 == 0) {
      thunk_EXT_FUN_0000737c(10);
      bVar1 = FUN_600d847c(param_1,0x10);
      uVar2 = (uint)bVar1;
      if (uVar2 == 0) {
        bVar1 = FUN_600d83bc(param_1,0x61,0,200);
        uVar2 = (uint)bVar1;
        if (uVar2 == 0) {
          thunk_EXT_FUN_0000737c(5);
        }
      }
    }
  }
  return uVar2;
}


