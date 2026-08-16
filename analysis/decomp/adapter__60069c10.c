// 60069c10  adapter__60069c10  size=60 bytes
// src: adapter.h
// --- callers ---
//   60069c58 adapter__60069c58
//   60069d50 adapter__60069d50
// --- callees ---
//   600d8a18 FUN_600d8a18
//   600d8a26 FUN_600d8a26
//   6010165c FUN_6010165c
//   600d8994 FUN_600d8994


/* src: adapter.h */

undefined4 adapter__60069c10(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar4 = param_1 + 0x110;
  iVar1 = FUN_600d8994(iVar4);
  if (iVar1 == 0) {
    if (*(char *)(param_1 + 0x11c) == '\x01') {
      iVar1 = FUN_600d8a26(iVar4);
      uVar3 = *(undefined4 *)(iVar1 + 8);
    }
    else {
      FUN_6010165c(0x28,DAT_60069c50,0xd9,DAT_60069c4c,param_4);
      uVar3 = DAT_60069c54;
    }
  }
  else {
    puVar2 = (undefined4 *)FUN_600d8a18(iVar4);
    uVar3 = *puVar2;
  }
  return uVar3;
}


