// 600f3ed6  FUN_600f3ed6  size=96 bytes
// --- callers ---
//   600ff482 FUN_600ff482
//   600fee40 FUN_600fee40
//   600ab9b8 FUN_600ab9b8
// --- callees ---
//   600b076c FUN_600b076c
//   600afd28 FUN_600afd28
//   600f74a8 FUN_600f74a8


undefined4 FUN_600f3ed6(undefined1 param_1,char param_2,int param_3)

{
  int iVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_600afd28(param_1);
  if (iVar1 == 0) {
    uVar3 = 0;
  }
  else {
    if (param_3 == 0) {
      if (param_2 == '\0') {
        uVar2 = 0;
      }
      else {
        uVar2 = 0xff;
      }
      *(undefined1 *)(iVar1 + 0x2e) = uVar2;
    }
    else {
      FUN_600f74a8(param_1,param_2,param_3,0);
    }
    uVar3 = FUN_600b076c();
  }
  return uVar3;
}


