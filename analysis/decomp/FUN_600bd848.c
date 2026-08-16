// 600bd848  FUN_600bd848  size=516 bytes
// --- callers ---
//   600bd150 FUN_600bd150
//   600bdb14 FUN_600bdb14
//   600bdaaa FUN_600bdaaa
//   600bd65c FUN_600bd65c
//   600bdb7c FUN_600bdb7c
//   600f6c4c FUN_600f6c4c
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600bdc24 FUN_600bdc24


undefined4 FUN_600bd848(int param_1,ushort param_2,char param_3,int param_4,int param_5)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_24;
  int *local_18;
  int *local_14;
  ushort local_e;
  ushort local_c;
  ushort local_a;
  
  local_14 = DAT_600bda4c;
  local_e = 0;
  while( true ) {
    if (*(ushort *)(DAT_600bda50 + 0x102) <= local_e) {
      return 0;
    }
    if (param_1 == *local_14) break;
    local_e = local_e + 1;
    local_14 = local_14 + 0x73;
  }
  local_a = 0;
  piVar1 = local_14;
  do {
    local_18 = piVar1 + 3;
    if (*(ushort *)(local_14 + 2) <= local_a) {
LAB_600bd8b6:
      if ((short)local_14[2] == 8) {
        return 0;
      }
      if (local_a == *(ushort *)(local_14 + 2)) {
        local_18 = local_14 + (uint)*(ushort *)(local_14 + 2) * 3 + 3;
      }
      else {
        for (local_c = *(ushort *)(local_14 + 2); local_a < local_c; local_c = local_c - 1) {
          iVar3 = local_c - 1;
          iVar2 = local_14[iVar3 * 3 + 4];
          iVar4 = local_14[iVar3 * 3 + 5];
          local_14[(uint)local_c * 3 + 3] = local_14[iVar3 * 3 + 3];
          local_14[(uint)local_c * 3 + 4] = iVar2;
          local_14[(uint)local_c * 3 + 5] = iVar4;
        }
      }
      *(ushort *)(local_18 + 2) = param_2;
      *(char *)((int)local_18 + 10) = param_3;
      *local_18 = param_4;
      local_24 = param_4;
      if (0x15d < (uint)(param_4 + local_14[1])) {
        if (param_3 == '\x04') {
          local_24 = 0x15e - local_14[1];
          *(undefined1 *)((0x15e - local_14[1]) + param_5) = 0;
          *(undefined1 *)((0x15f - local_14[1]) + param_5) = 0;
        }
        else {
          local_24 = 0;
        }
      }
      if ((local_24 == 0) || (param_5 == 0)) {
        if (((local_24 == 0) && (*local_18 != 0)) || (param_5 == 0)) {
          *local_18 = 0;
          *(undefined1 *)((int)local_18 + 10) = 0;
          *(ushort *)(local_18 + 2) = (ushort)*(byte *)((int)local_18 + 10);
          return 0;
        }
      }
      else {
        *local_18 = local_24;
        thunk_EXT_FUN_0000b572((int)local_14 + local_14[1] + 0x6c,param_5,local_24);
        local_18[1] = (int)local_14 + local_14[1] + 0x6c;
        local_14[1] = local_14[1] + local_24;
      }
      *(short *)(local_14 + 2) = (short)local_14[2] + 1;
      if ((param_1 == *(int *)(DAT_600bda50 + 0xfc)) && (param_2 == 0x8001)) {
        *(undefined1 *)(DAT_600bda50 + 0x100) = 1;
      }
      return 1;
    }
    if (param_2 == *(ushort *)(piVar1 + 5)) {
      FUN_600bdc24(param_1,param_2);
      goto LAB_600bd8b6;
    }
    if (param_2 < *(ushort *)(piVar1 + 5)) goto LAB_600bd8b6;
    local_a = local_a + 1;
    piVar1 = local_18;
  } while( true );
}


