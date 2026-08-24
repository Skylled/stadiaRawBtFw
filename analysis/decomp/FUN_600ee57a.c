// 600ee57a  FUN_600ee57a  size=254 bytes
// --- callers ---
//   600ee9f6 FUN_600ee9f6
//   60094c5c FUN_60094c5c
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572
//   60094754 FUN_60094754


undefined1
FUN_600ee57a(int param_1,undefined2 param_2,undefined2 param_3,undefined4 param_4,undefined1 param_5
            ,undefined1 param_6)

{
  int iVar1;
  byte bVar2;
  undefined1 uVar3;
  
  if ((*(ushort *)(param_1 + 0x24) < 0x30) && (iVar1 = FUN_60094754(param_1), iVar1 == 0)) {
    uVar3 = 0x80;
  }
  else {
    iVar1 = *(int *)(param_1 + 0x20);
    *(undefined2 *)(iVar1 + 0x24) = param_2;
    *(undefined2 *)(iVar1 + 0x26) = param_3;
    *(undefined1 *)(iVar1 + 0x18) = param_5;
    thunk_EXT_FUN_0000b572(iVar1,param_4,0x14);
    *(undefined1 *)(iVar1 + 0x14) = param_6;
    *(undefined4 *)(iVar1 + 0x28) = 0;
    if (*(int *)(param_1 + 0x10) != 0) {
      *(int *)(*(int *)(param_1 + 0x10) + 0x28) = iVar1;
    }
    *(int *)(param_1 + 0x10) = iVar1;
    *(undefined4 *)(*(int *)(param_1 + 0x10) + 0x2c) = 0;
    if (*(int *)(param_1 + 0xc) == 0) {
      *(int *)(param_1 + 0xc) = iVar1;
    }
    *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 0x30;
    *(short *)(param_1 + 0x24) = *(short *)(param_1 + 0x24) + -0x30;
    if ((*(uint *)(param_1 + 0x20) & 3) == 0) {
      bVar2 = 0;
    }
    else {
      bVar2 = 4 - ((byte)*(uint *)(param_1 + 0x20) & 3);
    }
    *(uint *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + (uint)bVar2;
    *(ushort *)(param_1 + 0x24) = *(short *)(param_1 + 0x24) - (ushort)bVar2;
    uVar3 = 0;
  }
  return uVar3;
}


