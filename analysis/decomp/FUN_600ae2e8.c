// 600ae2e8  FUN_600ae2e8  size=500 bytes
// --- callers ---
//   600ae670 FUN_600ae670
// --- callees ---
//   600af9a0 FUN_600af9a0


undefined1 FUN_600ae2e8(int *param_1,int param_2,ushort *param_3,ushort param_4,ushort param_5)

{
  undefined2 uVar1;
  undefined1 *puVar2;
  int iVar3;
  byte bStack_25;
  undefined2 local_24;
  undefined4 *local_20;
  ushort local_1a;
  undefined1 *local_18;
  undefined1 local_11;
  
  local_11 = 10;
  local_1a = *param_3;
  local_24 = *DAT_600ae4dc;
  if ((*param_1 == 0) || (*(int *)*param_1 == 0)) {
    return 10;
  }
  local_20 = *(undefined4 **)*param_1;
  local_18 = (undefined1 *)((uint)*(ushort *)(param_2 + 2) + param_2 + 0x15);
  do {
    if ((local_20 == (undefined4 *)0x0) || (param_5 < *(ushort *)(local_20 + 3))) goto LAB_600ae4ca;
    if (param_4 <= *(ushort *)(local_20 + 3)) {
      if (*(short *)(param_2 + 4) == 0) {
        if (*(char *)(local_20 + 2) == '\0') {
          uVar1 = 1;
        }
        else {
          uVar1 = 2;
        }
        *(undefined2 *)(param_2 + 4) = uVar1;
      }
      if (local_1a < (&bStack_25)[*(ushort *)(param_2 + 4)]) {
        local_11 = 0x80;
LAB_600ae4ca:
        *param_3 = local_1a;
        return local_11;
      }
      if ((*(short *)(param_2 + 4) == 1) && (*(char *)(local_20 + 2) == '\0')) {
        *local_18 = (char)*(undefined2 *)(local_20 + 3);
        local_18[1] = (char)((ushort)*(undefined2 *)(local_20 + 3) >> 8);
        puVar2 = local_18 + 3;
        local_18[2] = (char)*(undefined2 *)((int)local_20 + 0xe);
        local_18 = local_18 + 4;
        *puVar2 = (char)((ushort)*(undefined2 *)((int)local_20 + 0xe) >> 8);
      }
      else if ((*(short *)(param_2 + 4) == 2) && (*(char *)(local_20 + 2) == '\x01')) {
        puVar2 = local_18 + 1;
        *local_18 = (char)*(undefined2 *)(local_20 + 3);
        local_18 = local_18 + 2;
        *puVar2 = (char)((ushort)*(undefined2 *)(local_20 + 3) >> 8);
        for (iVar3 = 0; puVar2 = local_18, iVar3 < 0x10; iVar3 = iVar3 + 1) {
          local_18 = local_18 + 1;
          *puVar2 = *(undefined1 *)((int)local_20 + iVar3 + 0xe);
        }
      }
      else {
        if ((*(short *)(param_2 + 4) != 2) || (*(char *)(local_20 + 2) != '\x02')) {
          local_11 = 0x80;
          goto LAB_600ae4ca;
        }
        puVar2 = local_18 + 1;
        *local_18 = (char)*(undefined2 *)(local_20 + 3);
        local_18 = local_18 + 2;
        *puVar2 = (char)((ushort)*(undefined2 *)(local_20 + 3) >> 8);
        FUN_600af9a0(local_18,local_20[4]);
        local_18 = local_18 + 0x10;
      }
      *(ushort *)(param_2 + 2) =
           (ushort)(&bStack_25)[*(ushort *)(param_2 + 4)] + *(short *)(param_2 + 2);
      local_1a = local_1a - (&bStack_25)[*(ushort *)(param_2 + 4)];
      local_11 = 0;
    }
    local_20 = (undefined4 *)*local_20;
  } while( true );
}


