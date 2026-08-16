// 600aee8c  FUN_600aee8c  size=302 bytes
// --- callers ---
//   600f6516 FUN_600f6516
// --- callees ---
//   600aeb14 FUN_600aeb14
//   600f6be6 FUN_600f6be6
//   600aed40 FUN_600aed40


void FUN_600aee8c(undefined4 param_1,byte param_2,short param_3,byte *param_4)

{
  ushort uVar1;
  undefined4 *local_18;
  char local_11;
  undefined4 *local_10;
  byte local_9;
  
  local_10 = DAT_600aefbc;
  local_11 = '\x01';
  uVar1 = (ushort)param_4[1] * 0x100 + (ushort)*param_4;
  if (uVar1 != 0) {
    for (local_9 = 0; local_9 < 10; local_9 = local_9 + 1) {
      if (((*(char *)((int)local_10 + 0x25) != '\0') && (*(ushort *)(local_10 + 8) <= uVar1)) &&
         (uVar1 <= *(ushort *)((int)local_10 + 0x22))) {
        local_18 = *(undefined4 **)*local_10;
        goto LAB_600aef6e;
      }
      local_10 = local_10 + 10;
    }
  }
LAB_600aef8e:
  if (((local_11 != '\0') && (param_2 != 0x52)) && (param_2 != 0xd2)) {
    FUN_600f6be6(param_1,local_11,param_2,uVar1,0);
  }
  return;
LAB_600aef6e:
  if (local_18 == (undefined4 *)0x0) goto LAB_600aef8e;
  if (uVar1 == *(ushort *)(local_18 + 3)) {
    if (param_2 == 0x12) {
LAB_600aef46:
      FUN_600aeb14(param_1,local_9,uVar1,param_2,param_3 + -2,param_4 + 2);
    }
    else if (param_2 < 0x13) {
      if ((param_2 == 10) || (param_2 == 0xc)) {
        FUN_600aed40(param_1,local_10,param_2,uVar1,param_3 + -2,param_4 + 2);
      }
    }
    else if (((param_2 == 0x52) || (param_2 == 0xd2)) || (param_2 == 0x16)) goto LAB_600aef46;
    local_11 = '\0';
    goto LAB_600aef8e;
  }
  local_18 = (undefined4 *)*local_18;
  goto LAB_600aef6e;
}


