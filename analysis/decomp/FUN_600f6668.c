// 600f6668  FUN_600f6668  size=194 bytes
// --- callers ---
//   600ab424 FUN_600ab424
// --- callees ---
//   600f662c FUN_600f662c


undefined4 FUN_600f6668(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *local_c;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0;
  }
  else {
    if (*(int *)(param_1 + 4) == 0) {
      *(undefined4 **)(param_1 + 8) = param_2;
      *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_1 + 8);
      param_2[1] = 0;
      *param_2 = param_2[1];
    }
    else {
      for (local_c = *(undefined4 **)(param_1 + 4); local_c != (undefined4 *)0x0;
          local_c = (undefined4 *)*local_c) {
        if (*(ushort *)(param_2 + 2) < *(ushort *)(local_c + 2)) {
          if (local_c[1] == 0) {
            *(undefined4 **)(param_1 + 4) = param_2;
          }
          else {
            *(undefined4 **)local_c[1] = param_2;
          }
          param_2[1] = local_c[1];
          *param_2 = local_c;
          local_c[1] = param_2;
          goto LAB_600f670e;
        }
      }
      **(undefined4 **)(param_1 + 8) = param_2;
      param_2[1] = *(undefined4 *)(param_1 + 8);
      *param_2 = 0;
      *(undefined4 **)(param_1 + 8) = param_2;
    }
LAB_600f670e:
    *(short *)(param_1 + 0xc) = *(short *)(param_1 + 0xc) + 1;
    FUN_600f662c(param_1);
    uVar1 = 1;
  }
  return uVar1;
}


