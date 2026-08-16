// 600b0e2c  FUN_600b0e2c  size=406 bytes
// --- callers ---
//   600b59ec FUN_600b59ec
//   6009c444 FUN_6009c444
// --- callees ---
//   6006dbac FUN_6006dbac
//   600a9234 FUN_600a9234


undefined4
FUN_600b0e2c(undefined2 param_1,undefined2 param_2,undefined1 param_3,undefined1 param_4,int param_5
            ,undefined1 param_6,undefined2 param_7,undefined2 param_8,undefined2 param_9,
            undefined2 param_10,undefined2 param_11,undefined2 param_12)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 *local_14;
  
  iVar1 = FUN_6006dbac(0x24,DAT_600b0fc4,0x151);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    *(undefined2 *)(iVar1 + 2) = 0x1c;
    *(undefined2 *)(iVar1 + 4) = 0;
    *(undefined1 *)(iVar1 + 8) = 0xd;
    *(undefined1 *)(iVar1 + 9) = 0x20;
    *(undefined1 *)(iVar1 + 10) = 0x19;
    *(char *)(iVar1 + 0xb) = (char)param_1;
    *(char *)(iVar1 + 0xc) = (char)((ushort)param_1 >> 8);
    *(char *)(iVar1 + 0xd) = (char)param_2;
    *(char *)(iVar1 + 0xe) = (char)((ushort)param_2 >> 8);
    *(undefined1 *)(iVar1 + 0xf) = param_3;
    *(undefined1 *)(iVar1 + 0x10) = param_4;
    local_14 = (undefined1 *)(iVar1 + 0x11);
    for (iVar3 = 0; iVar3 < 6; iVar3 = iVar3 + 1) {
      *local_14 = *(undefined1 *)((5 - iVar3) + param_5);
      local_14 = local_14 + 1;
    }
    *local_14 = param_6;
    local_14[1] = (char)param_7;
    local_14[2] = (char)((ushort)param_7 >> 8);
    local_14[3] = (char)param_8;
    local_14[4] = (char)((ushort)param_8 >> 8);
    local_14[5] = (char)param_9;
    local_14[6] = (char)((ushort)param_9 >> 8);
    local_14[7] = (char)param_10;
    local_14[8] = (char)((ushort)param_10 >> 8);
    local_14[9] = (char)param_11;
    local_14[10] = (char)((ushort)param_11 >> 8);
    local_14[0xb] = (char)param_12;
    local_14[0xc] = (char)((ushort)param_12 >> 8);
    FUN_600a9234(0,iVar1);
    uVar2 = 1;
  }
  return uVar2;
}


