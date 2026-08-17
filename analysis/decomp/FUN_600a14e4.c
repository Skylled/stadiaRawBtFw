// 600a14e4  FUN_600a14e4  size=118 bytes
// --- callers ---
//   600fd162 FUN_600fd162
// --- callees ---
//   600b3240 FUN_600b3240
//   600a1d3c FUN_600a1d3c
//   600a1900 FUN_600a1900
//   600b30ac FUN_600b30ac
//   600b4b8c FUN_600b4b8c


undefined4 FUN_600a14e4(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_9;
  
  local_9 = 2;
  iVar1 = FUN_600b3240(2,0,&local_9,1);
  if (iVar1 == 0) {
    uVar2 = 3;
  }
  else {
    iVar1 = FUN_600a1d3c(1,0x12,0x800);
    if (iVar1 == 0) {
      iVar1 = FUN_600a1900(2,0x12,0x800);
      if (iVar1 == 0) {
        iVar1 = FUN_600b30ac(0,DAT_600a155c);
        if (iVar1 == 0) {
          uVar2 = 3;
        }
        else {
          iVar1 = FUN_600b4b8c();
          if (iVar1 == 0) {
            uVar2 = 3;
          }
          else {
            uVar2 = 0;
          }
        }
      }
      else {
        uVar2 = 3;
      }
    }
    else {
      uVar2 = 3;
    }
  }
  return uVar2;
}


