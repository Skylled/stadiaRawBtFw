// 600ae0dc  FUN_600ae0dc  size=516 bytes
// --- callers ---
//   600ae4e0 FUN_600ae4e0
// --- callees ---
//   600f4ed6 FUN_600f4ed6
//   600f69f0 FUN_600f69f0
//   600f68f0 FUN_600f68f0


undefined1
FUN_600ae0dc(int param_1,int param_2,char param_3,ushort param_4,ushort param_5,undefined4 param_6,
            undefined4 param_7,undefined4 param_8,undefined4 param_9,undefined4 param_10,
            undefined4 param_11)

{
  char *pcVar1;
  int iVar2;
  char *local_28;
  undefined4 *local_24;
  undefined4 *local_20;
  int *local_1c;
  undefined4 *local_18;
  byte local_12;
  undefined1 local_11;
  
  local_11 = 10;
  local_12 = 4;
  local_1c = DAT_600ae2e0;
  local_28 = (char *)(param_1 + 0x15);
  for (local_18 = (undefined4 *)DAT_600ae2e0[1]; local_18 != (undefined4 *)0x0;
      local_18 = (undefined4 *)*local_18) {
    iVar2 = (uint)*(byte *)((int)local_18 + 10) * 0x28 + DAT_600ae2e4;
    local_20 = (undefined4 *)(iVar2 + 0xa84);
    if ((((*(char *)(iVar2 + 0xaa9) != '\0') && (param_4 <= *(ushort *)(iVar2 + 0xaa4))) &&
        (*(ushort *)(iVar2 + 0xaa4) <= param_5)) && (*(short *)(iVar2 + 0xaa2) == 0x2800)) {
      local_24 = (undefined4 *)FUN_600f4ed6(*local_20);
      if (local_24 != (undefined4 *)0x0) {
        if (param_3 == '\x10') {
          local_12 = (char)*(undefined2 *)local_24 + 4;
        }
        pcVar1 = local_28;
        if (*(short *)(param_1 + 4) == 0) {
          *local_28 = param_3 + '\x01';
          *(short *)(param_1 + 2) = *(short *)(param_1 + 2) + 1;
          *(ushort *)(param_1 + 4) = (ushort)local_12;
          pcVar1 = local_28 + 1;
          if (param_3 == '\x10') {
            local_28[1] = (char)*(undefined2 *)(param_1 + 4);
            *(short *)(param_1 + 2) = *(short *)(param_1 + 2) + 1;
            pcVar1 = local_28 + 2;
          }
        }
        local_28 = pcVar1;
        if (((uint)*(ushort *)(param_2 + 0x1a) <
             (uint)*(ushort *)(param_1 + 4) + (uint)*(ushort *)(param_1 + 2)) ||
           ((ushort)local_12 != *(ushort *)(param_1 + 4))) break;
        if (param_3 == '\x06') {
          iVar2 = FUN_600f68f0(param_7,param_8,param_9,param_10,param_11,*local_24,local_24[1],
                               local_24[2],local_24[3],local_24[4]);
          if (iVar2 == 0) goto LAB_600ae2c0;
        }
        *local_28 = (char)*(undefined2 *)(local_20 + 8);
        local_28[1] = (char)((ushort)*(undefined2 *)(local_20 + 8) >> 8);
        if ((local_18 == (undefined4 *)*local_1c) && (*local_1c == local_1c[2])) {
          local_28[2] = -1;
          local_28[3] = -1;
        }
        else {
          local_28[2] = (char)*(undefined2 *)((int)local_20 + 0x22);
          local_28[3] = (char)((ushort)*(undefined2 *)((int)local_20 + 0x22) >> 8);
        }
        local_28 = local_28 + 4;
        if (param_3 == '\x10') {
          FUN_600f69f0(&local_28,*local_24,local_24[1],local_24[2],local_24[3],local_24[4]);
        }
        local_11 = 0;
        *(short *)(param_1 + 2) = *(short *)(param_1 + 4) + *(short *)(param_1 + 2);
      }
    }
LAB_600ae2c0:
  }
  *(undefined2 *)(param_1 + 4) = 0xd;
  return local_11;
}


