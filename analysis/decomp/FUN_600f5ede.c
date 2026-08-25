// 600f5ede  FUN_600f5ede  size=214 bytes
// --- callers ---
// --- callees ---
//   600f20ac FUN_600f20ac
//   600f79a8 FUN_600f79a8
//   600ada6c FUN_600ada6c
//   600ad8fc FUN_600ad8fc
//   600f610e FUN_600f610e
//   600f60ee FUN_600f60ee
//   600afea0 FUN_600afea0
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600af718 FUN_600af718


void FUN_600f5ede(undefined2 param_1,undefined2 *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_600afea0(param_1);
  if (iVar1 != 0) {
    if (((*(char *)(param_2 + 1) == '\0') || ((ushort)param_2[2] < 0x30)) ||
       (0x29f < (ushort)param_2[2])) {
      *(undefined2 *)(iVar1 + 0x1a) = 0x2a0;
    }
    else {
      *(undefined2 *)(iVar1 + 0x1a) = param_2[2];
    }
    thunk_EXT_FUN_0000b5ba(param_2,0,0x48);
    *param_2 = 0;
    FUN_600f79a8(param_1,param_2);
    if ((*(byte *)(iVar1 + 0x1d) & 1) == 0) {
      *(byte *)(iVar1 + 0x1d) = *(byte *)(iVar1 + 0x1d) | 1;
      if ((*(byte *)(iVar1 + 0x1d) & 2) != 0) {
        FUN_600f610e(iVar1,4);
        iVar2 = FUN_600af718(iVar1 + 0xd);
        if (iVar2 == 0) {
          iVar2 = FUN_600f20ac(iVar1 + 0xd);
          if (iVar2 != 0) {
            FUN_600ada6c(iVar1 + 0xd);
          }
        }
        else {
          FUN_600f60ee(iVar2);
        }
        FUN_600ad8fc(iVar1);
      }
    }
  }
  return;
}


