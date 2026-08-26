// 60101bcc  FUN_60101bcc  size=48 bytes
// --- callers ---
//   600cbebc logger__600cbebc
//   6005a1b0 device_info__6005a1b0
// --- callees ---
//   600cdd6c FUN_600cdd6c
//   60101ba2 FUN_60101ba2


undefined1 FUN_60101bcc(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_8 = param_3;
  uStack_4 = param_4;
  uVar1 = FUN_600cdd6c(param_1[2] + *param_1,param_1[1] - param_1[2],param_2,&uStack_8,param_1,
                       &uStack_8);
  FUN_60101ba2(param_1,uVar1);
  return *(undefined1 *)((int)param_1 + 0xd);
}


