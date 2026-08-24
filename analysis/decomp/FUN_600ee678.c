// 600ee678  FUN_600ee678  size=434 bytes
// --- callers ---
//   600eead0 FUN_600eead0
//   60094a3c FUN_60094a3c
//   60094c5c FUN_60094c5c
//   600eeb42 FUN_600eeb42
// --- callees ---
//   600ee522 FUN_600ee522
//   60094754 FUN_60094754
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600ee4c8 FUN_600ee4c8


undefined1
FUN_600ee678(int param_1,undefined2 param_2,short *param_3,undefined1 param_4,char param_5)

{
  undefined1 uVar1;
  int iVar2;
  byte bVar3;
  ushort uVar4;
  undefined4 *puVar5;
  undefined1 *puVar6;
  
  uVar4 = *param_3 + 0x10;
  if (*(int *)(param_1 + 0x10) == 0) {
    uVar1 = 0x82;
  }
  else if ((*(ushort *)(param_1 + 0x24) < uVar4) && (iVar2 = FUN_60094754(param_1), iVar2 == 0)) {
    uVar1 = 0x80;
  }
  else {
    puVar5 = *(undefined4 **)(param_1 + 0x20);
    *(undefined2 *)((int)puVar5 + 10) = param_2;
    *(char *)((int)puVar5 + 0xe) = param_5;
    *(undefined1 *)((int)puVar5 + 0xd) = param_4;
    *(short *)(puVar5 + 2) = *param_3;
    *puVar5 = puVar5 + 4;
    puVar5[1] = 0;
    puVar6 = (undefined1 *)*puVar5;
    if (*param_3 == 2) {
      *puVar6 = (char)param_3[2];
      puVar6[1] = (char)((ushort)param_3[2] >> 8);
    }
    else if (*param_3 == 0x10) {
      thunk_EXT_FUN_0000b572(puVar6,param_3 + 2,0x10);
    }
    if (param_5 == '\x01') {
      uVar1 = FUN_600ee4c8(*(undefined4 *)(param_1 + 0x10),param_3);
      *(undefined1 *)(puVar5 + 3) = uVar1;
      *(undefined4 **)(*(int *)(param_1 + 0x10) + 0x2c) = puVar5;
    }
    else if (param_5 == '\x02') {
      uVar1 = FUN_600ee522(*(undefined4 *)(*(int *)(param_1 + 0x10) + 0x2c),param_3);
      *(undefined1 *)(puVar5 + 3) = uVar1;
    }
    else {
      *(undefined1 *)(puVar5 + 3) = 0;
    }
    *(uint *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + (uint)uVar4;
    *(ushort *)(param_1 + 0x24) = *(short *)(param_1 + 0x24) - uVar4;
    if ((*(uint *)(param_1 + 0x20) & 3) == 0) {
      bVar3 = 0;
    }
    else {
      bVar3 = 4 - ((byte)*(uint *)(param_1 + 0x20) & 3);
    }
    *(uint *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + (uint)bVar3;
    *(ushort *)(param_1 + 0x24) = *(short *)(param_1 + 0x24) - (ushort)bVar3;
    if (*(int *)(*(int *)(param_1 + 0x10) + 0x1c) == 0) {
      *(undefined4 **)(*(int *)(param_1 + 0x10) + 0x1c) = puVar5;
    }
    if (*(int *)(*(int *)(param_1 + 0x10) + 0x20) != 0) {
      *(undefined4 **)(*(int *)(*(int *)(param_1 + 0x10) + 0x20) + 4) = puVar5;
    }
    *(undefined4 **)(*(int *)(param_1 + 0x10) + 0x20) = puVar5;
    uVar1 = 0;
  }
  return uVar1;
}


