// 600d0fb6  FUN_600d0fb6  size=168 bytes
// --- callers ---
//   600555d4 FUN_600555d4
//   600554a4 FUN_600554a4
// --- callees ---
//   600d0ede FUN_600d0ede


undefined4 FUN_600d0fb6(int param_1,undefined4 *param_2)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  undefined4 local_1c;
  undefined4 local_18;
  char local_14;
  
  if ((param_2 == (undefined4 *)0x0) || (param_1 == 0)) {
    uVar2 = 3;
  }
  else {
    if (*(int *)(param_1 + 8) != 0) {
      bVar1 = *(byte *)(param_2 + 2);
      if (bVar1 == 0x10) {
        *(undefined1 *)(param_1 + 0xcf) = 1;
        FUN_600d0ede(param_1,0xe,0);
        *(undefined1 *)(param_1 + 0xcc) = 0;
        *(undefined1 *)(param_1 + 0xce) = 2;
        iVar3 = param_1;
        do {
          *(undefined1 *)(iVar3 + 0x14) = 0;
          *(undefined4 *)(iVar3 + 0xc) = 0;
          *(undefined4 *)(iVar3 + 0x10) = 0;
          iVar3 = iVar3 + 0xc;
        } while (param_1 + 0xc0 != iVar3);
        (**(code **)(param_1 + 8))(param_1,1,0);
        *(undefined1 *)(param_1 + 0xcf) = 0;
        return 0;
      }
      uVar4 = bVar1 & 0xf;
      if (uVar4 < 8) {
        uVar4 = uVar4 << 1 | (uint)(bVar1 >> 7);
        iVar3 = uVar4 * 0xc + param_1;
        if (*(int *)(iVar3 + 0xc) != 0) {
          local_1c = *param_2;
          local_18 = param_2[1];
          local_14 = *(char *)((int)param_2 + 9);
          if (local_14 == '\0') {
            *(undefined1 *)(iVar3 + 0x14) = 0;
          }
          else {
            *(undefined1 *)(param_1 + 0x14) = 0;
            *(undefined1 *)(param_1 + 0x20) = 0;
          }
          iVar3 = uVar4 * 0xc + param_1;
          uVar2 = (**(code **)(iVar3 + 0xc))(param_1,&local_1c,*(undefined4 *)(iVar3 + 0x10));
          return uVar2;
        }
      }
    }
    uVar2 = 1;
  }
  return uVar2;
}


