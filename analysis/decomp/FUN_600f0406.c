// 600f0406  FUN_600f0406  size=88 bytes
// --- callers ---
//   600b89b8 FUN_600b89b8
//   60099dd0 FUN_60099dd0
// --- callees ---
//   600b3a80 FUN_600b3a80
//   60098ec8 FUN_60098ec8


undefined4 FUN_600f0406(undefined4 param_1,undefined2 param_2)

{
  undefined2 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  puVar1 = (undefined2 *)FUN_60098ec8(param_1,1);
  if (puVar1 == (undefined2 *)0x0) {
    uVar3 = 7;
  }
  else {
    puVar1[0x86] = param_2;
    if (*(char *)((int)puVar1 + 0x129) == '\0') {
      iVar2 = FUN_600b3a80(0,*puVar1,param_2);
      if (iVar2 == 0) {
        uVar3 = 3;
      }
      else {
        uVar3 = 1;
      }
    }
    else {
      uVar3 = 0;
    }
  }
  return uVar3;
}


