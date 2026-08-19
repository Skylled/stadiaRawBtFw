// 600df014  FUN_600df014  size=44 bytes
// --- callers ---
//   60080180 wakelock__60080180
// --- callees ---
//   6013d2a0 thunk_EXT_FUN_00007a2c
//   600cae38 timers__600cae38


undefined4 FUN_600df014(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = timers__600cae38(*(undefined4 *)(param_1 + 0x80));
  uVar2 = 0;
  if (iVar1 != 0) {
    iVar1 = thunk_EXT_FUN_00007a2c(*(undefined4 *)(param_1 + 0x80),3,0,0,10,param_2);
    if (iVar1 == 1) {
      uVar2 = 0;
    }
    else {
      uVar2 = 4;
    }
  }
  return uVar2;
}


