// 600bdc24  FUN_600bdc24  size=368 bytes
// --- callers ---
//   600bd848 FUN_600bd848
// --- callees ---


undefined4 FUN_600bdc24(int param_1,short param_2)

{
  short sVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *local_18;
  undefined1 *local_14;
  int *local_10;
  ushort local_c;
  ushort local_a;
  
  local_10 = DAT_600bdd94;
  local_a = 0;
  do {
    if (*(ushort *)(DAT_600bdd98 + 0x102) <= local_a) {
      return 0;
    }
    if (param_1 == *local_10) {
      piVar2 = local_10;
      for (local_a = 0; local_18 = piVar2 + 3, local_a < *(ushort *)(local_10 + 2);
          local_a = local_a + 1) {
        if (param_2 == (short)piVar2[5]) {
          local_14 = (undefined1 *)piVar2[4];
          iVar3 = *local_18;
          if (iVar3 != 0) {
            for (local_c = 0; local_c < *(ushort *)(local_10 + 2); local_c = local_c + 1) {
              if (local_14 < (undefined1 *)local_10[(uint)local_c * 3 + 4]) {
                local_10[(uint)local_c * 3 + 4] = local_10[(uint)local_c * 3 + 4] - iVar3;
              }
            }
          }
          *(short *)(local_10 + 2) = (short)local_10[2] + -1;
          for (local_c = local_a; local_c < *(ushort *)(local_10 + 2); local_c = local_c + 1) {
            *local_18 = local_18[3];
            local_18[1] = local_18[4];
            local_18[2] = local_18[5];
            local_18 = local_18 + 3;
          }
          if (iVar3 != 0) {
            iVar4 = local_10[1];
            sVar1 = (short)local_14;
            for (local_c = 0;
                local_c < (ushort)((short)iVar4 -
                                  (((short)iVar3 + sVar1) - ((short)local_10 + 0x6c)));
                local_c = local_c + 1) {
              *local_14 = local_14[iVar3];
              local_14 = local_14 + 1;
            }
            local_10[1] = local_10[1] - iVar3;
          }
          return 1;
        }
        piVar2 = local_18;
      }
    }
    local_a = local_a + 1;
    local_10 = local_10 + 0x73;
  } while( true );
}


