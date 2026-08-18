// 600cea74  FUN_600cea74  size=132 bytes
// --- callers ---
//   60052ccc FUN_60052ccc
// --- callees ---


undefined4
FUN_600cea74(undefined4 param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
            uint param_6,undefined4 *param_7)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  if ((param_6 < 0x10) || ((param_6 & 0xf) != 0)) {
    return 4;
  }
  *(uint *)(param_3 + 0x14) = param_6;
  *(undefined4 *)(param_3 + 0xc) = param_4;
  *(undefined4 *)(param_3 + 0x10) = param_5;
  uVar2 = (uint)*(byte *)(param_2 + 4);
  *(undefined4 *)(param_3 + 4) = 0x222;
  *(undefined4 *)(param_3 + 8) = 0x10;
  if (uVar2 == 4) {
    *(undefined4 **)(param_3 + 0x18) = param_7;
    *(undefined4 *)(param_3 + 4) = 0x622;
    uVar2 = 0xff10;
  }
  else if (uVar2 == 5) {
    *(undefined4 **)(param_3 + 0x18) = param_7;
    *(undefined4 *)(param_3 + 4) = 0x622;
    uVar2 = 0xfe10;
  }
  else {
    if (uVar2 == 6) {
      puVar3 = (undefined4 *)(param_2 + 0x18);
      puVar4 = param_7;
      do {
        puVar5 = puVar4 + 1;
        *puVar3 = *puVar4;
        puVar3 = puVar3 + 1;
        puVar4 = puVar5;
      } while (puVar5 != param_7 + 4);
      *(int *)(param_3 + 0x18) = param_2 + 8;
      *(uint *)(param_3 + 4) = *(uint *)(param_3 + 4) | 0x800;
      goto LAB_600ceae2;
    }
    *(undefined4 **)(param_3 + 0x18) = param_7;
    uVar2 = uVar2 << 8 | 0x10;
  }
  *(uint *)(param_3 + 8) = uVar2;
LAB_600ceae2:
                    /* WARNING: Could not recover jumptable at 0x6013d0f8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*DAT_6013d0fc)();
  return uVar1;
}


