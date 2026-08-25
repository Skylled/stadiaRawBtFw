// 600f39fc  FUN_600f39fc  size=178 bytes
// --- callers ---
//   600abdac FUN_600abdac
//   600ee8f2 FUN_600ee8f2
// --- callees ---
//   600afd84 FUN_600afd84
//   600af7c8 FUN_600af7c8
//   600f6d9c FUN_600f6d9c
//   600afd28 FUN_600afd28
//   600afdf8 FUN_600afdf8


undefined1 FUN_600f39fc(undefined2 param_1,byte param_2,short *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined1 local_11;
  
  local_11 = 0;
  iVar1 = FUN_600af7c8((char)((ushort)param_1 >> 8));
  iVar2 = FUN_600afd28((char)param_1);
  if ((((iVar1 == 0) || (iVar2 == 0)) || (param_3 == (short *)0x0)) || (5 < param_2)) {
    local_11 = 0x87;
  }
  else {
    iVar1 = FUN_600afd84(param_1);
    if (iVar1 == 0) {
      iVar1 = FUN_600afdf8(param_1);
      if (iVar1 == 0) {
        local_11 = 0x80;
      }
      else if (((param_3[10] == 0) || (param_3[0xb] == 0)) || ((param_2 == 2 && (*param_3 == 0)))) {
        FUN_600f6d9c(iVar1);
        local_11 = 0x87;
      }
      else {
        *(undefined1 *)(iVar1 + 0x31) = 1;
        *(byte *)(iVar1 + 0x32) = param_2;
        *(short *)(iVar1 + 0x28) = param_3[10];
        *(short *)(iVar1 + 0x2a) = param_3[0xb];
        uVar3 = *(undefined4 *)(param_3 + 2);
        uVar4 = *(undefined4 *)(param_3 + 4);
        uVar5 = *(undefined4 *)(param_3 + 6);
        *(undefined4 *)(iVar1 + 0x10) = *(undefined4 *)param_3;
        *(undefined4 *)(iVar1 + 0x14) = uVar3;
        *(undefined4 *)(iVar1 + 0x18) = uVar4;
        *(undefined4 *)(iVar1 + 0x1c) = uVar5;
        *(undefined4 *)(iVar1 + 0x20) = *(undefined4 *)(param_3 + 8);
        FUN_600ac524(iVar1);
      }
    }
    else {
      local_11 = 0x84;
    }
  }
  return local_11;
}


