// 600d4b78  FUN_600d4b78  size=194 bytes
// --- callers ---
//   600d6c76 FUN_600d6c76
// --- callees ---
//   600600c4 pwm__600600c4
//   600cf3de FUN_600cf3de
//   6006012c pwm__6006012c
//   60052aa8 FUN_60052aa8
//   6013cef0 thunk_EXT_FUN_0000887a
//   6013d3d8 thunk_EXT_FUN_0000b4c2
//   600600f8 pwm__600600f8


undefined4 FUN_600d4b78(char *param_1,uint param_2,int param_3)

{
  ushort uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  char *local_28;
  undefined1 local_24 [4];
  undefined2 local_20 [4];
  
  if (*param_1 == '\0') {
    uVar5 = 9;
  }
  else if ((param_2 < 0x65) && (-1 < param_3)) {
    local_28 = param_1 + 0x68;
    thunk_EXT_FUN_0000b4c2();
    if (param_1[10] != '\0') {
      local_24[2] = 0;
      local_24[0] = 1;
      local_20[0] = 0;
      local_24[1] = (char)param_2;
    }
    uVar6 = (uint)(param_1[10] != '\0');
    uVar7 = uVar6;
    if (param_1[0x38] != '\0') {
      iVar4 = uVar6 * 6;
      uVar7 = uVar6 + 1;
      local_24[iVar4] = 0;
      local_24[iVar4 + 1] = (char)param_2;
      local_24[iVar4 + 2] = 0;
      local_20[uVar6 * 3] = 0;
    }
    uVar5 = pwm__6006012c(*(undefined4 *)(param_1 + 4));
    uVar2 = pwm__600600c4(param_1[8]);
    uVar3 = FUN_60052aa8(3);
    FUN_600cf3de(uVar5,uVar2,local_24,uVar7,3,param_3,uVar3);
    iVar4 = pwm__6006012c(*(undefined4 *)(param_1 + 4));
    uVar1 = pwm__600600f8(param_1[8]);
    *(ushort *)(iVar4 + 0x188) = uVar1 & 0xf | *(ushort *)(iVar4 + 0x188);
    param_1[1] = '\x01';
    uVar5 = 0;
    thunk_EXT_FUN_0000887a(&local_28);
  }
  else {
    uVar5 = 3;
  }
  return uVar5;
}


