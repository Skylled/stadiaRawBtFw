// 600c63e0  FUN_600c63e0  size=228 bytes
// --- callers ---
// --- callees ---
//   60094d24 FUN_60094d24
//   600f7bd8 FUN_600f7bd8
//   600d9250 FUN_600d9250
//   600d9230 FUN_600d9230
//   6006ddd8 FUN_6006ddd8
//   600aa648 FUN_600aa648


void FUN_600c63e0(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined2 *local_c;
  
  local_c = *(undefined2 **)(param_1 + 0x14);
  if (*(int *)(param_1 + 0x10) != 0) {
    if (*(char *)(param_1 + 8) == '\x02') {
      iVar2 = *(int *)(param_1 + 0x10) + 1;
      FUN_600f7bd8(iVar2,1,param_3,iVar2,param_2);
    }
    *(undefined1 *)(*(int *)(param_1 + 0x10) + 8) = 0;
    *(undefined1 *)(param_1 + 0x1a) = 0;
    if (*(char *)(param_1 + 0x1d) != '\0') {
      if (*(int *)(*(int *)(param_1 + 0x10) + 0xc) != 0) {
        while (*(int *)(*(int *)(param_1 + 0x10) + 0x14) != 0) {
          uVar1 = FUN_600d9250(*(int *)(param_1 + 0x10) + 0x14);
          FUN_6006ddd8(uVar1,DAT_600c64c4,0x3d7);
        }
        *(undefined4 *)(*(int *)(param_1 + 0x10) + 0xc) = 0;
      }
      FUN_600d9230(*(int *)(param_1 + 0x10) + 1);
    }
    FUN_600aa648(*(int *)(param_1 + 0x10) + 0x28);
    if (*(char *)(param_1 + 0x19) == '\x01') {
      *(undefined1 *)(param_1 + 0x19) = 0x10;
      FUN_60094d24(param_1,0x1d0e,0);
    }
    else if (local_c != (undefined2 *)0x0) {
      *(undefined4 *)(param_1 + 0x14) = 0;
      iVar2 = FUN_60094d24(param_1,*local_c,local_c);
      if (iVar2 != 0) {
        FUN_600aa648(&local_c);
      }
    }
  }
  return;
}


